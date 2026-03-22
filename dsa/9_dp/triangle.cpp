#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/triangle/description/

// There exists a better solution where we use only O(N) space => Think about it 

/*
    The Approach here is Top Down Approach => Memoization where use dp to make the recursion tree into a liner search 
    ith element in the curr row can be derived from i-1 and i parents 
    i + 1 elements in the ith row => solved using Memoization

    Each cell (row, i) is computed exactly once due to memoization, 
    and there are 1 + 2 + 3 + ... + n = n(n+1)/2 cells in the triangle.
*/

int minPathSum(vector<vector<int>> &dp, vector<vector<int>> &triangles, int row, int i) {
    // row indicates which curr row and i indicates which index in that row 
    if(row == 0)
        return dp[row][i] = triangles[row][i];

    if(dp[row][i] != -1)  
        return dp[row][i];

    // cell (row, i) can be reached from (row-1, i-1) or (row-1, i)
    int leftMinSum = INT_MAX, rightMinSum = INT_MAX;

    if(i - 1 >= 0) // parent (row-1, i-1) exists
        leftMinSum = minPathSum(dp, triangles, row-1, i-1);

    if(i <= row - 1) // parent (row-1, i) exists
        rightMinSum = minPathSum(dp, triangles, row-1, i);
    
    return dp[row][i] = min(leftMinSum, rightMinSum) + triangles[row][i];
}


int minimumTotal(vector<vector<int>>& triangles) {
    int n = triangles.size();

    // we follow a top down approach start from the bottom of the triangle 
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // we call the minPathSum for all the elements in the last row of the triangle
    int result = INT_MAX;

    for(int i = 0; i < n; i++) {
        result = min(result, minPathSum(dp, triangles, n-1, i));
    }

    return result;
}
