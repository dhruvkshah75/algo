// ============================================================== state machine dp ========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

/* Explaination: This question is the same as best-time-to-buy-and-sell-stock-ii
   Here at the end of each transaction we just subtract the fee for the transaction 
   
   Recurrence => f(ind, buy) is used where buy = 1 indicates a new stock can be bought 
   and buy = 0 => currently holding a stock and must sell it */

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class Solution {
private: 
    int fee;

    int f(int ind, int buy, vector<int> &pr, vector<vector<int>> &dp) {
        // base case: when index goes out of bounds 
        if(ind == (int)pr.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if(buy) {
            // 1. buy the stock or 2. skip this day 
            profit = max(-pr[ind] + f(ind+1, 0, pr, dp),
                        f(ind+1, buy, pr, dp));
        } 
        else {
            // 1. sell the stock with fee or 2. skip the day 
            profit = max(pr[ind] - fee + f(ind+1, 1, pr, dp),
                        f(ind+1, buy, pr, dp));
        }

        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        this->fee = fee;

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));
        // dp[ind][buy]

        // starting from the 0th day with buy = 1 (can buy stock)
        return f(0, 1, prices, dp);
    }
};
// space complexity = O(2 * N) + O(N) 


// =================================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// =================================================================================================================================================================

class Solution {
private: 
    int fee;

    /*
    int f(int ind, int buy, vector<int> &pr, vector<vector<int>> &dp) {
        // base case: when index goes out of bounds 
        if(ind == (int)pr.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if(buy) {
            // 1. buy the stock or 2. skip this day 
            profit = max(-pr[ind] + f(ind+1, 0, pr, dp),
                        f(ind+1, buy, pr, dp));
        } 
        else {
            // 1. sell the stock with fee or 2. skip the day 
            profit = max(pr[ind] - fee + f(ind+1, 1, pr, dp),
                        f(ind+1, buy, pr, dp));
        }

        return dp[ind][buy] = profit;
    }
    */

public:
    int maxProfit(vector<int>& pr, int fee) {
        int n = pr.size();

        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // dp[ind][buy]

        // base case: ind == n => dp = 0
        dp[n][0] = dp[n][1] = 0;

        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy: {0, 1}) {
                // explore case of buying and selling the stock 
                int profit = 0;

                if(buy) {
                    // 1. buy the stock or 2. skip the day 
                    profit = max(-pr[ind] + dp[ind+1][0], dp[ind+1][buy]);
                }
                else {
                    // 1. sell the stock with the fee or 2. skip the day
                    profit = max(pr[ind] - fee + dp[ind+1][1], dp[ind+1][buy]);
                }

                dp[ind][buy] = profit;
            }
        }

        // starting from the 0th day with buy = 1(can buy the stock)
        return dp[0][1];
    }
};
// space complexity = O(2 * N)

// ====================================================== space optimised solution ===============================================================================

// the above solution can be space optimised each calculation depends on dp[i+1]

class Solution {
private: 
    int fee;

    /*
    int f(int ind, int buy, vector<int> &pr, vector<vector<int>> &dp) {
        // base case: when index goes out of bounds 
        if(ind == (int)pr.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if(buy) {
            // 1. buy the stock or 2. skip this day 
            profit = max(-pr[ind] + f(ind+1, 0, pr, dp),
                        f(ind+1, buy, pr, dp));
        } 
        else {
            // 1. sell the stock with fee or 2. skip the day 
            profit = max(pr[ind] - fee + f(ind+1, 1, pr, dp),
                        f(ind+1, buy, pr, dp));
        }

        return dp[ind][buy] = profit;
    }
    */

public:
    int maxProfit(vector<int>& pr, int fee) {
        int n = pr.size();

        vector<int> ahead(2, 0), curr(2, 0);
        // ahead => dp[i+1] and curr => dp[i]
        // dp[ind][buy]

        // base case: ind == n => dp = 0
        ahead[0] = ahead[1] = 0;

        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy: {0, 1}) {
                // explore case of buying and selling the stock 
                int profit = 0;

                if(buy) {
                    // 1. buy the stock or 2. skip the day 
                    profit = max(-pr[ind] + ahead[0], ahead[buy]);
                }
                else {
                    // 1. sell the stock with the fee or 2. skip the day
                    profit = max(pr[ind] - fee + ahead[1], ahead[buy]);
                }

                curr[buy] = profit;
            }

            swap(ahead, curr);
        }

        // starting from the 0th day with buy = 1(can buy the stock)
        // after all the iterations ahead => dp[0]
        return ahead[1];
    }
};
// Space complexity = O(1) and Time Complexity = O(2 * N)