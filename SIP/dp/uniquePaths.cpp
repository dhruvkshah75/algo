#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// ========================================================= DP on Grids or 2d Matrices ================================================================================


// question link: https://leetcode.com/problems/unique-paths/description/

// ======================================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// ======================================================================================================================================================================

class Solution {
public:
    int uniquePaths(int m, int n) {
        // from [i][j] allowed movement is => [i+1][j] and [i][j+1]
        // to find the number of possible paths to reach a particular cell in the grid 

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        dp[1][1] = 1; 

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                // to reach [i][j] cell 
                dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};

class spaceOptimisedSolution {
public: 
    int uniquePaths(int m, int n) {
        /* Optimisation of space 
           
        */
    }
};


// ======================================================================================================================================================================
//                                                          Top Down Approach (Memoization) dp
// ======================================================================================================================================================================

class Solution {
private:    
    int f(int x, int y, vector<vector<int>> &dp) {
        // base case 
        if(x == 0 && y == 0) return 1;

        if(dp[x][y] != -1) return dp[x][y];

        if(x != 0 && y != 0) {
            // both the previous cells are valid then add their ans
            return dp[x][y] = f(x - 1, y, dp) + f(x, y - 1, dp);
        }
        else if(x != 0) {
            return dp[x][y] = f(x - 1, y, dp);
        }
        else if(y != 0) {
            return dp[x][y] = f(x, y - 1, dp);
        }

        return 0;
    }

public:
    int uniquePaths(int m, int n) {
        // using memoization => start from the the end cell [m][n]
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, dp);
    }
};