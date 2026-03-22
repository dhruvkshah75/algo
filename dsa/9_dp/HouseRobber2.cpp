#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/house-robber-ii/description/

/*
    Note house 0 and N-1 are connect
    if house[0] is robbed then house[n-1] cannot be robbed => houses are in a circular arrangement
    In this we use the cleaner dp version where dp[i] = max amount robbed from 1..i
    i.e. dp[i] = max(dp[i-1], dp[i-1] + nums[i])
    Robber can rob the houses in 2 batches => houses [0: N-2] and houses [1:N-1]
    => so calculate the max Robbed in both the batches and the max of them will the final result 
*/


int rob(vector<int>& nums) {
    int n = nums.size();
    // Base cases for n = 1 and n = 2
    if(n == 1)
        return nums[0];
    if(n == 2)
        return max(nums[0], nums[1]);

    // CASE1: robbing house[0:N-2]
    vector<int> dp(n);  // dp[i] = max amount robbed till reaching this place
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n-1; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    int robM1 = dp[n-2];

    // CASE2: robbing house[1:N-1]=> overwrite the existing dp
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);

    for(int i = 3; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    int robM2 = dp[n-1];
    // return the best way to rob => houses [0:n-2] or [1:n-1]
    return max(robM1, robM2);
}
