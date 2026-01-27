#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-subarray/description/

/*
    Algorithm:
        We have two variables
        1. curr_sum = stores the sum at every time and resets to 0 when the cur_sum < 0 (becomes negative)
        2. max_sum = storing the max ans at every iteration 
        
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        int cur_sum = 0;
        for(int i=0; i<n; i++) {
            cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
            if(cur_sum < 0) cur_sum = 0;
        }
        return max_sum;
    }
};