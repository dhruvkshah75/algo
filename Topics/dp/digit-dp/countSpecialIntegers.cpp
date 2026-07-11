// ====================================================== digit dp + bitmask dp =======================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-special-integers/description/

/* Explanation: digit dp + bitmasking 
   use a bit mask to keep a track of what digits have been used 
   digits => 9 8 7 6 5 4 3 2 1 
   mask   => 0 1 0 0 0 1 0 0 0
   => this mask means that 8, 4 have already appeared => so we cannot place them again 
   the bitmask value <= 1024

   question is same as number with repeated digits 
   (link: https://leetcode.com/problems/numbers-with-repeated-digits/description/)

   dp states => (pos, tight, started, mask)
   started is needed as the leading zeros arent counting in duplicates 
   when started = 0 (leading zeros) => means mask remains 0
*/

class Solution {
private:
    string num;
    int dp[10][2][2][1024];

    int f(int pos, int tight, int started, int mask) {
        // base case: 0 is not to be counted => range = [1, n]
        if(pos == num.length()) return started;

        if(dp[pos][tight][started][mask] != -1) 
            return dp[pos][tight][started][mask];

        int res = 0;
        int limit = (tight) ? num[pos]-'0' : 9;

        if(!started) {
            // continue with leading zeros => mask remains 0, tight becomes 0 
            res += f(pos+1, 0, 0, 0);

            // start the number by placing numbers [1...limit]
            for(int d = 1; d <= limit; d++) {
                int new_tight = tight && (d == num[pos]-'0');

                // set the dth bit in mask 
                int new_mask = mask | (1 << d);
                res += f(pos+1, new_tight, 1, new_mask);
            }
        }
        else {
            // number has already started then only use digit d (if not already used)
            // 0 can also be placed (as this 0 is not a leading zero)
            for(int d = 0; d <= limit; d++) {
                int new_tight = tight && (d == num[pos]-'0');

                // check if the dth bit is set or not 
                int bit = (mask >> d) & 1;

                if(!bit) {
                    // d digit is not used previously 
                    int new_mask = mask | (1 << d);
                    res += f(pos+1, new_tight, 1, new_mask);
                }
            }
        }

        return dp[pos][tight][started][mask] = res;
    }

public:
    int countSpecialNumbers(int n) {
        num = std::to_string(n);

        memset(dp, -1, sizeof(dp));

        // start with tight = 1 (currently bounded), mask = 0, started = 0
        return f(0, 1, 0, 0);
    }
};