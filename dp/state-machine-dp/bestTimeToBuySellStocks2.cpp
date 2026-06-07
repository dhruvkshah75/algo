// ============================================================== state machine dp ========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// Important Question => this involves the use of state = buy = {0, 1} to make desicion 

/* Explaination: 
   At the same time i can only hold a single stock 
   So in recursion we can choose to buy the stock if we dont hold anything and sell it on some day with profit (> 0)
   or sell it on some further day => explore all the possibilities => this is why we use recursion 
   
   Write the recurrence:
   1. Express everything in terms of indices => f(ind, state) 
      At each day we must have know if we alreadt have bought a stock or not are we allowed to buy the stock or not 
      f(ind, buy) => buy = 0 => we cannot buy the stock as we already hold a stock 
                  => buy = 1 => we are allowed buy the stock if we want to 

   2. Explore all possible ways for that day 
   3. Take the maximum of all profits of all the ways 

   Start from ind = 0 (from the start) => f(ind = 0, buy = 1) => we have the liberty to buy the stock 
   Buy => means we are adding -prices[i] and sell means adding to the profit
   buy_stock = -prices[i] and sell_stock = +prices[i]
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class Solution {
private:
    int f(int x, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        // base case: all days exhausted  
        if((size_t)x == prices.size()) return 0;

        if(dp[x][buy] != -1) return dp[x][buy];

        // explore all possible ways 
        int profit = 0;

        if(buy == 1) {
            // buy = 1 => we are allowed to buy the stock
            // => either buy the stock or dont buy the stock (buy or dont buy)
            profit = max(
                -prices[x] + f(x+1, 0, prices, dp),      // buy stock 
                f(x+1, 1, prices, dp)                    // dont buy stock
            );
        }
        else {
            // buy = 0 => we already hold a stock we either sell the stock or we dont 
            profit = max(
                prices[x] + f(x+1, 1, prices, dp),        // sell stock 
                f(x+1, 0, prices, dp)                     // dont sell stock
            );
        }

        return dp[x][buy] = profit;
    }


public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));
        // dp[ind][buy] => buy = 0 we hold a stock we need to sell it and buy = 1 => free to buy a stock

        // starting from the 1st day we have the liberty to buy the first stock => f(day = 0, buy = 1)
        return f(0, 1, prices, dp);
    }
};



// =========================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================


class Solution {
private:
    /* 
    int f(int x, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        // base case: all days exhausted  
        if((size_t)x == prices.size()) return 0;

        if(dp[x][buy] != -1) return dp[x][buy];

        // explore all possible ways 
        int profit = 0;

        if(buy == 1) {
            // buy = 1 => we are allowed to buy the stock
            // => either buy the stock or dont buy the stock (buy or dont buy)
            profit = max(-prices[x] + f(x+1, 0, prices, dp),      // buy stock 
                       f(x+1, 1, prices, dp));                    // dont buy stock
        }
        else {
            // buy = 0 => we already hold a stock we either sell the stock or we dont 
            profit = max(prices[x] + f(x+1, 1, prices, dp),        // sell stock 
                       f(x+1, 0, prices, dp));                     // dont sell stock
        }

        return dp[x][buy] = profit;
    }
    */

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int dp[n+1][2];
        // dp[ind][buy] => buy = 0 we hold a stock we need to sell it and buy = 1 => free to buy a stock

        // base case: (ind == n) => dp[n][0..1] = 0
        dp[n][0] = dp[n][1] = 0;

        // ind => in memo goes from 0 -> n-1 => reverse in tabulation 

        for(int i = n-1; i >= 0; i--) {
            for(int buy: {0, 1}) {
                // explore all possible ways 
                int profit = 0;

                if(buy == 1) {
                    // either buy the stock or not 
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else {
                    // either sell the stock or not 
                    profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }

                dp[i][buy] = profit;
            }
        }

        // on the 0th day we have the liberty to buy the stock (day = 0 and buy = 1)
        return dp[0][1];
    }
};

// space complexity = O(2 * N)

// This solution can be space optimised to constant space rather than O(N) space 

// ===============================================================================================================================================================
//                                                     Space Optimised Bottom up approach (Tabulation) dp
// ===============================================================================================================================================================

class SpaceOptimisedSolution {
private:
    /* 
    int f(int x, int buy, vector<int> &prices, vector<vector<int>> &dp) {
        // base case: all days exhausted  
        if((size_t)x == prices.size()) return 0;

        if(dp[x][buy] != -1) return dp[x][buy];

        // explore all possible ways 
        int profit = 0;

        if(buy == 1) {
            // buy = 1 => we are allowed to buy the stock
            // => either buy the stock or dont buy the stock (buy or dont buy)
            profit = max(-prices[x] + f(x+1, 0, prices, dp),      // buy stock 
                       f(x+1, 1, prices, dp));                    // dont buy stock
        }
        else {
            // buy = 0 => we already hold a stock we either sell the stock or we dont 
            profit = max(prices[x] + f(x+1, 1, prices, dp),        // sell stock 
                       f(x+1, 0, prices, dp));                     // dont sell stock
        }

        return dp[x][buy] = profit;
    }
    */

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int prev[2], curr[2];
        // prev => dp[i+1] (previously calculated) and curr => dp[i] (current calculation)

        // dp[ind][buy] => buy = 0 we hold a stock we need to sell it and buy = 1 => free to buy a stock

        // base case: (ind == n) => dp[n][0..1] = 0
        prev[0] = prev[1] = 0;

        // ind => in memo goes from 0 -> n-1 => reverse in tabulation 

        for(int i = n-1; i >= 0; i--) {
            for(int buy: {0, 1}) {
                // explore all possible ways 
                int profit = 0;

                if(buy == 1) {
                    // either buy the stock or not 
                    profit = max(-prices[i] + prev[0], prev[1]);
                }
                else {
                    // either sell the stock or not 
                    profit = max(prices[i] + prev[1], prev[0]);
                }

                curr[buy] = profit;
            }

            swap(prev, curr);
        }

        // on the 0th day we have the liberty to buy the stock (day = 0 and buy = 1)
        // after all iterations prev indicates the dp[n] th row 
        return prev[1];
    }
};



