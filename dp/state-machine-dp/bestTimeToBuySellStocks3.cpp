// ============================================================== state machine dp ========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

/* Explaination: The logic is the same as best time to buy and sell stock 3
   We can use state => hold 
   We can only have 2 Buys and 2 stocks At most => (Buy 1 -> Sell 1) -> (Buy 2 -> Sell 2)

   Buying a stock => means -prices[i] and selling the stock means +prices[i]

   introduce a new state called cap => allowed transactions left 
   recurrence => f(ind, buy, cap) 
   Note: Reduce the cap only when the current holding stock is sold 

   stop buying when the cap reaches 0 (2 transactions done)

   This question essentially introduces a new cap state and just a extension of best-time-to-buy-and-sell-stock-2
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecurrsiveSolution {
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // dp[ind][buy][cap] => buy = {0, 1} and cap = {1, 2}

        // at the start of the 0th day => 2 transactions are left and we can buy any stock 
        return f(0, 1, 2, prices, dp);
    }
};

// =========================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int dp[n+1][2][3];
        // dp[ind][buy][cap] => buy = {0, 1} and cap = {1, 2}

        // base cases: ind is out of bounds
        for(int j = 0; j < 2; j++) 
            for(int c = 0; c < 3; c++) 
                dp[n][j][c] = 0;

        // base case: cap = 0 => dp = 0
        for(int i = 0; i <= n; i++) 
            for(int j: {0, 1}) 
                dp[i][j][0] = 0;

        
        // in memo => i goes from 0 to n-1 
        for(int i = n-1; i >= 0; i--) {
            for(int buy: {0, 1}) {
                for(int cap: {1, 2}) {
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
        
        // return the max profit with at most 2 transactions on the 0th day with buy = 1 => freedom to buy anything 
        return max(dp[0][1][1], dp[0][1][2]);
    }
};

// This solution can be space optimised to constant space rather than O(6 * N) space 

// ===============================================================================================================================================================
//                                                     Space Optimised Bottom up approach (Tabulation) dp
// ===============================================================================================================================================================

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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int ahead[2][3], curr[2][3];
        // ahead => dp[i+1] and curr => dp[i]
        // dp[ind][buy][cap] => buy = {0, 1} and cap = {1, 2}

        // base cases: ind is out of bounds
        for(int j = 0; j < 2; j++) 
            for(int c = 0; c < 3; c++) 
                ahead[j][c] = 0;

        // base case: cap = 0 => dp = 0
        ahead[0][0] = ahead[1][0] = 0;
  
        // in memo => i goes from 0 to n-1 
        for(int i = n-1; i >= 0; i--) {
            // for cap = 0 => dp = 0
            curr[0][0] = curr[1][0] = 0;

            for(int buy: {0, 1}) {
                for(int cap: {1, 2}) {
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
        
        // return the max profit with at most 2 transactions on the 0th day with buy = 1 => freedom to buy anything 
        return max(ahead[1][1], ahead[1][2]);
    }
};