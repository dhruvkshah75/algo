#include<bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/cherry-pickup/description/

/* In this the concept of round trip that is going from n-1, n-1 to 0, 0 again can be converted to anathor person moving from the start to end 
   The question typically becomes 2 person walk from [0][0] to [n-1][n-1]

   Memoizaton starting from 0,0 to end up at n-1, n-1
   both persons going down and left 
*/

// ================================================================================================================================================
//                                                     Top Down Approach (Memoization) dp        
// ================================================================================================================================================

/* Very Important Note: 
   The concept of round trip that is reaching the end cell and then coming back to top cell cant be done in 2 steps 
   Both the movement needs to done simultaneously => consider a person Person 1 is moving from [0][0] and Person 2 is moving from [n-1][n-1]
   This can be converted into the fact that going from [n-1][n-1] to [0][0] by moving up and backward left is the same as 
   Both the persons starting from the same starting point [0][0] and reaching the end cell  
   Note: If either of the person ends up in the end cell then the other person also ends up in the same cell (kind of non intuitive to think)
   as both of them take the same number of steps 
   The question is completely transformed into a question into a 2 person starting at the same point and want to collect max possible cherries on their
   way to reach the end cell 

   Time Complexity = O(steps * N * N) => max steps are 2 * N - 2
   so O(N ^ 3)
*/

#define pii pair<int,int>
typedef long long ll;

class Solution {
private:
    vector<pii> dir = {{1, 0}, {0, 1}};

    int dp[100][51][51];
    // dp[steps][y1][y2] => we can have a max of 98 steps => n - 1 + n - 1

    int f(int x1, int y1, int x2, int y2, int steps, vector<vector<int>> &grid) {
        int n = grid.size();

        // base case => invalid cell accessed or obstacle reached 
        if(x1 >= n || y1 >= n || x2 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1)
            return -1e8;

        // Note: if 1 person reaches the end cell then both end in the same cell => as both of them take the same number of steps 
        if(x1 == n - 1 && y1 == n - 1) return grid[x1][y1];

        if(dp[steps][y1][y2] != -1) return dp[steps][y1][y2]; 

        int cherries = 0;
        // both end up in the same cell or both of them are in different places 
        if(x1 == x2 && y1 == y2) cherries = grid[x1][y1];
        else cherries = grid[x1][y1] + grid[x2][y2];
    
        int maxi = -1e8;

        // explore all the 4 possible moves (2 x 2)
        for(auto [dx1, dy1]: dir) {
            for(auto [dx2, dy2]: dir) {
                // select the best step to be taken from this cell 
                maxi = max(maxi, f(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2, steps + 1, grid));
            }
        }

        return dp[steps][y1][y2] = maxi + cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        // similar to max sum path problem with obstacles 
        int n = grid.size();

        memset(dp, -1, sizeof(dp));

        int result = f(0, 0, 0, 0, 0, grid);
        // if there is no valid path to reach n-1, n-1 then 0
        if(result > 0)
            return result;
        else 
            return 0;
    }
};