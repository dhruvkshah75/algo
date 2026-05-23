#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
typedef long long ll; 

// question link: https://leetcode.com/problems/out-of-boundary-paths/description/

// ============================================================================================================================================================
//                                            Memoization dp (Top down approach) => fixed starting point and multiple ending points 
// ============================================================================================================================================================

// using simple arrays for small fixes size arrays is better than vectors due to heap allocation 

class Solution {
private:
    const int mod = 1e9 + 7;
    int M, N;

    vector<pii> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dp[51][51][51];

    int f(int x, int y, int moves) {
        // if the ball moves out of the grid then return 
        if(x >= M || x < 0 || y < 0 || y >= N) return 1;

        // if we run out of moves 
        if(moves == 0) return 0;

        if(dp[x][y][moves] != -1) return dp[x][y][moves];

        ll sum = 0;

        for(auto [dx, dy]: dirs) {
            int posX = x + dx, posY = y + dy;
            sum = (sum + f(posX, posY, moves - 1)) % mod;
        }

        return dp[x][y][moves] = sum;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        this->M = m; this->N = n;
        
        memset(dp, -1, sizeof(dp));

        return f(startRow, startColumn, maxMove);
    }
};


// ================================================================================================================================================
//                                              Bottom up Approach (Tabulation) dp      
// ================================================================================================================================================

class Solution {
private: 
    const int mod = 1e9 + 7;
    vector<pii> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dp[51][51][51]; 

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp, 0, sizeof(dp));
        // base case when moves = 0 then dp = 0 => start from moves = 1 to moves

        for(int moves = 1; moves <= maxMove; moves++) {
            // inner loops is for coordinates of the grid 
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    // this cell [i][j] can be reached from 4 previous cells 
                    for(auto [dx, dy]: dirs) {
                        int prevX = i + dx, prevY = j + dy;
                        
                        // new pos goes out of bounds then add 1 
                        if(prevX < 0 || prevY < 0 || prevX >= m || prevY >= n) { 
                            dp[i][j][moves] = (dp[i][j][moves] + 1) % mod; 
                        }
                        else {
                            dp[i][j][moves] = (dp[i][j][moves] + dp[prevX][prevY][moves - 1]) % mod;
                        }
                    }
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};