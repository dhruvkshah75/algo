// ========================================================== counting dp or multi state dp =================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/dice-roll-simulation/


/* Explaination: This is counting dp or state machine dp
   Simply run the recursion and keep a track of prev rolled dice and number of times it is rolled 
   rollMax <= 15 and 1 <= dice <= 6

   dp[n][prev_dice][times] = these states can be used to define the recurrence 
   For each dice rolling we have 6 possible options rolling any face on the dice 
   if rolling dice != prev case => we start a new fresh case with times = 1 
   and when the dice rolled = prev case => times + 1 <= rollMax for that face
*/

// ================================================================================================================================================================
//                                                      Memoization Top Down Approach dp
// ================================================================================================================================================================

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;

    static constexpr int N = 5e3;
    int dp[N][7][16];

    int f(int ind, int prev_case, int times, vector<int> &rollMax, int n) {
        // base case: all dices rolled 
        if(ind == n) return 1;

        if(dp[ind][prev_case][times] != -1) return dp[ind][prev_case][times];

        // explore all possible dice rolls for ind th dice 
        ll cnt = 0;

        for(int dice = 1; dice <= 6; dice++) {
            if(prev_case != dice) {
                // rolled a new number as compared to the prev case 
                cnt = (cnt + f(ind+1, dice, 1, rollMax, n)) % MOD;
            }
            else {
                // dice = prev rolled dice (check the rollMax before)
                if(times + 1 <= rollMax[dice-1]) 
                    cnt = (cnt + f(ind+1, dice, times+1, rollMax, n)) % MOD;
            }
        }

        return dp[ind][prev_case][times] = cnt % MOD;
    }

public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // rollMax size is 6 => for each dice face 

        memset(dp, -1, sizeof(dp));

        // start the simulation from the first dice (ind = 0) with no prev case (dice = 0)
        return f(0, 0, 0, rollMax, n);
    }
};
// Space Complexity = O(N * 7 * 16) + O(N), Time Complexity = O(N * 7 * 16 * 6)

// ======================================================================================================================================================
//                                                   Bottom Up Approach tabulation dp
// ======================================================================================================================================================

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;

    /*
    static constexpr int N = 5e3;
    int dp[N][7][16];

    int f(int ind, int prev_case, int times, vector<int> &rollMax, int n) {
        // base case: all dices rolled 
        if(ind == n) return 1;

        if(dp[ind][prev_case][times] != -1) return dp[ind][prev_case][times];

        // explore all possible dice rolls for ind th dice 
        ll cnt = 0;

        for(int dice = 1; dice <= 6; dice++) {
            if(prev_case != dice) {
                // rolled a new number as compared to the prev case 
                cnt = (cnt + f(ind+1, dice, 1, rollMax, n)) % MOD;
            }
            else {
                // dice = prev rolled dice (check the rollMax before)
                if(times + 1 <= rollMax[dice-1]) 
                    cnt = (cnt + f(ind+1, dice, times+1, rollMax, n)) % MOD;
            }
        }

        return dp[ind][prev_case][times] = cnt % MOD;
    }
    */

public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // rollMax size is 6 => for each dice face 

        int dp[n+1][7][16];

        memset(dp, 0, sizeof(dp));

        // base case: ind == n => dp = 1
        for(int j = 1; j <= 6; j++) 
            for(int k = 1; k <= 15; k++) 
                dp[n][j][k] = 1;

        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int prev = 0; prev <= 6; prev++) {
                for(int times = 0; times <= 15; times++) {
                    // explore all possible dice rolls for the ind th dice 
                    ll cnt = 0;

                    for(int dice = 1; dice <= 6; dice++) {
                        if(prev != dice) {
                            // rolled a new number as compared to the prev case 
                            cnt = (cnt + dp[ind+1][dice][1]) % MOD;
                        }
                        else {
                            // dice = prev rolled dice (check the rollMax before)
                            if(times + 1 <= rollMax[dice-1]) 
                                cnt = (cnt + dp[ind+1][dice][times+1]) % MOD;
                        }
                    }

                    dp[ind][prev][times] = cnt % MOD;
                }
            }
        }
        
        // start the simulation from the first dice (ind = 0) with no prev case (dice = 0)
        return dp[0][0][0];
    }
};
// Space Complexity = O(N * 7 * 16), Time Complexity = O(N * 7 * 16 * 6)




// The above Solution can be space optimised 

// =========================================================================================================================================================
//                                                Space Optimised Tabulation dp 
// =========================================================================================================================================================

// array<array<>> => more effecient in space then vectors 

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;

    /*
    static constexpr int N = 5e3;
    int dp[N][7][16];

    int f(int ind, int prev_case, int times, vector<int> &rollMax, int n) {
        // base case: all dices rolled 
        if(ind == n) return 1;

        if(dp[ind][prev_case][times] != -1) return dp[ind][prev_case][times];

        // explore all possible dice rolls for ind th dice 
        ll cnt = 0;

        for(int dice = 1; dice <= 6; dice++) {
            if(prev_case != dice) {
                // rolled a new number as compared to the prev case 
                cnt = (cnt + f(ind+1, dice, 1, rollMax, n)) % MOD;
            }
            else {
                // dice = prev rolled dice (check the rollMax before)
                if(times + 1 <= rollMax[dice-1]) 
                    cnt = (cnt + f(ind+1, dice, times+1, rollMax, n)) % MOD;
            }
        }

        return dp[ind][prev_case][times] = cnt % MOD;
    }
    */

public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // rollMax size is 6 => for each dice face 

        array<array<int,16>,7> ahead, curr;
        // ahead[7][16] => 7 is the outer dimension and 16 is for the inner dimension 
        // ahead => dp[i+1] and curr => dp[i]

        // base case: ind == n => dp = 1
        for(auto &row: ahead) {
            fill(row.begin(), row.end(), 1);
        }
 
        for(int ind = n-1; ind >= 0; ind--) {
            for(int prev = 0; prev <= 6; prev++) {
                for(int times = 0; times <= 15; times++) {
                    // explore all possible dice rolls for the ind th dice 
                    ll cnt = 0;

                    for(int dice = 1; dice <= 6; dice++) {
                        if(prev != dice) {
                            // rolled a new number as compared to the prev case 
                            cnt = (cnt + ahead[dice][1]) % MOD;
                        }
                        else {
                            // dice = prev rolled dice (check the rollMax before)
                            if(times + 1 <= rollMax[dice-1]) 
                                cnt = (cnt + ahead[dice][times+1]) % MOD;
                        }
                    }

                    curr[prev][times] = cnt % MOD;
                }
            }
            swap(ahead, curr);
        }
        
        // start the simulation from the first dice (ind = 0) with no prev case (dice = 0)
        return ahead[0][0];
    }
};
// Space Complexity = O(7 * 16), Time Complexity = O(N * 7 * 16 * 6)