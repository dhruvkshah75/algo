// ============================================ digit dp ============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/

/* Explanation: digit dp 
   here we must pickup the numbers from the set (each number can be picked multiple times) 
   and note that we also need one more state => started to handle the case of leading zeros i.e.
   a number with less digits than n
   so when started = 0 => we are allowed to not pick any number from the set and add leading zeros 

   so there are 3 states => pos, tight, started 
   start by building numbers from started = 0 and then use the digits of the given the vector 
*/

class Solution {
private: 
    int dp[10][2][2];
    // dp[pos][tight][started]
    string num;

    int f(int pos, int tight, int started, vector<string> &digits) {
        // base case: all positions of the string num is fullfilled => skip the entire number = 0
        if(pos == num.length()) return started;

        if(dp[pos][tight][started] != -1) return dp[pos][tight][started];

        // try building all numbers 
        int res = 0;
        int limit = (tight) ? num[pos]-'0' : 9;

        if(!started) {
            // can only place a leading zero if number is not started 
            // when leading zero is placed then tight doesnt matter (number we are forming has less digits)
            res += f(pos+1, 0, 0, digits);
        }
        
        // number can be or is already started 
        for(int i = 0; i < digits.size(); i++) {
            int digit = digits[i][0]-'0';

            // cannot use the digits[i] if exceeds limit 
            if(digit > limit) continue;

            // either the number is started or we start the number 
            int newTight = tight && (digits[i][0] == num[pos]) ? 1 : 0;

            res += f(pos+1, newTight, 1, digits);
        }
        
        return dp[pos][tight][started] = res;
    }

public:
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        num = std::to_string(n);

        memset(dp, -1, sizeof(dp));

        // when calling => number is not started and tight = 1 
        return f(0, 1, 0, digits);
    }
};