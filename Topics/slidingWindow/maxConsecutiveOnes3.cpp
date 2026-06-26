// =============================================== Sliding Window ==============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/max-consecutive-ones-iii/description/

/* Explanation: Sliding window => longest increasing Subarray Pattern 
 * here we are allowed to change any 0 to 1 (allowed flips are at most k)
 * So we can use the concept of sliding window of variable size => we must define the rules for 
 * shrinking the window and expanding the window 
 *
 * So we can start by expanding the window if 1 comes (no issue in this)
 * and when 0 is encountered then we can use one flip to convert the 0 to 1 (if <= k)
 * and then anathor 0 is encountered and all k flips have been used 
 * then start shrinking the window until a zero arrives and restore one flip and then expand right side 
 *
 * Question is  => what to do when we cant move forward and cant shrink either ?
 * This wont ever happen if k >= 1 as we can always shrink to the size of sliding window becoming 1 
 *  
 * deal with the case of k = 0 => as base case and simply find the max number of consecutive 1s 
 */


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        // base case: if no flips are allowed 
        if(k == 0) {
            int i = 0, res = 0;

            while(i < n) {
                if(nums[i] == 0) {
                    i++; continue;
                }

                int j = i;
                while(j < n && nums[j] == 1) j++;
                res = max(res, j-i);
                i = j;
            }

            return res;
        }

        int flips = 0;

        // initialise the sliding window of size 1 with 1st element
        int l = 0, r = 0, maxLen = 1;
        if(nums[0] == 0) flips++;
        
        while(r+1 < n) {
            // expand the window to r+1 
            if(nums[r+1] == 1) 
                r++;
            else if(nums[r+1] == 0) {
    
                if(flips == k) {
                    // cant expand the window on the right => so shrink from left
                    while(nums[l] != 0) l++;
                    flips--;
                    l++;
                }
                
                // now expand on the right by flipping 0 to 1 
                flips++;
                r++;
            }
            
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};