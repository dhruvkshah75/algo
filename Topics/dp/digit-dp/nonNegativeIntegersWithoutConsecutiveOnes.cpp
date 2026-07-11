// ================================================== digit dp ======================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/

/* Explanation: digit dp 
   instead of expressing the number as decimals => represent the number in binary 0 1 bits 
   so convert the given n into a binary number and till the msb 1 
   so if n = 8 => only represent the number as 1000 (the msb 0s are irrelevant)

   So we need 3 states => pos going on till 32 bits, tight = 0, 1 and 
   prev to store which digit was present earlier 
   if prev = 1 then the next bit cannot be 1 
*/

class Solution {
private:
    int dp[32][2][2];

    int f(int pos, int tight, int prev, string &num) {
        // base case: all bits are occupied 
        if(pos == num.length()) return 1;

        if(dp[pos][tight][prev] != -1) return dp[pos][tight][prev];

        // try placing all possible bit combinations 0 and 1 
        int res = 0;
        int limit = (tight) ? num[pos]-'0' : 1;

        for(int d = 0; d <= limit; d++) {
            int new_tight = tight && (d == limit);

            // only place d = 1 when prev != 1
            if(d == 1 && prev != 1) {
                res += f(pos+1, new_tight, 1, num);
            }
            else if(d == 0) {
                // we can place bit = 0 no matter what 
                res += f(pos+1, new_tight, 0, num);
            }
        }

        return dp[pos][tight][prev] = res;
    }

    string binary_rep(int n) {
        string res = "";

        while(n > 0) {
            int bit = (n & 1);
            res += bit + '0';
            // right shift n by 1 to access the next bit 
            n = (n >> 1);
        }

        // binary rep will be in the reverse dir 
        reverse(res.begin(), res.end());
        return res;
    }


public:
    int findIntegers(int n) {
        string num = binary_rep(n);
        cout << num << endl;

        memset(dp, -1, sizeof(dp));

        // start with prev = 0 => as we only care if prev = 1 occurs 
        return f(0, 1, 0, num);
    }
};