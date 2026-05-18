#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/dungeon-game/description/

/*
    VERY IMPORTANT QUESTON:

*/

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    // we must go from end cell to the start cell 
    int m = dungeon.size(), n = dungeon[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    // dp[i][j] = min health needed when entering cell (i,j) to survive from (i,j) all the way to (m-1, n-1)

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(i == m-1 && j == n-1) // the last cell 
                dp[i][j] = max(1 - dungeon[i][j], 1);
            else if(i == m-1)  // last row 
                dp[i][j] = max(dp[i][j+1] - dungeon[i][j], 1);
            else if(j == n-1)
                dp[i][j] = max(dp[i+1][j] - dungeon[i][j], 1);
            else {   // the best path from the right cell or bottom cell => note we are travelling in reverse
                int best_path = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(best_path - dungeon[i][j], 1);
            }
        }
    }
    // finally at the end dp[0][0] indicates the best path followed
    return dp[0][0];
}
