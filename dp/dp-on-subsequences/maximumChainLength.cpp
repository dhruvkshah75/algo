#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/maximum-length-of-pair-chain/description/

/* Explanation: knapsack variant dp 
   This question also involves the concept of take, not take 
   we can not take the current pair and move to the next index or 
   the other option is to take the current chain and move to the next index j
   such that j is the upper bound of j on the value of b 
   pair 1 = [a, b] and pair 2 = [c, d] such that b < c (c can be found out using upper bound)

   Recurrence => f(ind) = max number of pairs taken in the chain in the suffix [ind...n]

   Question is very similar to Maximum profit in job scheduling 
   => uses the exact same concept of knapsack + binary search to get the next index 
*/

class Solution {
private:
    static constexpr int N = 1e3;
    int dp[N];

    int ub(int x, vector<vector<int>> &pairs) {
        // if no upper bound return n (out of bounds)
        int n = pairs.size();
        int low = 0, high = n-1, res = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(x < pairs[mid][0]) {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return res;
    }

    int f(int ind, int n, vector<vector<int>> &pairs) {
        // base case: all pairs of chain are processed 
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        // try cases of 0-1 knapsack 
        int not_take = f(ind+1, n, pairs);

        int nxt = ub(pairs[ind][1], pairs);
        int take = 1 + f(nxt, n, pairs);

        return dp[ind] = max(take, not_take);
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), [&](const vector<int> &a, const vector<int> &b){
            // sort ascending on left value of pairs
            return a[0] < b[0];
        });

        memset(dp, -1, sizeof(dp));

        return f(0, n, pairs);
    }
};