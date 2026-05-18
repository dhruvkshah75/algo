#include<bits/stdc++.h>
using namespace std; 

// VERY IMPORTANT dp question type 

// bottom Up approach => Tabulation
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    // dp[i] = max length of the subsequence that ith element is part of 
    vector<int> dp(n, 1);
    int result = 1;
    
    for(int i = 1; i < n; i++) {
        int maxi = 0;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) 
                maxi = max(maxi, dp[j]);
        }
        dp[i] = maxi + 1;
        result = max(result, dp[i]);
    }
    return result;
}  

// Top down approach => Memoization: Starting from a bigger question and comming down to smaller sub problems 
int lis(int i, vector<int> &nums, vector<int> &dp) {
    // the optimization case
    if(dp[i] != -1) 
        return dp[i];

    int maxi = 1;
    for(int j = 0; j < i; j++) {
        if(nums[i] > nums[j])
            maxi = max(maxi, lis(j, nums, dp) + 1);
    }

    return dp[i] = maxi;
}


int lenOfLIS(vector<int> &nums) {
    int n = nums.size();

    vector<int> dp(n, 1);

    int result = 0;
    for(int i = 0; i < n; i++) {
        result = max(result, lis(i, nums, dp));
    }

    return result;

}