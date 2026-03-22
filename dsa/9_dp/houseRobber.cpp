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
