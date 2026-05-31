// ==================================================================== dp on subsequences ===================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/coin-change-ii/description/

/* This question is the same as Coin change 1 with infite supply of each coin 
   Here we are asked to find the number of ways we can get the sum => just explore all the paths */

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecursiveSolution {
private:    
    int f(int x, int W, vector<int> &coins, vector<vector<int>> &dp) {
        // base case: sum = 0 => found a way to get the amount
        if(W == 0) return 1;
        // base case: last coin reached 
        if(x == 0) {
            if(W % coins[x] == 0) return 1;
            else return 0;
        }

        if(dp[x][W] != -1) return dp[x][W];

        int not_take = f(x - 1, W, coins, dp);
        // since there is infinite supply of coins => take multiple coins of the same denomination
        int take = 0;
        if(W >= coins[x]) take = f(x, W - coins[x], coins, dp);

        return dp[x][W] = take + not_take;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return f(n - 1, amount, coins, dp);
    }
};

// time complexity = O(N * Amount)
// Space complexity = O(N * Amount) + O(N) (auxiliary stack space)

// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

/* Question mentions that the ans fits in signed 32 bit integer => but the intermediate step answers may not fit
   Solve using the dp array as unsigned long long 
*/

typedef unsigned long long ull;

class Solution {
public: 
    int change(int amount, vector<int> &coins) {
        int n = coins.size();

        vector<vector<ull>> dp(n, vector<ull>(amount + 1, 0));

        // base case: W = 0 => dp = 1
        for(int i = 0; i < n; i++) 
            dp[i][0] = 1;

        // base case: x == 0 (first index)
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) dp[0][t] = 1;
            else dp[0][t] = 0;
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                // explore the cases of taking the coin or not 
                ull not_take = dp[i - 1][t];
                ull take = 0;
                if(t >= coins[i]) take = dp[i][t - coins[i]];

                dp[i][t] = take + not_take;
            }
        }

        return (int)dp[n - 1][amount];
    }
};

// this solution can be space optimised to have only 1d array 

class SpaceOptimisedSolution {
public: 
    int change(int amount, vector<int> &coins) {
        int n = coins.size();

        vector<ull> prev(amount + 1, 0), curr(amount + 1, 0);
        // prev => dp[i - 1] and curr => dp[i] 

        // base case: W = 0 => dp = 1
        // base case: x == 0 (first index)
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) prev[t] = 1;
            else prev[t] = 0;
        }

        for(int i = 1; i < n; i++) {
            curr[0] = 0;
            for(int t = 0; t <= amount; t++) {
                // explore the cases of taking the coin or not 
                ull not_take = prev[t];
                ull take = 0;
                if(t >= coins[i]) take = curr[t - coins[i]];

                curr[t] = take + not_take;
            }

            swap(prev, curr);
        }

        // after all the iterations prev denotes dp[n - 1]
        return (int)prev[amount];
    }
};