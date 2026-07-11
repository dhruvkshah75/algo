// =============================================== digit dp + bitmask dp ==============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/numbers-with-repeated-digits

// ================================================== very important dp question ==============================================================

/* Explanation: digit + bitmask dp (5d dp)
   here we must form such numbers which have at least one repeated digit 
   so we must know how many numbers have been used till now => use a bitmask for that 
   a bitmask with 10 states => ith bit indicates whether the digit i is previously used or not
   so example if the bitmask is 
   numbers => 9 8 7 6 5 4 3 2 1 0
   bitmask => 0 0 1 0 0 1 0 0 1 0
   This means 1 is used, 4 is used and 7 is used 
   so when we place a number and check if that bit is set in the mask or not => if yes then at least one digit got repeated 
   
   the mask has 10 bits => max value is 2^10-1 = 1023 states at max 

   also deal with the case of leading zeros separately as leading zeros dont count to the case of multiple digits 
   or 0 appearing 
   if the number hasnt been started then mask remains 0  

   pos → current digit position
   tight → whether we're still matching the prefix of n
   started → whether we've placed the first non-leading-zero digit
   mask → which digits (0–9) have already appeared
   repeated → whether we've already seen a repeated digit (flaf condition just to check if condition in the question fullfilled or not)
*/

class Solution {
private:
    string num;
    int dp[10][2][2][1024][2];
    // dp[pos][tight][started][mask][repeated]

    int f(int pos, int tight, int started, int mask, int repeated) {
        // base case: only return 1 when repeated condition is true 
        if(pos == num.length()) return repeated;

        if(dp[pos][tight][started][mask][repeated] != -1) 
            return dp[pos][tight][started][mask][repeated];

        // try forming all numbers 
        int res = 0;
        int limit = (tight) ? num[pos]-'0' : 9;

        if(!started) {
            // if number has leading zero => either continue with leading zero or start the number 
            res += f(pos+1, 0, 0, 0, 0);

            // start the number => place d = 1 to limit 
            for(int d = 1; d <= limit; d++) {
                int new_tight = tight && (d == num[pos]-'0');

                // using this d => set the dth bit in mask 
                int new_mask = mask | (1 << d);
                res += f(pos+1, new_tight, 1, new_mask, 0);
            }
        }
        else {
            // number has already started then place any number between 0 to limit 
            // and check if d already use => if used then one digit repeated so set repeated 
            for(int d = 0; d <= limit; d++) {
                int new_tight = tight && (d == num[pos]-'0');

                // check the dth bit of current mask 
                int bit = (mask >> d) & 1;

                if(bit) {
                    // if bit is set then make repeated = 1 (already set so no changes to the mask)
                    res += f(pos+1, new_tight, 1, mask, 1);
                }
                else {
                    int new_mask = mask | (1 << d);
                    // since this digit has not appeared to set the dth bit and use the prev value of repeated
                    res += f(pos+1, new_tight, 1, new_mask, repeated);
                }
            }
        }

        return dp[pos][tight][started][mask][repeated] = res;
    }

public:
    int numDupDigitsAtMostN(int n) {
        num = std::to_string(n);

        memset(dp, -1, sizeof(dp));

        // start with tight = 1, started = 0, mask = 0, repeated = 0(no digits are repeated yet)
        return f(0, 1, 0, 0, 0);
    }
};