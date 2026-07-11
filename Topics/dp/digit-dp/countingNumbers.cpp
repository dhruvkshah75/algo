// ================================================ digit dp ====================================================== 

#include<bits/stdc++.h>
using namespace std;

/** 
 *  How does digit dp work 
 *  Digit dp is used when we are supposed to count some numbers under some conditions (calculate numbers in some range [a, b])
 *  or we use digit dp when the range of numbers is very large like <= 1e18 or 1e9
 * 
 *  we use a extra state called tight => it is actually a flag that helps to keep a note of something 
 *  
 *  Question:
 *  Your task is to count the number of integers between a and b where no two adjacent digits are the same.
 *  
 *  Approach: 
 *  Here in this question we use the prefix concept => answer = solve(b) - solve(a-1)
 *  now how to figure out if the number string that we form does not exceed b (we dont go out of range) => here tight comes into play 
 * 
 *  tight = true (1) means your prefix so far macthes exactly to n's prefix
 *  tight determines are we still bounded by the upper bound 
 *  
 *  here the tight we use is 
 *  tight = 1 (true): current_digit can only be 0 to digit[pos] of B 
 *  tight = 0 (false): current_digit can be 0 to 9
 * 
 *  take example => b = 234 
 *  so in the start we can place 0, 1, 2 
 *  when we place 2 then we are bounded by the tight constraint as the next digit has to be between [0..digit[pos] of B]
 *  but in the start if we place 1 then tight = 0 => next digit we can place anything 
 * 
 *  In this question we must need 3 states => tight, pos, prev 
 *  we need prev to prevent duplicates and tight to handle the upperbound condition to the number b
 * 
 *  dp[19][2][11] => dp[pos][tight][prev]
 *  prev = 10 for the case when there is no previous number => leading zero case => since the number can have less number of digits 
 *  (instead add leading zeros)
 *  when we call the function for the first time => tight = true (as we cannot exceed the number from the first digit)
 * 
 *  To decide with what tight becomes => we need the case of what the tight was 
 *  if tight = 1 (means we are currently bounded and some digits previously used form the prefix so to continue this if it matched again then newtight = 1)
 */

typedef long long ll;

class Solution {
private: 
    ll dp[19][2][11];

    ll f(int pos, int tight, int prev, string &num) {
        // base case: when the entire word is filled 
        if(pos == num.length()) return 1;

        if(dp[pos][tight][prev] != -1) return dp[pos][tight][prev];

        // now try constructing all values (all numbers withing limit)
        ll res = 0;
        int limit = (tight) ? num[pos]-'0' : 9;

        for(int digit = 0; digit <= limit; digit++) {
            // update the tight => is the entire prefix till this pos matching with string num 
            int newTight = tight && (digit == limit) ? 1 : 0;

            // deal with prev = 10 (leading zero)
            if(prev == 10) {
                if(digit == 0) {
                    // continue with leading zero => so the prev = 10 
                    res += f(pos+1, newTight, 10, num);
                }
                else {
                    // non leading zero number is added 
                    res += f(pos+1, newTight, digit, num);
                }
            }
            else {
                // prev is valid case (normal number) 
                if(digit != prev) res += f(pos+1, newTight, digit, num);
            }
        }

        return dp[pos][tight][prev] = res;
    }

public: 
    ll cntDigits(ll a, ll b) {
        string num1 = std::to_string(a-1);
        string num2 = std::to_string(b);

        // convert to string to handle cases easily 
        memset(dp, -1, sizeof(dp));

        // start with leading zero (no prev) and tight = 1 (we are to be bounded by the first digit)
        ll ans_B = f(0, 1, 10, num2);
        
        memset(dp, -1, sizeof(dp));
        
        // note a can also be 0 => a-1 would be negative
        ll ans_A_minus_1 = 0;
        if(a > 0) ans_A_minus_1 = f(0, 1, 10, num1);

        return ans_B - ans_A_minus_1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    ll a, b;
    cin >> a >> b;

    cout << s.cntDigits(a, b) << endl;
}