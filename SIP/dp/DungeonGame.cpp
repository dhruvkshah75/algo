#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int,int>

// question link: https://leetcode.com/problems/dungeon-game/description/

// Using Bottom Up Tabulation approach 


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size(), c = dungeon[0].size();
        
        int dp[201][201];

        memset(dp, 0, sizeof(dp));

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (i == r - 1 && j == c - 1) {  // Princess Cell
                    dp[i][j] = min(0, dungeon[i][j]);
                } 
                else if (i == r - 1) {  // Last row (only right move possible)
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j + 1]);
                } 
                else if (j == c - 1) {   // Last column (only down move possible)
                    dp[i][j] = min(0, dungeon[i][j] + dp[i + 1][j]);
                } 
                else {
                    int best_health = max(dp[i][j + 1], dp[i + 1][j]);
                    dp[i][j] = min(0, dungeon[i][j] + best_health);
                }
            }
        }

        return abs(dp[0][0]) + 1;
    }
};

