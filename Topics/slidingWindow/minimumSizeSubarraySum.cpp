// ===================================================== sliding window ==========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-size-subarray-sum/description/

/* Explanation: Sliding Window => 4th pattern concept of minimum sized window
   subarray whose sum >= target => we want the subarray of min length 
   so we can expand the window for all r and then shrink the window keeping the window valid 
   and in this way we get the minimum sized window 
   This works as there are no negative integers so we can expand and shrink depending on the curr_sum value 
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int curr_sum = 0, l = 0, minLen = 1e9;

        for(int r = 0; r < n; r++) {
            // expand the window on right 
            curr_sum += nums[r];

            // shrink the window if it is valid and keep the window valid always 
            while(curr_sum >= target) {
                if(curr_sum - nums[l] < target) break;
                
                curr_sum -= nums[l];
                l++;
            }

            if(curr_sum >= target) minLen = min(minLen, r-l+1);
        }

        // if we did not find a subarray with whose sum >= target
        return (minLen == 1e9) ? 0 : minLen;
    }
};