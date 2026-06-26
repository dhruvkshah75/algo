// =================================================== dp on subsequences ==========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/profitable-schemes/description/

/* Explaination: 
   f(ind, n, profit) => number of schemes to be chosen 
   ind => index on the group and n => number of people left
   profit => profit earned till this point
   Since Profit >= minProfit at some point => to reduce the space of the 3rd state 
   When profit exceeds minProfit make it equal to minProfit  

   Can commit the same crime only once => 0/1 knapsack

   The Most important Part in the question is to reduce the 3rd state size (profit) 
   When profit exceeds make it equal to minProfit => this reduces the size of the 3rd state to 100

   int next_prof = min(minProfit, prof + profit[ind])
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

typedef long long ll;

class Solution {
private: 
    int minProfit;
    const int MOD = 1e9 + 7;

    int dp[101][101][101];

    int f(int ind, int members_left, int prof, vector<int> &group, vector<int> &profit) {
        // base case: all crimes proccessed 
        if(ind < 0) {
            // if prof >= minProfit => valid case 
            return (prof == minProfit) ? 1 : 0;
        }

        if(dp[ind][members_left][prof] != -1) 
            return dp[ind][members_left][prof];

        // 0-1 KnapSack
        // case 1: dont commit this crime 
        ll not_take = f(ind-1, members_left, prof, group, profit);

        // case 2: commit this crime 
        ll take = 0;
        if(members_left >= group[ind]) {
            int next_prof = min(minProfit, prof + profit[ind]);
            take = f(ind-1, members_left-group[ind], next_prof, group, profit);
        }

        return dp[ind][members_left][prof] = (take + not_take) % MOD;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        this->minProfit = minProfit;

        int m = group.size();

        memset(dp, -1, sizeof(dp));

        return f(m-1, n, 0, group, profit);
    }
};
// Space Complexity = O(M * N * minProfit) + O(M)

// ============================================================================================================================================
//                                                  Bottom Up Approach Tabulation dp
// ============================================================================================================================================

typedef long long ll;

class Solution {
private: 
    const int MOD = 1e9 + 7;

    /*
    int minProfit;
    int dp[101][101][101];

    int f(int ind, int members_left, int prof, vector<int> &group, vector<int> &profit) {
        // base case: all crimes proccessed 
        if(ind < 0) {
            // if prof >= minProfit => valid case 
            return (prof == minProfit) ? 1 : 0;
        }

        if(dp[ind][members_left][prof] != -1) 
            return dp[ind][members_left][prof];

        // 0-1 KnapSack
        // case 1: dont commit this crime 
        ll not_take = f(ind-1, members_left, prof, group, profit);

        // case 2: commit this crime 
        ll take = 0;
        if(members_left >= group[ind]) {
            int next_prof = min(minProfit, prof + profit[ind]);
            take = f(ind-1, members_left-group[ind], next_prof, group, profit);
        }

        return dp[ind][members_left][prof] = (take + not_take) % MOD;
    }
    */

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();

        int dp[m+1][n+1][minProfit+1];
        // 1 based indexing with respect to ith crimes 

        memset(dp, 0, sizeof(dp));

        // base case => ind = 0 (1 based) profit = minProfit => dp = 1
        for(int j = 0; j <= n; j++) 
            dp[0][j][minProfit] = 1;


        for(int ind = 1; ind <= m; ind++) {
            for(int mem = 0; mem <= n; mem++) {
                for(int k = minProfit; k >= 0; k--) {
                    // 0-1 Knapsack 
                    // case 1: dont commit this crime 
                    ll not_take = dp[ind-1][mem][k];

                    // case 2: commit this group if members left 
                    ll take = 0;
                    if(mem >= group[ind-1]) {
                        int next_k = min(minProfit, k + profit[ind-1]);  // state size reduction step
                        take = dp[ind-1][mem-group[ind-1]][next_k];
                    }

                    dp[ind][mem][k] = (take + not_take) % MOD;
                }
            }
        }

        // memo => return f(ind-1, n, 0)
        return dp[m][n][0];
    }
};
// Space Complexity = O(M * N * minProfit)


// The tabulation solution can be space optimised as each step calclulation step depends on ind-1
// 2d prev and curr

// ==============================================================================================================================================
//                                              Space Optimised Tabulation dp
// ==============================================================================================================================================

typedef long long ll;

class SpaceOptimisedSolution {
private: 
    const int MOD = 1e9 + 7;

    /*
    int minProfit;
    int dp[101][101][101];

    int f(int ind, int members_left, int prof, vector<int> &group, vector<int> &profit) {
        // base case: all crimes proccessed 
        if(ind < 0) {
            // if prof >= minProfit => valid case 
            return (prof == minProfit) ? 1 : 0;
        }

        if(dp[ind][members_left][prof] != -1) 
            return dp[ind][members_left][prof];

        // 0-1 KnapSack
        // case 1: dont commit this crime 
        ll not_take = f(ind-1, members_left, prof, group, profit);

        // case 2: commit this crime 
        ll take = 0;
        if(members_left >= group[ind]) {
            int next_prof = min(minProfit, prof + profit[ind]);
            take = f(ind-1, members_left-group[ind], next_prof, group, profit);
        }

        return dp[ind][members_left][prof] = (take + not_take) % MOD;
    }
    */

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();

        vector<vector<int>> prev(n+1, vector<int>(minProfit+1, 0)), curr(n+1, vector<int>(minProfit+1, 0));
        // prev => dp[ind-1] and curr => dp[ind]
        // 1 based indexing with respect to ith crimes 

        // base case => ind = 0 (1 based) profit = minProfit => dp = 1
        for(int j = 0; j <= n; j++) 
            prev[j][minProfit] = 1;


        for(int ind = 1; ind <= m; ind++) {
            for(int mem = 0; mem <= n; mem++) {
                for(int k = minProfit; k >= 0; k--) {
                    // 0-1 Knapsack 
                    // case 1: dont commit this crime 
                    ll not_take = prev[mem][k];

                    // case 2: commit this group if members left 
                    ll take = 0;
                    if(mem >= group[ind-1]) {
                        int next_k = min(minProfit, k + profit[ind-1]);  // state size reduction step
                        take = prev[mem-group[ind-1]][next_k];
                    }

                    curr[mem][k] = (take + not_take) % MOD;
                }
            }

            swap(prev, curr);
        }

        // memo => return f(ind-1, n, 0)
        return prev[n][0];
    }
};
// Space Complexity = O(N * minProfit). Time Complexity = O(M * N * minProfit)