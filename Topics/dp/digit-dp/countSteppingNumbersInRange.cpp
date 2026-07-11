// ================================================================ digit dp ==========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-stepping-numbers-in-range/description/

// ==================================== Very Important Question =======================================================================

/* Explanation: digit dp 
   remember we consider leading zeros to consider cases where we also add in numbers with less digits than given upper bound 
   since in this question we need the prev digit to place two numbers prev+1 or prev-1 
   so we need a state for prev and for dealing the case of prev can be done using prev = 10 

   tight to handle the upper bound condition 
   recurrence has three states => f(pos, tight, prev)

   we must first of all deal with 2 cases => prev = 10 (number hasnt started yet => leading zeros)
   prev = 10 => 1. place 0 and continue with leading zero 
                2. start a the number by placing any number within limit and tight check 

   prev != 10 => means number has already started 
                1. place prev+1 if <= 9 and <= limit with the tight check 
                2. place prev-1 if >= 0 and <= limit and tight check 
*/

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    int dp[101][2][11];
    // dp[pos][tight][prev]

    int f(int pos, int tight, int prev, string &num) {
        // base case
        if(pos == num.length()) return 1;

        if(dp[pos][tight][prev] != -1) return dp[pos][tight][prev];

        // try all combinations of numbers 
        ll res = 0;
        int limit = (tight) ? num[pos]-'0' : 9;

        if(prev == 10) {
            // number has not yet started => leading zeros 
            res = (res + f(pos+1, 0, 10, num)) % MOD;

            // anathor option is to start the number (place any number from 1 to limit)
            for(int d = 1; d <= limit; d++) {
                int new_tight = tight && (d == num[pos]-'0');
                res = (res + f(pos+1, new_tight, d, num)) % MOD;
            }
        } 
        else {
            // number has started so prev exists so we either place prev-1 or prev+1 if exists 
            if(prev+1 <= 9 && prev+1 <= limit) {
                int new_tight = tight && (prev+1 == num[pos]-'0');
                res = (res + f(pos+1, new_tight, prev+1, num)) % MOD;
            }

            if(prev-1 >= 0 && prev-1 <= limit) {
                int new_tight = tight && (prev-1 == num[pos]-'0');
                res = (res + f(pos+1, new_tight, prev-1, num)) % MOD;
            }
        }

        return dp[pos][tight][prev] = res % MOD;
    }

    string subtract_one(string &s) {
        int n = s.length();

        for(int i = n-1; i >= 0; i--) {
            if(s[i] > '0') {
                // just subtract one and then done 
                s[i]--;
                return s;
            }

            // this digit is 0 so substract to make 9 
            s[i] = '9';
        }

        // remove the leading zero 
        return s.substr(1);
    }

public:
    int countSteppingNumbers(string &low, string &high) {
        memset(dp, -1, sizeof(dp));
        // start with tight = 1 and no prev case = 10
        ll res_High = f(0, 1, 10, high);

        string low_minus_one = subtract_one(low);

        memset(dp, -1, sizeof(dp));

        ll res_Low = f(0, 1, 10, low_minus_one);

        return (int)(res_High - res_Low + MOD) % MOD;
    }
};