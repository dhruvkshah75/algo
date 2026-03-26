#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/largest-divisible-subset/description/

// Time Complexity = O(N^2)
/*
    We store 2 values in the dp => length of the subset, and prevIndex => stores the previous index 
    to the sequence to which ith element is a part and in the end using the prevIndex stored make the 
    result vector 
*/

vector<int> largestDivisibleSubset(vector<int>& nums) {
    // this question is similar to lis 
    int n = nums.size();
    
    sort(nums.begin(), nums.end());

    vector<pair<int,int>> dp(n, {1, -1});
    // dp[i] = {len, prevIdx} store the length of the subset that ith element belongs to 
    int maxLen = 0;     

    // O(N^2) gives us the maxLen of the subset that we want and store the prevIndex of it 
    for(int i = 0; i < n; i++) {
        int maxi = 0, prevIdx = -1;  
        for(int j = 0; j < i; j++) {
            if(nums[i] % nums[j] == 0 && dp[j].first > maxi) {
                // if the number is part of subset and max is to be updated 
                maxi = dp[j].first;
                prevIdx = j;
            }     
        }
        dp[i] = {maxi + 1, prevIdx};
        maxLen = max(maxLen, dp[i].first);
    }

    vector<int> result;  

    int startIdx, i = n - 1;
    while(i >= 0) {
        if(dp[i].first == maxLen) {
            startIdx = i;
            break;
        }
        i--;
    }

    while(startIdx != -1) {
        result.push_back(nums[startIdx]);
        startIdx = dp[startIdx].second;  // now go the prev element in the sequence 
    }

    reverse(result.begin(), result.end());

    return result;
}
