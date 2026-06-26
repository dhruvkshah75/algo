// =========================================================== state-machine dp ==================================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/perfect-squares/description/

/* Explaination: 
   Store all the perfect squares <= 1e4
   then start from the last square then use unbounded knapsack (take or not_take)
   a number can always be return in terms of perfect squares as 1 is a perfect square 
   The options that we would have are not_take the current perect square or take it (infinite supply)
*/

// ================================================================================================================================================================
//                                                      Memoization Top Down Approach dp
// ================================================================================================================================================================

class Solution {
private: 
    vector<int> perfect_sq;

    void precompute(int n) {
        // precompute all the perfect squares till n
        for(int i = 1; i * i <= n; i++) {
            perfect_sq.push_back(i * i);
        }
    }

    int f(int ind, int num, vector<vector<int>> &dp) {
        // base case: num is exhausted 
        if(num == 0) return 0;

        // base case: last perfect square reached => 1 
        if(ind == 0) return num / 1;

        if(dp[ind][num] != -1) return dp[ind][num];

        // explore all cases of taking the current perfect square and not taking 
        int not_take = f(ind-1, num, dp);
        int take = 1e8;
        if(num >= perfect_sq[ind]) take = 1 + f(ind, num-perfect_sq[ind], dp);

        return dp[ind][num] = min(take, not_take);
    } 

public:
    int numSquares(int n) {
        // precompute all the required perfect squares
        precompute(n);

        int sz = perfect_sq.size();

        vector<vector<int>> dp(sz, vector<int>(n+1, -1));

        return f(sz-1, n, dp);
    }
};

// ============================================================================================================================================
//                                                  Bottom Up Approach Tabulation 
// ============================================================================================================================================

class Solution {
private: 
    vector<int> perfect_sq;

    void precompute(int n) {
        // precompute all the perfect squares till n
        for(int i = 1; i * i <= n; i++) {
            perfect_sq.push_back(i * i);
        }
    }

    /*
    int f(int ind, int num, vector<vector<int>> &dp) {
        // base case: num is exhausted 
        if(num == 0) return 0;

        // base case: last perfect square reached => 1 
        if(ind == 0) return num / 1;

        if(dp[ind][num] != -1) return dp[ind][num];

        // explore all cases of taking the current perfect square and not taking 
        int not_take = f(ind-1, num, dp);
        int take = 1e8;
        if(num >= perfect_sq[ind]) take = 1 + f(ind, num-perfect_sq[ind], dp);

        return dp[ind][num] = min(take, not_take);
    } 
    */

public:
    int numSquares(int n) {
        // precompute all the required perfect squares
        precompute(n);

        int sz = perfect_sq.size();

        vector<vector<int>> dp(sz, vector<int>(n+1, 0));

        // base case: num = 0
        for(int ind = 0; ind < sz; ind++) 
            dp[ind][0] = 0;

        // base case: ind = 0 => dp = num
        for(int j = 1; j <= n; j++) 
            dp[0][j] = j;

        
        for(int ind = 1; ind < sz; ind++) {
            for(int num = 0; num <= n; num++) {
                // explore all cases => unbounded knapsack
                int not_take = dp[ind-1][num];
                int take = 1e8;
                if(num >= perfect_sq[ind]) take = 1 + dp[ind][num-perfect_sq[ind]];

                dp[ind][num] = min(take, not_take);
            }
        }

        return dp[sz-1][n];
    }
};


// This solution can be space Optimised to get O(N) space complexity

// ==============================================================================================================================================
//                                              Space Optimised Tabulation dp
// ==============================================================================================================================================

class SpaceOptimisedSolution {
private: 
    vector<int> perfect_sq;

    void precompute(int n) {
        // precompute all the perfect squares till n
        for(int i = 1; i * i <= n; i++) {
            perfect_sq.push_back(i * i);
        }
    }

    /*
    int f(int ind, int num, vector<vector<int>> &dp) {
        // base case: num is exhausted 
        if(num == 0) return 0;

        // base case: last perfect square reached => 1 
        if(ind == 0) return num / 1;

        if(dp[ind][num] != -1) return dp[ind][num];

        // explore all cases of taking the current perfect square and not taking 
        int not_take = f(ind-1, num, dp);
        int take = 1e8;
        if(num >= perfect_sq[ind]) take = 1 + f(ind, num-perfect_sq[ind], dp);

        return dp[ind][num] = min(take, not_take);
    } 
    */

public:
    int numSquares(int n) {
        // precompute all the required perfect squares
        precompute(n);

        int sz = perfect_sq.size();

        vector<int> prev(n+1, 0), curr(n+1, 0);

        // base case: num = 0 for all ind

        // base case: ind = 0 => dp = num
        for(int j = 0; j <= n; j++) 
            prev[j] = j;

        for(int ind = 1; ind < sz; ind++) {
            // base case: num = 0 => dp = 0
            curr[0] = 0;
            for(int num = 0; num <= n; num++) {
                // explore all cases => unbounded knapsack
                int not_take = prev[num];
                int take = 1e8;
                if(num >= perfect_sq[ind]) take = 1 + curr[num-perfect_sq[ind]];

                curr[num] = min(take, not_take);
            }
            swap(prev, curr);
        }

        // after all the iterations => prev => dp[sz-1]
        return prev[n];
    }
};
