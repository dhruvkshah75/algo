// ======================================================== digit dp ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-numbers-with-non-decreasing-digits/description/

/* Explanation: digit dp 
   numbers are specified in the base b so the digit limit will be b-1 
   if the base is 8 => max digit limit is 7 cant go above it 
   and for states in dp => we need prev case to compare that the digits are non decreasing 
    
   prev size will be b+1 => make it to [11] and prev = 10 denotes the case of no prev digit or 
   leading zero
   f(pos, tight, prev) => recurrence for this question 
   to get l-1 of the string => the subtraction logic also changes as the numbers are in base b 

   the string must be converted to their base => so the string length in thr worst case <= 350
*/

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    int base;
    int dp[350][2][11];

    int f(int pos, int tight, int prev, string &num) {
        // base case
        if(pos == num.length()) return 1;

        if(dp[pos][tight][prev] != -1) return dp[pos][tight][prev];

        ll res = 0;
        int limit = (tight) ? num[pos]-'0' : base-1;

        if(prev == 10) {
            // prev = 10 => case of leading zeros 
            res = (res + f(pos+1, 0, 10, num)) % MOD;

            // option to start the number 
            for(int d = 1; d <= limit; d++) {
                int new_tight = tight && (d == num[pos]-'0');

                res = (res + f(pos+1, new_tight, d, num)) % MOD;
            }
        }
        else {
            // prev number exists => so only use d >= prev
            for(int d = prev; d <= limit; d++) {
                int new_tight = tight && (d == num[pos]-'0');

                res = (res + f(pos+1, new_tight, d, num)) % MOD;
            }
        }

        return dp[pos][tight][prev] = res;
    }

    string subtract_one(string &s) {
        int n = s.length();

        for(int i = n-1; i >= 0; i--) {
            if(s[i] > '0') {
                s[i]--;
                return s;
            }
            // s[i] = 0 => on subtracting carry is counted 
            s[i] = base-1+'0';
        }
        return s.substr(1);
    }

    string toBase(string s) {
        if (s == "0") return "0";

        string ans;

        while (s != "0") {
            string quotient;
            int rem = 0;

            for (char c : s) {
                int cur = rem * 10 + (c - '0');

                if (!quotient.empty() || cur / base != 0)
                    quotient.push_back(char(cur / base + '0'));

                rem = cur % base;
            }
            ans.push_back(char(rem + '0'));
            if(quotient.empty()) quotient = "0";

            s = quotient;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    int countNumbers(string &l, string &r, int b) {
        base = b;

        memset(dp, -1, sizeof(dp));
        string num2 = toBase(r);
        int res_B = f(0, 1, 10, num2);

        memset(dp, -1, sizeof(dp));
        string num1 = toBase(l);
        string l_minus_one = subtract_one(num1);
        int res_A = f(0, 1, 10, l_minus_one);

        return (int)((res_B - res_A + MOD) % MOD);
    }
};