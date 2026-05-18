#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/unique-paths/description

// Standard 2D dp question 

// This solution is not space optimised 
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));

    // use bottom up approach start from the [0][0]
    // dp[i][j] = no of unique ways to reach the [i][j] cell 

    dp[0][0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // to reach the [i][j] cell we can come from [i-1][j] or [i][j-1]
            if(i >= 1 && j >= 1) 
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else if(i >= 1)
                dp[i][j] = dp[i-1][j];
            else if(j >= 1)
                dp[i][j] = dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

// question link: https://leetcode.com/problems/unique-paths-ii/description/

// Unique path II with obstacles in the path => standard 2d dp question  

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    // use the same logic as unique paths => if we reach the obstactle then set dp[i][j] = 0 
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n));
    // dp[i][j] = no of unique ways to reach the [i][j] cell 

    dp[0][0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // we can reach the curr cell from the top or the left cell 
            if(obstacleGrid[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            if(i >= 1 && j >= 1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else if(i >= 1)
                dp[i][j] = dp[i-1][j];
            else if(j >= 1)
                dp[i][j] = dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}