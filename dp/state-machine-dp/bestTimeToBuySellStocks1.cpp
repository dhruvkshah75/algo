// ============================================================== state machine dp ========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// Pretty simple question not much to do with dp 

/* Explaination: earn maximum profit => buy on some day and then sell it on some day to get maximum profit 
   How to approach this question

   if i sell the stock on the ith day then i will definitely would have bought the stock on the some day 
   day [1:i-1] with the minimum price

   At the ith iteration keep the track of the min price of the stock and then compare the profit on selling the stock on the ith day 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();  

        int res = 0;
        int min_price = prices[0];

        for(int i = 1; i < n; i++) {
            // if we found a better profit case 
            res = max(res, prices[i] - min_price);
            // update the min price for the next iteration
            min_price = min(min_price, prices[i]);
        }

        return res;
    }
};