// ========================================== digit dp ==============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-digit-one/description/

/* Explanation: digit dp 
   since we are supposed to calculate the number of ones in numbers for all nums <= n 
   so we try using all numbers in the num that we form

   we will need 3 dp states => dp[pos][tight][number of ones so far]
   started is not needed as we dont care about leading zeros 

   just add ones so far => here we count the number of ones that we accumulated in the number 
   keeping this as the state in the dp => max number of ones in a number will be 10
*/

class Solution {
private:
    string num;
    int dp[10][2][10];

    int f(int pos, int tight, int onesSoFar) {
        // base case: if all digits explored 
        if(pos == num.length()) return onesSoFar;

        if(dp[pos][tight][onesSoFar] != -1) return dp[pos][tight][onesSoFar];

        // try forming all numbers 
        int res = 0;
        int limit = (tight) ? num[pos]-'0' : 9;

        for(int digit = 0; digit <= limit; digit++) {
            // if the digit used is 1 => then update onesSoFar 
            int newTight = tight && (digit == num[pos]-'0') ? 1 : 0;
            int add = (digit == 1) ? 1 : 0;

            res += f(pos+1, newTight, onesSoFar + add);
        }

        return dp[pos][tight][onesSoFar] = res;
    }

public:
    int countDigitOne(int n) {
        num = std::to_string(n);

        memset(dp, -1, sizeof(dp));

        // call for tight = 1 and onesSoFar = 0
        return f(0, 1, 0);
    }
};