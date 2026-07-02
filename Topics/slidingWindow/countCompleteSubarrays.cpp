// ===================================================== sliding window ======================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

/* Explanation: sliding window + counting of subarrays 
   question translates to number of subarrays with k distinct elements 
   which further can be solved => 
   (no of subarrays containing <= k distinct elements) - (no of subarrays containing <= k-1 elements) */

class Solution {
private:
    int n;

    int func(vector<int> &nums, int k) {
        // returns the cnt of subarrays with <= k distinct elements 
        int l = 0, cnt = 0;
        unordered_map<int,int> mp;

        for(int r = 0; r < n; r++) {
            mp[nums[r]]++;

            // shrink if the current window is invalid 
            while(mp.size() > k) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt += (r-l+1);
        }

        return cnt;
    }

public:
    int countCompleteSubarrays(vector<int> &nums) {
        n = nums.size();

        unordered_set<int> s(nums.begin(), nums.end());
        int distinct = s.size();

        // return (no of subarrays <= k distinct elements) - (no of subarrays <= k-1 distinct elements)
        return func(nums, distinct) - func(nums, distinct-1);
    }
};