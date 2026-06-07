// ====================================================== VERY IMPORTANT QUESTION =================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int> 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

// ================================================================================================================================================
//                                                  Top Down Approach (Memoization) dp    
// ================================================================================================================================================

// dp on grids => Multiple starting points and multiple ending points 
// moving from j1 to j2 => j1 != j2

class Solution {
private:   
    static constexpr int N = 2e2+1;
    int dp[N][N];

    int f(int i, int j, vector<vector<int>> &grid) {
        // base case: last row reached 
        if(i == 0) return grid[0][j];

        if(dp[i][j] != -1) return dp[i][j];

        // explore all cases of possible options 
        int min_path = 1e9;

        for(int col = 0; col < (int)grid.size(); col++) {
            if(col == j) continue;
            min_path = min(min_path, grid[i][j] + f(i-1, col, grid));
        }

        return dp[i][j] = min_path;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        memset(dp, -1, sizeof(dp));

        // take the min of all the ending points
        int res = 1e9;

        for(int j = 0; j < n; j++) {
            res = min(res, f(n-1, j, grid));
        }

        return res;
    }
};

// ============================================================================================================================================
//                                                  Bottom Up Approach Tabulation dp
// ============================================================================================================================================

class Solution {
private:   
    /*
    static constexpr int N = 2e2+1;
    int dp[N][N];

    int f(int i, int j, vector<vector<int>> &grid) {
        // base case: last row reached 
        if(i == 0) return grid[0][j];

        if(dp[i][j] != -1) return dp[i][j];

        // explore all cases of possible options 
        int min_path = 1e9;

        for(int col = 0; col < (int)grid.size(); col++) {
            if(col == j) continue;
            min_path = min(min_path, grid[i][j] + f(i-1, col, grid));
        }

        return dp[i][j] = min_path;
    } */

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int dp[n][n];

        // base case: i = 0 => dp = grid val
        for(int j = 0; j < n; j++) 
            dp[0][j] = grid[0][j];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // try out all the possible paths
                int min_path = 1e9;

                for(int c = 0; c < n; c++) {
                    if(c == j) continue;
                    min_path = min(min_path, grid[i][j] + dp[i-1][c]);
                }

                dp[i][j] = min_path;
            }
        }

        // now take the min path among all the ending points 
        int res = 1e9;

        for(int j = 0; j < n; j++) {
            res = min(res, dp[n-1][j]);
        }

        return res;
    }
};


// ===========================================================================================================================================
//                                          Space + Time Complexity Optimised Tabulation dp
// ===========================================================================================================================================

/* dp on grids => Multiple starting points and multiple ending points
    moving from j1 to j2 => j1 != j2
    to reduce the time complexity keep the track of the previous min value to get the ans in O(N^2)
    calculate two min values as min value could be such that j1 == j2

    Optimal Solution = O(N^2) 
    Since we only need the two smallest prev elements we precompute them 
*/

#define all(x) x.begin(), x.end()

class Solution {
private:   
    /*
    static constexpr int N = 2e2+1;
    int dp[N][N];

    int f(int i, int j, vector<vector<int>> &grid) {
        // base case: last row reached 
        if(i == 0) return grid[0][j];

        if(dp[i][j] != -1) return dp[i][j];

        // explore all cases of possible options 
        int min_path = 1e9;

        for(int col = 0; col < (int)grid.size(); col++) {
            if(col == j) continue;
            min_path = min(min_path, grid[i][j] + f(i-1, col, grid));
        }

        return dp[i][j] = min_path;
    } */

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> prev(n, 0), curr(n, 0);
        // prev => dp[i-1] and curr => dp[i]

        // base case: i = 0 => dp = grid val
        for(int j = 0; j < n; j++) 
            prev[j] = grid[0][j];
        

        for(int i = 1; i < n; i++) {
            // use the two min values from the prev row 
            int min1 = 1e9, min2 = 1e9;

            for(int j = 0; j < n; j++) {
                if(prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                }
                else if(prev[j] < min2) {
                    min2 = prev[j];
                }
            }

            for(int j = 0; j < n; j++) {
                // use the min value of the prev array 
                curr[j] = grid[i][j] + ((prev[j] == min1) ? min2 : min1);
            }

            swap(prev, curr);
        }

        // now take the min path among all the ending points 
        // after all the iterations prev => dp[n-1]
        return *min_element(all(prev));
    }
};