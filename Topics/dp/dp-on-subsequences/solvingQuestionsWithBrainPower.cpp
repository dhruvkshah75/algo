// ==================================================== dp on Subsequences ==============================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int,int>
#define pll pair<ll,ll>

// question link: https://leetcode.com/problems/solving-questions-with-brainpower/description/

/* Explaination: Classic 0-1 Knapsack Variant with easier constraints 
   Recurrence: f(ind) 
   At each point u have 2 choices 
   1. dont solve the current question and earn 0 points and move on ind+1 th question 
   2. solve the current question and then skip brainpower no of questions and earn points[i]
   return the max points earn out of both these ways 

   f(ind) => maximum points earned till the ind th question 
*/

// =====================================================================================================================================================
//                                                  Top Down Approach Memoization dp 
// =====================================================================================================================================================

typedef long long ll;

class Solution {
private: 
    static constexpr int N = 1e5;
    ll dp[N];

    ll f(int ind, vector<vector<int>> &q, int n) {
        // base case: index out of bounds (all q finished)
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        // 0-1 knapsack 
        auto p = q[ind][0], j = q[ind][1];

        ll not_solve = f(ind+1, q, n);
        ll solve = p + f(ind+j+1, q, n);

        return dp[ind] = max(solve, not_solve);
    }


public:
    ll mostPoints(vector<vector<int>>& q) {
        int n = q.size();

        memset(dp, -1, sizeof(dp));

        // starting from the 0th question to get the max points 
        return f(0, q, n);
    }
};
// time complexity = O(N) and space complexity = O(N) + O(N)


// =====================================================================================================================================================
//                                                  Bottom up Approach Tabulation dp 
// =====================================================================================================================================================

// pretty basic 0-1 knapsack variant 

typedef long long ll;

class Solution {
private: 
   /*
    static constexpr int N = 1e5;
    ll dp[N];

    ll f(int ind, vector<vector<int>> &q, int n) {
        // base case: index out of bounds (all q finished)
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        // 0-1 knapsack 
        auto p = q[ind][0], j = q[ind][1];

        ll not_solve = f(ind+1, q, n);
        ll solve = p + f(ind+j+1, q, n);

        return dp[ind] = max(solve, not_solve);
    } */

public:
    ll mostPoints(vector<vector<int>>& q) {
        int n = q.size();

        ll dp[n+1];
        // dp[ind] = max points earned solving any question in suffix[ind...n]
        
        // base case: ind >= n => dp = 0
        dp[n] = 0;

        for(int ind = n-1; ind >= 0; ind--) {
            // apply 0-1 knapsack => solving the question or not 
            ll p = q[ind][0], j = q[ind][1];

            ll not_solve = dp[ind+1];
            ll solve = p + ((ind+j+1 <= n) ? dp[ind+j+1] : 0);
            dp[ind] = max(solve, not_solve);
        }

        // return => dp[0] = max points for solving any question in q[0...n]
        return dp[0];
    }
};