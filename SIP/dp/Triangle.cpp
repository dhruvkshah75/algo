#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int> 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/triangle/description 

/* This question of dp on 2d grids is Fixed starting point and mutliple ending points 
   we must start from the top cell and then reach any cell in the last row */

// ================================================================================================================================================
//                               Top Down Approach (Memoization) dp with Fixed starting point and Multiple Ending Points        
// ================================================================================================================================================

// The path length is n - 1 as we we go to previous row in each step 

const int inf = INT_MAX;

class RecursiveSolution {
private: 
    int f(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
        // base case if the [0][0] is reached or invalid cell is accessed 
        if(row == 0 && col == 0) return triangle[0][0];
        else if(row < 0 || col < 0 || (size_t)col >= dp[row].size()) return inf;
        

        if(dp[row][col] != -1) 
            return dp[row][col];    

        // [r][c] can be reached from [r-1][c] or [r-1][c-1]
        return dp[row][col] = triangle[row][col] + min(f(row - 1, col, triangle, dp), f(row - 1, col - 1, triangle, dp));
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        /* from row i to row i + 1 => we can move from jth index of row i to j or j+1 the index of the i+1 th row 
           Like normal 2d dp grid questions we simply start recursive calls from all the elements of the last row 
           Note: the invalid cell shouldnt be accessed so it should be marked with very high value */

        vector<vector<int>> dp(n);

        // we must assign same number of cells to dp => all initialised to -1 
        for(int r = 0; r < n; r++) 
            for(int c = 0; c < triangle[r].size(); c++) 
                dp[r].push_back(-1);
        
        
        // since there are multiple ending points so we must take minimum among all of them 
        int result = inf;

        for(int i = 0; (size_t)i < dp[n - 1].size(); i++) {
            result = min(result, f(n - 1, i, triangle, dp));
        }

        return result;
    }
};



// there is anathor recursive solution that works where we start exploring all the possible paths from the fixed end 

class RecursiveSolutionTwo {
private:
    const int inf = 1e5;       // all values range in -1e4 to 1e4

    int f(int r, int c, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
        // base case => when will we stop => reaching the n-1 th row 
        if(r == (int)triangle.size() - 1) return triangle[r][c];

        if(dp[r][c] != inf)
            return dp[r][c];

        return dp[r][c] = triangle[r][c] + min(f(r + 1, c, triangle, dp), f(r + 1, c + 1, triangle, dp));
    }

public: 
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();

        // from the current ith cell of row r move to ith and i+1th cell of r+1 th row 

        vector<vector<int>> dp(n);

        // we must assign same number of cells to dp => all initialised to -1 
        for(int r = 0; r < n; r++) 
            dp[r].resize(triangle[r].size(), inf);

        return f(0, 0, triangle, dp);
    }
};

// ================================================================================================================================================
//                               Bottom up Approach (Tabulation) dp with Fixed starting point and Multiple Ending Points        
// ================================================================================================================================================

class Solution {
public: 
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n);

        // initiliase all the values in the dp to 0 as all the dp[i] has i + 1 elements 
        for(int i = 0; i < n; i++) 
            for(int j = 0; (size_t)j < triangle[i].size(); j++) 
                dp[i].push_back(0);
        
        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; (size_t)j < triangle[i].size(); j++) {
                if(j == 0) {      // only one prev cell exists [j]
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                } 
                else if(j == i) {   // Only one prev cell exists [j-1]
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                } 
                else {    // both prev cells exist 
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }

        // for dealing with multiple ending points take the min element of the last row of dp 
        return (int)*min_element(dp[n-1].begin(), dp[n-1].end());
    }
};


// ========================================= Very Important Space Optimised solution =========================================================================
/* Space Optimisation can be done as each entry depends only on the prev entry */

class SpaceOptimisedSolution {
public: 
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();

        vector<int> prevRow, temp;

        prevRow.resize(1, triangle[0][0]);

        for(int i = 1; i < n; i++) {
            // ith row has i + 1 elements 
            temp.resize(i + 1);

            for(int j = 0; (size_t)j < triangle[i].size(); j++) {
                if(j == 0) {      // only one prev cell exists [j]
                    temp[j] = triangle[i][j] + prevRow[j];
                } 
                else if(j == i) {   // Only one prev cell exists [j-1]
                    temp[j] = triangle[i][j] + prevRow[j - 1];
                } 
                else {    // both prev cells exist 
                    temp[j] = triangle[i][j] + min(prevRow[j - 1], prevRow[j]);
                }
            }

            prevRow.resize(i + 1);
            prevRow = temp;
        }

        // for dealing with multiple ending points take the min element of the last row of dp which is prevRow after all the iterations 
        return (int)*min_element(prevRow.begin(), prevRow.end());
    }
};