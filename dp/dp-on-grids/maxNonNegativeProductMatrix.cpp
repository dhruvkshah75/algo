#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

// ================================================================================================================================================
//                                                      Top Down Approach (Memoization) dp         
// ================================================================================================================================================

typedef long long ll;
#define pll pair<ll,ll>

class Solution {
private:
    const int mod = 1e9 + 7;

    pll f(int x, int y, vector<vector<int>> &grid, vector<vector<pll>> &dp) {
        // base case 
        if(x == 0 && y == 0) return {grid[x][y], grid[x][y]};
    
        // invalid cell is accessed 
        if(x < 0 || y < 0 || (size_t)x >= grid.size() || (size_t)y >= grid[0].size()) 
            return {1e12, -1e12};

        if(dp[x][y].first != -1 && dp[x][y].second != -1)
            return dp[x][y];

        if(x - 1 >= 0 && y - 1 >= 0) {
            pll left = f(x, y - 1, grid, dp);
            pll top = f(x - 1, y, grid, dp);

            if(grid[x][y] >= 0)
                return dp[x][y] = {
                    min(left.first * grid[x][y], top.first * grid[x][y]),
                    max(left.second * grid[x][y], top.second * grid[x][y])
                };
            else 
                return dp[x][y] = {
                    min({left.first * grid[x][y], top.first * grid[x][y], left.second * grid[x][y], top.second * grid[x][y]}),
                    max({left.first * grid[x][y], top.first * grid[x][y], left.second * grid[x][y], top.second * grid[x][y]})
                };
        }
        else if(x - 1 >= 0) {
            pll top = f(x - 1, y, grid, dp);

            if(grid[x][y] >= 0) 
                return dp[x][y] = {top.first * grid[x][y], top.second * grid[x][y]};
            else 
                return dp[x][y] = {
                    min(top.first * grid[x][y], top.second * grid[x][y]), 
                    max(top.first * grid[x][y], top.second * grid[x][y])
                };
        }
        else {
            pll left = f(x, y - 1, grid, dp);

            if(grid[x][y] >= 0) 
                return dp[x][y] = {left.first * grid[x][y], left.second * grid[x][y]};
            else 
                return dp[x][y] = {
                    min(left.first * grid[x][y], left.second * grid[x][y]), 
                    max(left.first * grid[x][y], left.second * grid[x][y])                    
                };
        }
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // whenever it comes to dealing with max or min products always store the min and max product encountered

        vector<vector<pll>> dp(m, vector<pll>(n, {-1, -1}));

        pll result = f(m - 1, n - 1, grid, dp);

        if(result.second < 0) return -1;
        else return result.second % mod;
    }
};