// ================================================== digit dp ===============================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-of-integers

/* Explanation: digit dp 
   first of all we are asked numbers in the range => solve(num2) - solve(num1-1)
   now the default dp states are pos and tight (started => leading zero state is not needed)
   since there are 23 digits at max the max sum <= 200

   prevent the sum from ever to exceed the max_sum so base case check is only needed for min_sum
*/

typedef long long ll;

class Solution {
private:
    int min_sum, max_sum;
    const int MOD = 1e9+7;
    int dp[23][2][200];

    int f(int pos, int tight, int curr_sum, string &num) {
        // base case
        if(pos == num.length()) return (curr_sum >= min_sum);

        if(dp[pos][tight][curr_sum] != -1) return dp[pos][tight][curr_sum];

        ll res = 0;
        int limit = (tight) ? num[pos]-'0' : 9;

        for(int d = 0; d <= limit; d++) {
            int new_tight = tight && (d == num[pos]-'0');

            // only take the digit if sum does not exceed max_sum 
            if(curr_sum + d <= max_sum) {
                res = (res + f(pos+1, new_tight, curr_sum+d, num)) % MOD;
            }
        }

        return dp[pos][tight][curr_sum] = res;
    }

    string subtract_one(string &s) {
        int n = s.length();

        for(int i = n-1; i >= 0; i--) {
            if(s[i] > '0') {
                s[i]--;
                // just decrement (no carry)
                return s;
            }

            // s[i] was 0 => on subtracting carry one occurs
            s[i] = '9';
        }

        return s.substr(1);
    }


public:
    int count(string &num1, string &num2, int min_sum, int max_sum) {
        if(min_sum >= 200) return 0;

        this->min_sum = min_sum;
        this->max_sum = max_sum;

        // for each recurrence call => start with tight = 1 and curr_sum = 0
        memset(dp, -1, sizeof(dp));
        int res_B = f(0, 1, 0, num2);

        memset(dp, -1, sizeof(dp));
        string num1_minus_one = subtract_one(num1);
        int res_A_minus_one = f(0, 1, 0, num1_minus_one);

        return (int)(res_B - res_A_minus_one + MOD) % MOD;
    }
};