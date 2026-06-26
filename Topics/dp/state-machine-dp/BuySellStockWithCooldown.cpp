// ============================================================== state machine dp ========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

// Very straight forward question based on a single state dp 

/* Explaination: similar to best time to buy and sell stock 2
   here after selling the stock => skip the next day 

   reccurrence = f(ind, buy) 
   buy = 1 => buy is allowed (not holding any stock)
   buy = 0 => sell is allowed (holding the stock bought earlier)
   buying => - prices and selling => +price */

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class Solution {
private:
    int n;
    const static int N = 1e5 + 10;

    int dp[N][2];

    int f(int ind, int buy, vector<int> &prices) {
        // base case: index gone out of bounds 
        if(ind >= n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        // explore case of buying and selling 
        int profit = 0;

        if(buy) {
            // 1. buy the stock or 2. dont do anything 
            profit = max(-prices[ind] + f(ind+1, 0, prices),
                        f(ind+1, buy, prices));
        }
        else {
            // 2. sell the stock with 1 day cooldown or 2. dont sell 
            profit = max(prices[ind] + f(ind+2, 1, prices),
                        f(ind+1, buy, prices));
        }

        return dp[ind][buy] = profit;
    }


public:
    int maxProfit(vector<int>& prices) {
        int n = this->n = prices.size();

        memset(dp, -1, sizeof(dp));

        // profit earned starting at the 0th day with buy = 1 (not holding any stock)
        return f(0, 1, prices);
    }
};

// =========================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

class Solution {
private:
    /*
    int n;
    const static int N = 1e5 + 10;
    int dp[N][2];

    int f(int ind, int buy, vector<int> &prices) {
        // base case: index gone out of bounds 
        if(ind >= n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        // explore case of buying and selling 
        int profit = 0;

        if(buy) {
            // 1. buy the stock or 2. dont do anything 
            profit = max(-prices[ind] + f(ind+1, 0, prices),
                        f(ind+1, buy, prices));
        }
        else {
            // 2. sell the stock with 1 day cooldown or 2. dont sell 
            profit = max(prices[ind] + f(ind+2, 1, prices),
                        f(ind+1, buy, prices));
        }

        return dp[ind][buy] = profit;
    }
    */

public:
    int maxProfit(vector<int>& pr) {
        int n = pr.size();

        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        // dp[ind][buy]

        // base case: i >= n (invalid index) dp = 0 

        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy: {0, 1}) {
                int profit = 0;

                if(buy) {
                    // 1. buy the stock or 2. skip the day 
                    profit = max(-pr[ind] + dp[ind+1][0], dp[ind+1][buy]);
                }
                else {
                    // 1. sell the stock with cooldown or 2. skip the day 
                    profit = max(pr[ind] + dp[ind+2][1], dp[ind+1][buy]);
                }

                dp[ind][buy] = profit;
            }
        }

        // profit earned starting at the 0th day with buy = 1 (not holding any stock)
        return dp[0][1];
    }
};
// Time Complexity = O(2*N) and Space Complexity = O(2*N)

// space complexity can be reduced to O(1)
// space optimised solution using ahead1 => dp[ind+1], ahead2 => dp[ind+2], curr => dp[ind]