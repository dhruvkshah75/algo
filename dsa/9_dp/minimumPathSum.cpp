#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-path-sum/description/

// The current code is not space optimized 

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n));
    // dp[i][j] = min cost to reach the [i][j] cell from top or left cell
    dp[0][0] = grid[0][0];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= 1 && j >= 1)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            else if(i >= 1)
                dp[i][j] = dp[i-1][j] + grid[i][j];
            else if(j >= 1)
                dp[i][j] = dp[i][j-1] + grid[i][j];
        }
    }

    return dp[m-1][n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for(int i = 0; i < m; i++) 
        for(int j = 0 ; j < n; j++)
            cin >> grid[i][j];

    int minSum = minPathSum(grid);

    cout << minSum << endl;
}