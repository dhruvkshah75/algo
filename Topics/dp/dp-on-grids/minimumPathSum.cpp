#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: 

// ========================================================= DP on Grids or 2d Matrices ================================================================================


// ===================================================================================================================================================== 
//                                                             Bottom up Approach (Tabulation) dp 
// =====================================================================================================================================================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int add = INT_MAX;

                if(i > 0) add = min(add, dp[i - 1][j]);

                if(j > 0) add = min(add, dp[i][j - 1]);

                dp[i][j] = grid[i][j] + ((add == INT_MAX) ? 0 : add);

            }
        }

        return dp[m - 1][n - 1];
    }
};

/* The above tabulation solution can be space optimsed as each entry depends on the prev Row and the prev Col entry */


class SpaceOptimisedSolution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> prevRow(n, INT_MAX), temp(n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    temp[j] = grid[i][j];
                }
                else if(j == 0) {   // only top nbg
                    temp[j] = grid[i][j] + prevRow[j];
                }
                else if(i == 0) {  // only left nbg
                    temp[j] = grid[i][j] + temp[j - 1];
                }
                else {            // both the nbg exist
                    temp[j] = grid[i][j] + min(temp[j - 1], prevRow[j]);
                }
            }
            prevRow = temp;
        }

        // this entry is equivalent to dp[m-1][n-1] 
        return prevRow[n - 1];
    }
};

// =====================================================================================================================================================
//                                                            Top Down Approach (Memoization) dp 
// =====================================================================================================================================================

class RecursiveSolution {
private:
    int f(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        // base case when invalid entry is accessed or [0][0] reached 
        if(x == 0 && y == 0) return grid[0][0];
        else if(x < 0 || y < 0) return INT_MAX;

        if(dp[x][y] != -1) 
            return dp[x][y];

        return dp[x][y] = grid[x][y] + min(f(x - 1, y, grid, dp), f(x, y - 1, grid, dp));
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, grid, dp);
    }
};