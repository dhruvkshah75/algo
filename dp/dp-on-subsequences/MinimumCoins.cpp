// ==================================================== dp on Subsequences ==============================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/coin-change/description/

/* Explaination: 
   This is different as compared to 0/1 Knapsack where each element could only be taken once 
   Here we have infinite supply of each coin type 
   So while taking a coin dont make the index x -> x - 1 stay at x with the reduced total target 
   => if(coins[x] <= W) take = f(x, W - coins[x], coins, dp)

   Very similar to 0/1 Knapsack but with infinite supply of each element so while taking each element (take) dont jump to 
   the next index => from x to x - 1 => remain at x with reduced amount => W - coins[x]
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecursiveSolution {
private:  
    const int inf = 1e8;

    int f(int x, int W, vector<int> &coins, vector<vector<int>> &dp) {
        // base case: last coin reached 
        if(x == 0) {
            // we can form the amount using coins[0]
            if(W % coins[0] == 0) return (W / coins[0]);
            else return inf;
        }

        if(dp[x][W] != -1) return dp[x][W];

        // try all possible combinations 
        int not_take = f(x - 1, W, coins, dp);
        int take = inf;
        
        if(coins[x] <= W) take = 1 + f(x, W - coins[x], coins, dp);

        return dp[x][W] = min(take, not_take);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // base case when amount = 0
        if(amount == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int res = f(n - 1, amount, coins, dp);

        return (res >= inf) ? -1 : res;
    }
};

// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

class Solution {
private:
    const int inf = 1e8;

public: 
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();

        if(amount == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // base case => x = 0 => t (amount) can be anything 
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) dp[0][t] = t / coins[0];
            else dp[0][t] = inf;         
        }


        for(int i = 1; i < n; i++) {
            for(int wt = 0; wt <= amount; wt++) {
                // now decide to take the coin or not 
                int not_take = dp[i - 1][wt];
                int take = inf;
                if(wt >= coins[i]) take = 1 + dp[i][wt - coins[i]];

                dp[i][wt] = min(take, not_take);
            }
        }

        int res = dp[n - 1][amount];

        if(res >= inf) return -1;
        else return res;
    }
};


// The above solution can be space optimised to O(N)

// ===================================================== Space Optimised Solution ==========================================================================

class SpaceOptimisedSolution {
private: 
    const int inf = 1e8;

public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();

        if(amount == 0) return 0;

        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        // prev indicates [i-1] row and the curr indicates [i] row

        // base case => index = 0, for all amount t
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) prev[t] = t / coins[0];
            else prev[t] = inf;
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                // decide whether we choose to use this coin or not  
                int not_take = prev[t];
                int take = inf;
                if(t >= coins[i]) take = 1 + curr[t - coins[i]];

                curr[t] = min(take, not_take);
            }

            prev = curr;
        }

        // after all the iterations prev denotes n-1 th row 
        int res = prev[amount];

        if(res >= inf) return -1;
        else return res;

    }
};