#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

/* Explanation: dp on graphs LIS variant 
   Here dp[i][j] is the length of the longest increasing sequence in any direction 
   starting at [i][j]
   So simply apply dfs + memoization and the longest increasing sequence can start 
   from any value so we must take max of all possibilities 
*/

class Solution {
private:    
    int m, n;
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>> &matrix) {
        
        if(dp[i][j] != -1) return dp[i][j];

        // try all possible paths to get the longest length 
        int maxi = 1;

        for(auto [dx, dy]: dirs) {
            int ni = i + dx, nj = j + dy;
            // [ni][nj] is the next index that we move onto to only if it is LIS
            if(ni < m && nj < n && ni >= 0 && nj >= 0 && matrix[ni][nj] > matrix[i][j]) {
                maxi = max(maxi, 1 + dfs(ni, nj, matrix));
            }
        }

        return dp[i][j] = maxi;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();

        dp.resize(m, vector<int>(n, -1));

        // note: the longest increasing sequence can start from any value so we must take max of all possibilities 
        int res = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }
        
        return res;
    }
};