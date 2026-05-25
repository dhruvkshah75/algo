#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int> 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/



/* question is on multiple starting points and multiple ending points
   Here each move is based on the cost to move from the previous cells 
   The final ans is the sum of cells visited + path followed */


// ================================================================================================================================================
//                               Top Down Approach (Memoization) dp with Multiple starting point and Multiple Ending Points        
// ================================================================================================================================================

class RecursiveSolution {
private:    
    int dp[51][51];

    int f(int x, int y, int r, int c, vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        // last row reached then 
        if(x == r - 1) return grid[x][y];
        
        if(dp[x][y] != -1) return dp[x][y];

        int min_path = 1e8, i = grid[x][y];

        for(int j = 0; j < c; j++) {
            // moving from [x][y] to [x+1][j]
            int move_cost = moveCost[i][j];
            min_path = min(min_path, move_cost + f(x + 1, j, r, c, grid, moveCost));
        }

        return dp[x][y] = grid[x][y] + min_path;
    }

public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        
        memset(dp, -1, sizeof(dp));

        // since we can start from any cell in the first row 

        int result = 1e8;

        for(int j = 0; j < n; j++) {
            result = min(result, f(0, j, m, n, grid, moveCost));
        }

        return result;
    }
};

// ================================================================================================================================================
//                                              Bottom up Approach (Tabulation) dp      
// ================================================================================================================================================

/* Start from the base case of memoization as the starting point in dp
   This question is based on multiple starting points and multiple ending points
   This question can be space optimised as each calculation depends on the previous row calculated 
*/

class Solution {
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        int m = grid.size(), n = grid[0].size();

        int dp[51][51];

        memset(dp, 0, sizeof(dp));

        // base case => in the last row all dp values are the same as grid values 
        for(int j = 0; j < n; j++) {
            dp[m - 1][j] = grid[m - 1][j];
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int curr = grid[i][j];
                // find the best path to move to next row 
                int min_path = 1e8;

                for(int col = 0; col < n; col++) {
                    // path sum would be min sum to reach [i+1][col] would be dp of it for accumulation and cost to move there  
                    min_path = min(min_path, dp[i + 1][col] + moveCost[curr][col]);
                }

                dp[i][j] = grid[i][j] + min_path;
            }
        }

        // now the result would be the minimum of all the ending points => here any first row of the grid 
        int result = 1e9;

        for(int j = 0; j < n; j++) {
            result = min(result, dp[0][j]);
        }

        return result;
    }
    // O(M * N * N)
};


// Space Optimised Solution 

