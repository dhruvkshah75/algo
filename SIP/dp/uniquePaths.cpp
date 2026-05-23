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

    /* Optimisation of space 
    We can space optimise the question as we are only using the previous row and previous column so the entire array can be eliminated
    For loops work like => pick the ith row then explore all the column cells of that row 

    Maintain a prevRow array which stores all the values for (i-1)th row when the ith row is being explored => This one is for the outer for loop 
    For the inner loop => for the jth column we must know the value for j-1 th column for that particular row 

    . . . . .
    . . . . X to get X we need the prev Row value and prev entry to X so we can get that using O(N) space */

class spaceOptimisedSolution {
public: 
    int uniquePaths(int m, int n) {

        // previous row array as used for dp space optimisation  
        vector<int> dpRow(n, 0), temp(n);

        for(int i = 0; i < m; i++) {
            int dpCol = 0;

            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) 
                    temp[j] = 1; 
                else 
                    temp[j] = dpRow[j] + dpCol;
                
                dpCol = temp[j];
            }

            dpRow = temp;
        }

        // in the end prevRow[n-1] will contain the entry for [m-1][n-1]
        return dpRow[n-1];
    }
};


// ======================================================================================================================================================================
//                                                          Top Down Approach (Memoization) dp
// ======================================================================================================================================================================

/* Start from the top that is the end [m][n] and then add the ways to reach the prev 2 cells and keep recursively till the cell is 0, 0 is reached 
   and use dp optimisation logic to make this code O(M * N)

   When can i apply Memoization ? => if in recursion there are overlapping subproblems then use dp 
   space complexity in this question is based on recursion stack and declared dp vector 
   Recursion call stack space is the path length (how deep the recursion went) => O((N - 1) + (M - 1)) and O(M * N) for dp vector  
*/

class RecursiveSolution {
private:    
    int f(int x, int y, vector<vector<int>> &dp) {
        // base case 
        if(x == 0 && y == 0) 
            return 1;
        else if(x < 0 || y < 0)   // if this cell is invalid then return 0
            return 0;

        if(dp[x][y] != -1) 
            return dp[x][y];

        return dp[x][y] = f(x - 1, y, dp) + f(x, y - 1, dp);
    }

public:
    int uniquePaths(int m, int n) {
        // using memoization => start from the the end cell [m][n]
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, dp);
    }
};