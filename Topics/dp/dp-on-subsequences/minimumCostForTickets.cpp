// ========================================================== dp on subsequences ======================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/minimum-cost-for-tickets/description/

/* Explaination: Pretty simple question on dp on subsequences 
   At each day we have 3 choices to buy tickets 
   and with each choice we go to the next day (depending on the type of pass)
   we can use upper bound to get the next day we must move onto to
   Reccurence => f(ind) = min dollors spent to travel on each 
*/

#define all(x, y) x.begin()+y, x.end()

class Solution {
private: 
    static constexpr int N = 365;
    int dp[N];

    int f(int ind, vector<int> &days, vector<int> &costs) {
        // base case: ran out of days
        if(ind >= (int)days.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        // explore all possible cases: 1-day pass, 7-day pass or 30-day pass
        // case 1: 1 day pass
        int min_cost = costs[0] + f(ind+1, days, costs);

        // case 2: 7 day pass
        auto it1 = upper_bound(all(days, ind), days[ind]+7-1);
        int nxt1 = distance(days.begin(), it1);

        min_cost = min(min_cost, costs[1] + f(nxt1, days, costs));

        // case 3: 30 days pass 
        auto it2 = upper_bound(all(days, ind), days[ind]+30-1);
        int nxt2 = distance(days.begin(), it2);

        min_cost = min(min_cost, costs[2] + f(nxt2, days, costs));

        return dp[ind] = min_cost;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        memset(dp, -1, sizeof(dp));

        return f(0, days, costs);
    }
};