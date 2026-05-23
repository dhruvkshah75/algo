#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int> 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://takeuforward.org/plus/dsa/problems/minimum-falling-path-sum

// ========================================= Multiple starting points and multiple ending points ===========================================================

/* Here the starting point is any element in the first row and end point is any cell in the last row 
   Similar to triangle but the start point is not fixed 
   Simply recurse for all starting points and then stop the recursion when the last row is reached */

// ================================================================================================================================================
//                               Top Down Approach (Memoization) dp with Multiple starting point and Multiple Ending Points        
// ================================================================================================================================================

class RecursiveSolution {
private: 
    const int inf = 1e9;             // values in the range [-1e3, 1e3] and N = 1e2 => this is the value to be returned when we dont want it to be counted 
    const int unvisited = 1e9 + 7;   // dp of that cell is not counted yet 

    int f(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        int m = matrix.size(), n = matrix[0].size() ;
        // base case when invalid cell accessed or last row reached 
        if(c < 0 || c >= n) return inf;
        else if(r == m - 1) return matrix[r][c];

        if(dp[r][c] != unvisited) 
            return dp[r][c];

        return dp[r][c] = matrix[r][c] + min({f(r + 1, c - 1, matrix, dp), f(r + 1, c, matrix, dp), f(r + 1, c + 1, matrix, dp)});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // [row][col] can move to [row + 1][col], [row + 1][col + 1] and [row + 1][col - 1]
        vector<vector<int>> dp(m, vector<int>(n, unvisited));

        // since the starting points are variable call the recursion for all starting points

        int result = inf;

        for(int j = 0; j < n; j++) 
            result = min(result, f(0, j, matrix, dp));
        
        return result;
    }
};


// ================================================================================================================================================
//                               Bottom up Approach (Tabulation) dp with Multiple starting point and Multiple Ending Points        
// ================================================================================================================================================

/* Prefill the first row of the matrix in the dp array and then compute the values from the next rows till the end row is reached */

class Solution {
public: 
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // initialise the first row i.e. the starting points 
        for(int j = 0; j < n; j++) 
            dp[0][j] = matrix[0][j];

        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j > 0 && j + 1 < n) {  // all three prev positions exist  
                    dp[i][j] = matrix[i][j] + min({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]});
                }
                else if(j > 0) {         // only the left diagnol and top element exists 
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
                else if(j + 1 < n) {    // only right diagnol and top element exists 
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                }
                else {                 // only one column in the matrix 
                    dp[i][j] = matrix[i][j] + dp[i-1][j];
                }
            }
        }

        // since the last row is the ending point => take the min of all the dp values in the last row 
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};


/* This tabulation method can be space optimised as each entry depends on only the prev Row */

class SpaceOptimisedSolution {
public: 
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> prevRow(n), temp(n);

        // initialise the first row i.e. the starting points 
        for(int j = 0; j < n; j++) 
            prevRow[j] = matrix[0][j];

        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j > 0 && j + 1 < n) {  // all three prev positions exist  
                    temp[j] = matrix[i][j] + min({prevRow[j], prevRow[j-1], prevRow[j+1]});
                }
                else if(j > 0) {         // only the left diagnol and top element exists 
                    temp[j] = matrix[i][j] + min(prevRow[j], prevRow[j-1]);
                }
                else if(j + 1 < n) {    // only right diagnol and top element exists 
                    temp[j] = matrix[i][j] + min(prevRow[j], prevRow[j+1]);
                }
                else {                 // only one column in the matrix 
                    temp[j] = matrix[i][j] + prevRow[j];
                }
            }

            swap(prevRow, temp);           // prevRow = temp;
        }

        // since the last row is the ending point => take the min of all the dp values in the last row 
        return *min_element(prevRow.begin(), prevRow.end());
    }
};