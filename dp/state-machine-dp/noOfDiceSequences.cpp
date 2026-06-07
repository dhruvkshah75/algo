// ==================================================== state-machine-dp =========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/number-of-distinct-roll-sequences/description/

/* Explaination: state machine dp => we define all needed states 
   Start by placing all possible dice configurations by satisfying the 2 mentioned conditions 
   1. placing at the xth position => __gcd(x, prev1) = 1
   2. x must be not be same till 2 prev positions => x != prev1 and x != prev2

   f(ind, prev1, prev2) => each state is denoted by these 3 indexes 
   ind => which number in the sequence are we at 
   prev1 and prev2 => placed values in the past 
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach Memoization dp
// ==================================================================================================================================================================

typedef long long ll;

class Solution {
private: 
    const int MOD = 1e9+7;
    static constexpr int N = 1e4;

    int dp[N][7][7];

    int f(int ind, int prev1, int prev2, int n) {
        // base case: if successfully placed all the dices 
        if(ind == n) return 1;

        if(dp[ind][prev1][prev2] != -1) return dp[ind][prev1][prev2];

        // try all possible combinations of dice rolls 
        ll cnt = 0;

        for(int dice = 1; dice <= 6; dice++) {
            // dice = x is allowed if it satisfies 2 cases 
            bool gcd_ok = (prev1 == 0) || (__gcd(dice, prev1) == 1);

            if(gcd_ok && dice != prev1 && dice != prev2) {
                cnt = (cnt + f(ind+1, dice, prev1, n)) % MOD; 
            }
        }

        return dp[ind][prev1][prev2] = cnt % MOD;
    }

public:
    int distinctSequences(int n) {

        // -1 cant be in index in vector => 0 is the no prev case 
        // dp[ind][prev1][prev2] => prev1 and prev2 => [1,2...6] and 0 is the invalid dice 
        memset(dp, -1, sizeof(dp));

        return f(0, 0, 0, n);
    }
};
// Space Complexity = O(N * 7 * 7) + O(N) (Auxiliary stack space)


// ============================================================================================================================================
//                                                  Bottom Up Approach Tabulation dp
// ============================================================================================================================================

typedef long long ll;

class Solution {
private: 
    const int MOD = 1e9+7;
    /*
    int f(int ind, int prev1, int prev2, int n, vector<vector<vector<int>>> &dp) {
        // base case: if successfully placed all the dices 
        if(ind == n) return 1;

        if(dp[ind][prev1][prev2] != -1) return dp[ind][prev1][prev2];

        // try all possible combinations of dice rolls 
        ll cnt = 0;

        for(int dice = 1; dice <= 6; dice++) {
            // dice = x is allowed if it satisfies 2 cases 
            bool gcd_ok = (prev1 == 0) || (__gcd(dice, prev1) == 1);

            if(gcd_ok && dice != prev1 && dice != prev2) {
                cnt = (cnt + f(ind+1, dice, prev1, n, dp)) % MOD; 
            }
        }

        return dp[ind][prev1][prev2] = cnt % MOD;
    } */

public:
    int distinctSequences(int n) {
        // -1 cant be in index in vector => 0 is the no prev case 

        int dp[n+1][7][7];
        // dp[ind][prev1][prev2] => prev1 and prev2 => [1,2...6] and 0 is the invalid dice 

        memset(dp, 0, sizeof(dp));

        // base case: ind = n (sequence completed) dp = 1
        for(int j = 0; j <= 6; j++) 
            for(int k = 0; k <= 6; k++) 
                dp[n][j][k] = 1;

        // memo => ind = 0...n 
        for(int ind = n-1; ind >= 0; ind--) {
            for(int prev1 = 0; prev1 <= 6;  prev1++) {
                for(int prev2 = 0; prev2 <= 6; prev2++) {
                    // try out all possible combinations of dice rolls 
                    ll cnt = 0;

                    for(int dice = 1; dice <= 6; dice++) {
                        // dice = x is allowed if it satisfies 2 cases 
                        bool gcd_ok = (prev1 == 0) || (__gcd(dice, prev1) == 1);

                        if(gcd_ok && dice != prev1 && dice != prev2) {
                            cnt = (cnt + dp[ind+1][dice][prev1]) % MOD;
                        }
                    }

                    dp[ind][prev1][prev2] = cnt;
                }
            }
        }

        // memo => f(0, 0, 0)
        return dp[0][0][0];
    }
};
// Space Complexity = O(49 * N), Time Complexity = O(343 * N)


// ====================================================================================================================================================
//                                                 Space Optimised Tabulation dp
// ====================================================================================================================================================

typedef long long ll;

class SpaceOptimisedSolution {
private: 
    const int MOD = 1e9+7;
    /*
    int f(int ind, int prev1, int prev2, int n, vector<vector<vector<int>>> &dp) {
        // base case: if successfully placed all the dices 
        if(ind == n) return 1;

        if(dp[ind][prev1][prev2] != -1) return dp[ind][prev1][prev2];

        // try all possible combinations of dice rolls 
        ll cnt = 0;

        for(int dice = 1; dice <= 6; dice++) {
            // dice = x is allowed if it satisfies 2 cases 
            bool gcd_ok = (prev1 == 0) || (__gcd(dice, prev1) == 1);

            if(gcd_ok && dice != prev1 && dice != prev2) {
                cnt = (cnt + f(ind+1, dice, prev1, n, dp)) % MOD; 
            }
        }

        return dp[ind][prev1][prev2] = cnt % MOD;
    } */

public:
    int distinctSequences(int n) {
        // -1 cant be in index in vector => 0 is the no prev case 

        vector<vector<int>> ahead(7, vector<int>(7, 0)), curr(7, vector<int>(7, 0));
        // ahead => dp[ind+1] and curr => dp[ind]
        // dp[ind][prev1][prev2] => prev1 and prev2 => [1,2...6] and 0 is the invalid dice 

        // base case: ind = n (sequence completed) dp = 1
        for(int j = 0; j <= 6; j++) 
            for(int k = 0; k <= 6; k++) 
                ahead[j][k] = 1;

        // memo => ind = 0...n 
        for(int ind = n-1; ind >= 0; ind--) {
            for(int prev1 = 0; prev1 <= 6;  prev1++) {
                for(int prev2 = 0; prev2 <= 6; prev2++) {
                    // try out all possible combinations of dice rolls 
                    ll cnt = 0;

                    for(int dice = 1; dice <= 6; dice++) {
                        // dice = x is allowed if it satisfies 2 cases 
                        bool gcd_ok = (prev1 == 0) || (__gcd(dice, prev1) == 1);

                        if(gcd_ok && dice != prev1 && dice != prev2) {
                            cnt = (cnt + ahead[dice][prev1]) % MOD;
                        }
                    }

                    curr[prev1][prev2] = cnt;
                }
            }
            swap(ahead, curr);
        }

        // memo => f(0, 0, 0)
        return ahead[0][0];
    }
};
// Space Complexity = O(49), Time Complexity = O(343 * N)