#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-product-subarray/description/

// This code is not space optimised => Space Complexity = O(N) => which is redundant 
int maxProduct(vector<int>& nums) {
    // use dp to calculate the max product till the ith cell 
    int n = nums.size();

    vector<pair<int,int>> dp(n);
    dp[0] = {nums[0], nums[0]};
    // dp[i] = {x,y}  => x = maxProduct of the subarray that ith index is a part of 
    int maxProduct = nums[0];

    for(int i = 1; i < n; i++) {
        // previous min and max Product
        auto [x, y] = dp[i-1];

        pair<int,int> result;
        // max and min will be either including the prev elements in the subarray or starting fresh
        result.first = max({x*nums[i], y*nums[i], nums[i]});
        result.second = min({x*nums[i], y*nums[i], nums[i]});

        dp[i] = result;

        maxProduct = max(maxProduct, dp[i].first);
    } 

    return maxProduct;
}


// Space Optimised code => Space complexity = O(1)

int maxProductSubarray(vector<int>& nums) {
    // use dp to calculate the max product till the ith cell 
    int n = nums.size();

    // instead of using O(N) space 
    int dpMin = nums[0], dpMax = nums[0];
    // dpMin = minProduct till including ith cell, dpMax = maxProduct till including ith cell 

    int maxProduct = nums[0];

    for(int i = 1; i < n; i++) {
        // previous min and max Product is dpMin and dpMax 

        // max and min will be either including the prev elements in the subarray or starting fresh
        int tempMax = max({dpMax * nums[i], dpMin * nums[i], nums[i]});
        int tempMin = min({dpMax * nums[i], dpMin * nums[i], nums[i]});

        dpMax = tempMax;
        dpMin = tempMin;

        maxProduct = max(maxProduct, dpMax);
    } 

    return maxProduct;
}
