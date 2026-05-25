#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int> 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

// here the dp array will hold no of paths so we need a state for value 
typedef long long ll;

class Solution {
private:
    const int mod = 1e9 + 7;

    int f(int x, int y, int rem, int k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        // base case 
        int r = grid.size(), c = grid[0].size();

        int curr_rem = (rem + grid[x][y]) % k;

        if(x == r - 1 && y == c - 1) return (curr_rem == 0) ? 1 : 0;

        if(dp[x][y][curr_rem] != -1)
            return dp[x][y][curr_rem];

        ll paths = 0;

        if(x + 1 < r) paths = (paths + f(x + 1, y, curr_rem, k, grid, dp)) % mod;

        if(y + 1 < c) paths = (paths + f(x, y + 1, curr_rem, k, grid, dp)) % mod;

        return dp[x][y][curr_rem] = (int)paths % mod;
    }
 
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // grid[i][j] % k actually matters rather than their original values 
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        // dp[i][j][value] => value <= k

        // start with the rem as 0
        return f(0, 0, 0, k, grid, dp);
    }
};