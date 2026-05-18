#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/house-robber/description

/*
    Why max(dp[i-2], dp[i-3]) is correct:
    When robbing house i, the previous robbed house can be either:
        i-2 (skipped one house) → dp[i-2]
        i-3 (skipped two houses) → dp[i-3]
*/

// METHOD 1
int rob1(vector<int>& nums) {
    int n = nums.size(); 
    // base case when only one house is there 
    if(n == 1)
        return nums[0];
    // if there are 2 houses the robber robs the max one 
    if(n == 2)
        return max(nums[0], nums[1]);

    // we can use bottom up approach 
    vector<int> dp(n);
    // dp[i] = maximum money robbed from houses 0..i where house i is definitely robbed.
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = dp[0] + nums[2];

    for(int i = 3; i < n; i++) {
        // to rob the ith one we check if it is better to rob i-2 or i-3 th house 
        dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
    }

    // we return the max of last two cases as the either of last 2 houses is definetly robbed 
    return max(dp[n-1], dp[n-2]);
}

// METHOD 2 => the cleaner way to solve the question where the meaning of dp[i] changes 
int rob2(vector<int> &nums) {
    int n = nums.size(); 

    // here dp[i] means max value robbed till the ith house 
    // so we decide that does the robber rob the ith house or not 
    if(n == 1)
        return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++) {
        // we rob the ith house if dp[i-2] + nums[i] > dp[i]
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }

    return dp[n-1];
}


// =======================================================================================
//                      Important Space Optimised Code => HOUSE ROBBER 1
// =======================================================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) 
            return nums[0];
         
        // dp[i] = amount robbed till ith house 
        // dp0 = dp[i-2] and dp1 = dp[i-1]

        int dp0 = nums[0];
        int dp1 = max(dp0, nums[1]); 

        
        for(int i = 2; i < n; i++) {
            // robber has 2 choices => rob the ith house or not 
            int val = max(dp1, dp0 + nums[i]);

            dp0 = dp1;
            dp1 = val;
        }

        return dp1;
    }
};

// =========================================================================================================
//                          SPACE OPTIMISED SOLUTION FOR HOUSE ROBBER 2
// =========================================================================================================

class HouseRobber2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // dp[i] = max amount robbed till reaching this place 
        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);

        // dp1 = dp[i-1] and dp0 = dp[i-2]

        // CASE1: robbing house[1] to house[n-1]
        int dp0 = nums[0];
        int dp1 = max(dp0, nums[1]);

        // if house[0] is robbed then house[n-1] cannot be robbed 
        for(int i = 2; i < n-1; i++) {
            int best = max(dp1, dp0 + nums[i]);

            dp0 = dp1;
            dp1 = best;
        }
        int robM1 = dp1;

        // CASE2: robbing house[2] to house[n]=> overwrite the existing dp
        dp0 = nums[1];
        dp1 = max(dp0, nums[2]);

        for(int i = 3; i < n; i++) {
            int best = max(dp1, dp0 + nums[i]);

            dp0 = dp1;
            dp1 = best;
        }
        int robM2 = dp1;
        
        // return the best way to rob => houses [0:n-2] or [1:n-1]
        return max(robM1, robM2);
    }
};