// ============================================== sliding window ==================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

/* Explanation: sliding window (3rd pattern of counting number of subarrays)
   We can use map to count the number of distinct integers 
   Here to count the number of subarrays with k different integers can be broken down into 
   (no of subarrays with <= K different integers) - (no of subarrays with <= K-1 different integers)

   Why this above formula works as when we define the a valid window [l...r]
   which contains <= K distinct integers then any subarray of this window ending in r 
   would include all subarrays => [l..r], [l+1,..r], ... [r] => r-l+1 subarrays as all of them 
   will always <= K different integers
*/

class Solution {
private:
    int n;

    int func(vector<int> &nums, int k) {
        // returns no of subarrays with less than k different integers
        int l = 0, cnt = 0;
        unordered_map<int,int> mp;

        for(int r = 0; r < n; r++) {
            // expand the window to r
            mp[nums[r]]++;

            // shrink the window if not valid 
            while(mp.size() > k) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);

                l++;
            }

            // count number of subarrays ending in r in the window [l...r]
            cnt += (r-l+1);
        }

        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n = nums.size();

        // (no of subarrays <= K different integers) - (no of subarrays <= K-1 different integers)
        // = no of subarrays with K different integers
        return func(nums, k) - func(nums, k-1);
    }
};