#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/
// important dp question 

// Need to space optimise the code => instead of the dp array we can use dpL and dpR to store only the prev calculation

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        // this is a classic 3d dp question 
        int m = coins.size(), n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        // dp[i][j][k] = coins collected till [i][j] and neutralising k cells on the way 

        if(coins[0][0] >= 0) dp[0][0][0] = coins[0][0];
        else {
            // 2 options he can neutralise the neg cell 
            dp[0][0][0] = coins[0][0];
            dp[0][0][1] = 0;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                // the current cell is only coins 
                if(coins[i][j] >= 0) {
                    vector<int> from_left(3, INT_MIN), from_right(3, INT_MIN);
                    if(i > 0) {
                        for(int k = 0; k < 3; k++) {
                            if(dp[i-1][j][k] == INT_MIN) continue;
                            from_left[k] = dp[i-1][j][k];
                        }
                    }
                    if(j > 0) {
                        for(int k = 0; k < 3; k++) {
                            if(dp[i][j-1][k] == INT_MIN) continue;
                            from_right[k] = dp[i][j-1][k];
                        }
                    }

                    // now take the max of the above two calculations
                    for(int k = 0; k < 3; k++) {
                        if(from_left[k] == INT_MIN && from_right[k] == INT_MIN) continue;
                        dp[i][j][k] = max(from_left[k], from_right[k]) + coins[i][j];
                    }
                }
                else {
                    // we encountered a robber 
                    // now use 0 abiliy, use ability 1 times, use ability 2 times 
                    vector<int> from_left(3, INT_MIN), from_right(3, INT_MIN);
                    
                    if(i > 0) {
                        for(int k = 0; k < 3; k++) {
                            if(dp[i-1][j][k] == INT_MIN) continue;
                            from_left[k] = dp[i-1][j][k];
                        }
                    }
                    if(j > 0) {
                        for(int k = 0; k < 3; k++) {
                            if(dp[i][j-1][k] == INT_MIN) continue;
                            from_right[k] = dp[i][j-1][k];
                        }
                    }

                    for(int k = 0; k < 3; k++) {
                        // Case 1: Don't neutralize the robber (take the negative hit)
                        int best_prev = max(from_left[k], from_right[k]);
                        if(best_prev != INT_MIN) {
                            dp[i][j][k] = max(dp[i][j][k], best_prev + coins[i][j]);
                        }

                        // Case 2: Use ability (neutralize this robber, cost is 0)
                        // This transitions from state k-1 to state k (depends on how many times we neutralised it before )
                        if(k > 0) {
                            int best_prev_k1 = max(from_left[k-1], from_right[k-1]);
                            if(best_prev_k1 != INT_MIN) {
                                dp[i][j][k] = max(dp[i][j][k], best_prev_k1);
                            }
                        }
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};