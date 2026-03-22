#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
// VERY IMPORTANT QUESTION

/*
    ALGORITHM: 
    We use array dp to get the length of lis => also calculate the no of possible lis till i 
    dp[i] = length of the lis that ith element is part of  
    cnt[i] = denotes the number of ways we can form lis with ith element of the same length 
    so there will be two cases to calculate the cnt 

    when the jth element adds on to increase the length that is dp[j] > maxi 
    cnt[i] = cnt[j];      => same ways to reach from previous one to the next 
    but when dp[j] == maxi that is two different lis is possible of length maxi 
    then cnt[i] = cnt[i] + cnt[j] => add both of them that is current ways + newer case 
 
*/

// getting lis using dp and counting how many lis can be formed also using dp 

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    // dp[i] = length of the lis that ith element is part of 
    vector<int> dp(n, 1), cnt(n, 1);     
    // cnt[i] = denotes the number of ways we can form lis with ith element 

    for(int i = 0; i < n; i++) {
        // for the ith element find the lis
        int maxi = 0;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                // case 1: found the next bigger element in the lis
                if(dp[j] > maxi) {  
                    maxi = dp[j];
                    cnt[i] = cnt[j];     // cnt[i] = no of lis till jth 
                }
                // case 2: found anathor way to reach ith lis 
                else if(dp[j] == maxi) { 
                    cnt[i] += cnt[j];    // add j's ways to current ways
                }
            }
        }
        dp[i] = maxi + 1;
    }

    // now we get the max length in the dp[i]
    int maxLength = 1;
    for(int i = 0; i < n; i++) {
        maxLength = max(maxLength, dp[i]);
    }

    // now sum all the ways to for lis of maxLength i.e. sum of cnt[i] where dp[i] = maxLength 
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] == maxLength) 
            result += cnt[i];
    }

    return result;
}
