// ====================================================== VERY IMPORTANT QUESTION =================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int> 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/cherry-pickup-ii/description/

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1)

// ================================================================================================================================================
//                                                  Top Down Approach (Memoization) dp    
// ================================================================================================================================================

/* Algorithm: 
   In the recursion we denote the position of both robots and each point separetly x1, y1 => robot 1 and x2, y2 => robot 2 
   x1 and x2 will always remain the same => as in each recursive step they move to the next row 
   We directly handle the sum of the total cherry picked by the robots by returning the sum of both 
   Keep a note of the fact that if the robots land at the same spot then cherries must be counted only once 
   dp[x][y1][y2] ==> indicates the max cherries collected at coordinates of robot 1 => (x, y1) and robot 2 => (x2, y2) 
   
   Space Complexity = O(M) + O(M * N * N) => recursion stack space is O(M) as each one call per row and the other space is the dp vector 
   The space can be optimised to use only O(N * N) as each calculation depends only on the previous Row 
   
   
   Very Important Note: 
   Both the positions of robots were important for each step calculation => here both the robots move in such a way that their rows always remains the same 
   Only differing position is their columns so we use dp[row][col1][col2] */


class RecursiveSolution {
private:
    const vector<int> dir = {-1, 0, 1};

    int f(int x, int y1, int y2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {

        int row = grid.size(), col = grid[0].size();
        
        // boundary condition check 
        if(y1 < 0 || y1 >= col || y2 < 0 || y2 >= col) return -1e8;
        
        // last row => end cell reached 
        if(x == row - 1) {
            // both robots ended up on the same cell so counted only once 
            if(y1 == y2) return grid[x][y1];
            else return grid[x][y1] + grid[x][y2];
        }

        if(dp[x][y1][y2] != -1) return dp[x][y1][y2];

        // to explore all the paths of both the robots must move simultaneously => consider all 9 (3 x 3) possibilites 
        int maxi = -1e8;
        
        for(int dy1: dir) {
            for(int dy2: dir) {
                maxi = max(maxi, f(x + 1, y1 + dy1, y2 + dy2, grid, dp));
            }
        }

        int curr = ((y1 == y2) ? grid[x][y1] : (grid[x][y1] + grid[x][y2]));
        return dp[x][y1][y2] = curr + maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));

        // memoization starts from the 2 fixed starting points simultaneously 
        return f(0, 0, col - 1, grid, dp);
    }
};


// ================================================================================================================================================
//                                              Bottom up Approach (Tabulation) dp      
// ================================================================================================================================================

/* This question involves using a 3d dp concept where we start from fixed point (2 starting points) to variable ending points 
   Convert Memoization to tabulation follow these steps
   1. Write down the base cases 
   2. Express every state in for loops => here there are 3 states so 3 for loops 


   In this question we write down the base case i.e. the case when both the robots are in the last row n-1
*/

class Solution {
private:
    const int inf = 1e8;

    vector<int> dir = {-1, 0, 1};

public:
    int cherryPickup(vector<vector<int>>& grid) {

        int row = grid.size(), col = grid[0].size();

        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));

        // tabulation here is done in reverse => starting from the ending points
        for(int j1 = 0; j1 < col; j1++) {
            for(int j2 = 0; j2 < col; j2++) {
                
                dp[row - 1][j1][j2] = ((j1 == j2) ? grid[row - 1][j1] : (grid[row - 1][j1] + grid[row - 1][j2]));
            }
        }


        for(int r = row - 2; r >= 0; r--) {
            for(int c1 = 0; c1 < col; c1++) {
                for(int c2 = 0; c2 < col; c2++) {
                    // now consider all the 9 possiblities to get the best path 
                    int maxi = -1e8;

                    for(int dy1: dir) {
                        for(int dy2: dir) {
                            int y1 = c1 + dy1, y2 = c2 + dy2;
                            // check if the y1 and y2 are in bounds or not 

                            if(y1 < 0 || y2 < 0 || y1 >= col || y2 >= col) 
                                continue;

                            maxi = max(maxi, dp[r + 1][c1 + dy1][c2 + dy2]);
                        }
                    }

                    int curr = ((c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]));
                    dp[r][c1][c2] = curr + maxi;
                }
            }
        }

        return dp[0][0][col - 1];
    }
};



/* This solution can be space optimised to O(N * N) as each calculation on depends on the prev Row */

class SpaceOptimisedSolution {
private:
    const int inf = 1e8;

    vector<int> dir = {-1, 0, 1};

public:
    int cherryPickup(vector<vector<int>>& grid) {

        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> prevRow(col, vector<int>(col, 0));

        // tabulation here is done in reverse => starting from the ending points => prevRow for row => n - 1
        for(int j1 = 0; j1 < col; j1++) {
            for(int j2 = 0; j2 < col; j2++) {
                
                prevRow[j1][j2] = ((j1 == j2) ? grid[row - 1][j1] : (grid[row - 1][j1] + grid[row - 1][j2]));
            }
        }


        for(int r = row - 2; r >= 0; r--) {
            vector<vector<int>> temp(col, vector<int>(col));

            for(int c1 = 0; c1 < col; c1++) {
                for(int c2 = 0; c2 < col; c2++) {
                    // now consider all the 9 possiblities to get the best path 
                    int maxi = -1e8;

                    for(int dy1: dir) {
                        for(int dy2: dir) {
                            int y1 = c1 + dy1, y2 = c2 + dy2;
                            // check if the y1 and y2 are in bounds or not 

                            if(y1 < 0 || y2 < 0 || y1 >= col || y2 >= col) 
                                continue;

                            maxi = max(maxi, prevRow[y1][y2]);
                        }
                    }

                    int curr = ((c1 == c2) ? grid[r][c1] : (grid[r][c1] + grid[r][c2]));
                    temp[c1][c2] = curr + maxi;
                }
            }

            prevRow = temp;
        }

        // this is equivalent to getting the max cherries collected by both robots 
        return prevRow[0][col - 1];
    }
};