// ============================================================== state machine dp ========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/* Explaination: 
   This is literally the extended version of best-time-to-buy-and-sell-stock-3
   the maximum transactions allowed were at most 2 here it is k 
   The code remains the same just update the loops and dp vector size 
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecursiveSolution {
private:
    int f(int x, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        // base case: when all the days are exhausted 
        if((size_t)x == prices.size()) return 0;

        // cap => number of transactions left becomes 0 
        if(cap == 0) return 0;

        if(dp[x][buy][cap] != -1) return dp[x][buy][cap];

        // explore all cases of buying and selling the stock 
        int profit = 0;

        if(buy) {
            // 1. buy a stock or dont do anything 
            profit = max(-prices[x] + f(x+1, 0, cap, prices, dp), 
                        f(x+1, 1, cap, prices, dp));
        }
        else {
            // 1. sell the stock => reduce the cap 1 as 1 transaction is done or 2. dont sell it 
            profit = max(prices[x] + f(x+1, 1, cap-1, prices, dp),
                        f(x+1, 0, cap, prices, dp));
        }

        return dp[x][buy][cap] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // dp[ind][buy][cap] => buy = {0, 1} and cap = {1, 2, ..., k}
        
        // at the start of the 0th day => 2 transactions are left and we can buy any stock 
        return f(0, 1, k, prices, dp);
    }
};
// space complexity = O(2 * K * N) + O(N) 

// =================================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// =================================================================================================================================================================

class Solution {
private:
    /*
    int f(int x, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        // base case: when all the days are exhausted 
        if((size_t)x == prices.size()) return 0;

        // cap => number of transactions left becomes 0 
        if(cap == 0) return 0;

        if(dp[x][buy][cap] != -1) return dp[x][buy][cap];

        // explore all cases of buying and selling the stock 
        int profit = 0;

        if(buy) {
            // 1. buy a stock or dont do anything 
            profit = max(-prices[x] + f(x+1, 0, cap, prices, dp), 
                        f(x+1, 1, cap, prices, dp));
        }
        else {
            // 1. sell the stock => reduce the cap 1 as 1 transaction is done or 2. dont sell it 
            profit = max(prices[x] + f(x+1, 1, cap-1, prices, dp),
                        f(x+1, 0, cap, prices, dp));
        }

        return dp[x][buy][cap] = profit;
    }
    */

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        int dp[n+1][2][k+1];
        // dp[ind][buy][cap] => buy = {0, 1} and cap = {1, 2, ..., k}
        
        // base cases: ind is out of bounds
        for(int j = 0; j < 2; j++) 
            for(int c = 0; c <= k; c++) 
                dp[n][j][c] = 0;

        // base case: cap = 0 => dp = 0
        for(int i = 0; i <= n; i++) 
            for(int j: {0, 1}) 
                dp[i][j][0] = 0;

        // in memo => i goes from 0 to n-1 and cap goes from k to 0

        for(int i = n-1; i >= 0; i--) {
            for(int buy: {0, 1}) {
                for(int cap = 1; cap <= k; cap++) {
                    // explore all cases of buying and selling the stocks 
                    int profit = 0;

                    if(buy) {
                        // 1. buy the stock, 2. skip this day 
                        profit = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    }
                    else {
                        // 1. sell the stock or 2. skip the day
                        profit = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }

                    dp[i][buy][cap] = profit;
                }
            }
        }

        // since there can be at most k transactions => we must the take the max of all options 
        // return for the 0th day and buy = 1 => ability to buy at first day 
        int res = 0;

        for(int c = 1; c <= k; c++) 
            res = max(res, dp[0][1][c]);

        return res;
    }
};
// space complexity = O(2 * K * N)


// ===============================================================================================================================================================
//                                                     Space Optimised Bottom up approach (Tabulation) dp
// ===============================================================================================================================================================

class SpaceOptimisedSolution {
private:
    /*
    int f(int x, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        // base case: when all the days are exhausted 
        if((size_t)x == prices.size()) return 0;

        // cap => number of transactions left becomes 0 
        if(cap == 0) return 0;

        if(dp[x][buy][cap] != -1) return dp[x][buy][cap];

        // explore all cases of buying and selling the stock 
        int profit = 0;

        if(buy) {
            // 1. buy a stock or dont do anything 
            profit = max(-prices[x] + f(x+1, 0, cap, prices, dp), 
                        f(x+1, 1, cap, prices, dp));
        }
        else {
            // 1. sell the stock => reduce the cap 1 as 1 transaction is done or 2. dont sell it 
            profit = max(prices[x] + f(x+1, 1, cap-1, prices, dp),
                        f(x+1, 0, cap, prices, dp));
        }

        return dp[x][buy][cap] = profit;
    }
    */

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        // ahead => dp[i+1] and curr => dp[i]
        // dp[ind][buy][cap] => buy = {0, 1} and cap = {1, 2, ..., k}
        
        // 1. base case: ind is out of bounds => dp[n] => ahead and 2. base case: cap = 0 => dp = 0

        // in memo => i goes from 0 to n-1 and cap goes from k to 0

        for(int i = n-1; i >= 0; i--) {
            // cap = 0 => dp = 0
            curr[0][0] = curr[1][0] = 0;

            for(int buy: {0, 1}) {
                for(int cap = 1; cap <= k; cap++) {
                    // explore all cases of buying and selling the stocks 
                    int profit = 0;

                    if(buy) {
                        // 1. buy the stock, 2. skip this day 
                        profit = max(-prices[i] + ahead[0][cap], ahead[1][cap]);
                    }
                    else {
                        // 1. sell the stock or 2. skip the day
                        profit = max(prices[i] + ahead[1][cap-1], ahead[0][cap]);
                    }

                    curr[buy][cap] = profit;
                }
            }

            swap(ahead, curr);
        }

        // since there can be at most k transactions => we must the take the max of all options 
        // return for the 0th day and buy = 1 => ability to buy at first day 
        int res = 0;

        for(int c = 1; c <= k; c++) 
            res = max(res, ahead[1][c]);

        return res;
    }
};
// space complexity = O(2 * K) 