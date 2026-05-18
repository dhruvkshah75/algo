#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

// NOTE: for product questions with negative number always rememeber to store minimum and maximum Product

/*
    we are supposed to calculate maxProduct => for product based questions always keep track of min product 
    and max product as on multiplying with negative number min and max get swapped 
    NOTE: max and min doesnt matter comes from which cell top cell or left cell 
*/
typedef long long ll;

class Solution {
    int mod = 1e9 + 7;

    // these functions calculate the max and min product
    pair<ll,ll> MaxMinCombo(pair<ll,ll> &a, pair<ll,ll> &b, int curr) {
        auto &[x1, y1] = a;
        auto &[x2, y2] = b;

        pair<ll,ll> result;
        result.first = max({x1*curr, x2*curr, y1*curr, y2*curr});
        result.second = min({x1*curr, x2*curr, y1*curr, y2*curr});

        return result;
    }

    pair<ll,ll> MaxMinCombo(pair<ll,ll> &a, int curr) {
        auto &[x, y] = a;

        pair<ll,ll> result;
        result.first = max(x*curr, y*curr);
        result.second = min(x*curr, y*curr);

        return result;
    }

public:
    int maxProductPath(vector<vector<int>>& grid) { 
        int m = grid.size(), n = grid[0].size();

        vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n));
        // dp[i][j] = {x, y} here x = maxProduct and y = minProduct for the path till [i][j] cell

        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // [i][j] cell can be accessed from [i-1][j] and [i][j-1] cell 
                int curr = grid[i][j];

                if(i >= 1 && j >= 1) {
                    // we multiply curr with all and store the max and min 
                    dp[i][j] = MaxMinCombo(dp[i-1][j], dp[i][j-1], curr);
                }
                else if(i >= 1) {
                    dp[i][j] = MaxMinCombo(dp[i-1][j], curr);
                }
                else if(j >= 1) {
                    dp[i][j] = MaxMinCombo(dp[i][j-1], curr);
                }
            }
        }

        if(dp[m-1][n-1].first < 0)
            return -1;
        
        return dp[m-1][n-1].first % mod;
    }
};