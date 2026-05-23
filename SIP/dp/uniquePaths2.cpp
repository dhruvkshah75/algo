#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/unique-paths-ii/description/

// ========================================================= DP on Grids or 2d Matrices ================================================================================


// ===================================================================================================================================================== 
//                                                             Bottom up Approach (Tabulation) dp 
// =====================================================================================================================================================

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        // base case when the end point or the starting point is a obstacle
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) 
            return 0; 

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;    

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) 
                    continue;

                // add paths from the top 
                if(i > 0) dp[i][j] += dp[i - 1][j];

                // add paths from the left 
                if(j > 0) dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


/* Space Optimised Solution for unique paths 2 => the logic is the same as the one for unique paths => here each entry depends on the prev Row and prev Col entry 
   Using the concept of Previous row for the outer loop and prevCol (single) entry for the inner loop to simulate like it is using 2d array with only O(N) space */


class SpaceOptimisedSolution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        // base case when the end point or the starting point is a obstacle
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) 
            return 0; 

        vector<int> prevRow(n, 0), temp(n);

        for(int i = 0; i < m; i++) {
            int prevCol = 0;

            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    temp[j] = 1;
                }
                else if(obstacleGrid[i][j] == 1) {
                    temp[j] = prevCol = 0;   // if obstacle then col and row entry must become 0 
                    continue;
                }
                else {
                    temp[j] = prevRow[j] + prevCol;
                } 
                
                prevCol = temp[j];
            }

            prevRow = temp;
        }

        // in the end this entry is equivalent to [m - 1][n - 1]
        return prevRow[n - 1];
    }
};

// =====================================================================================================================================================
//                                                            Top Down Approach (Memoization) dp 
// =====================================================================================================================================================

class RecursiveSolution {
private:
    int f(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        // base case: 
        if(x == 0 && y == 0) 
            return 1;
        else if(x < 0 || y < 0 || grid[x][y] == 1) 
            return 0;

        if(dp[x][y] != -1) 
            return dp[x][y];

        return dp[x][y] = f(x, y-1, grid, dp) + f(x-1, y, grid, dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        // base case when the end point or the starting point is a obstacle
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) 
            return 0; 

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m-1, n-1, obstacleGrid, dp);
    }
};