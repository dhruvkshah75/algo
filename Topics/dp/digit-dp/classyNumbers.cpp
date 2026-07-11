// ============================================= digit dp ============================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// question link: https://codeforces.com/problemset/problem/1036/C

/* Explanation: digit dp 
   here the max length of number is 18 and we must keep a count of how many non zero digits we encountered 
   max non zero allowed digits will be 3 => so the next state will have 4 values => 0, 1, 2, 3
   we cannot allow 4 non zero digits to be used 
   here we dont care about leading zeros so no state needed for that as they are 0s => do not contribute to the 3d state 
*/

class Solution {
private:
    ll dp[19][2][4];

    ll f(int pos, int tight, int nonZeroCnt, string &num) {
        // base case: the number fully explored 
        if(pos == num.length()) return 1;

        if(dp[pos][tight][nonZeroCnt] != -1) return dp[pos][tight][nonZeroCnt];

        // try forming all numbers 
        ll res = 0;
        int limit = (tight) ? num[pos]-'0' : 9;

        for(int digit = 0; digit <= limit; digit++) {
            // update the new_tight => whether the number being formed is prefix of num or not 
            int new_tight = tight && (digit == num[pos]-'0') ? 1 : 0;

            // we can use 0 no matter what 
            if(digit == 0) res += f(pos+1, new_tight, nonZeroCnt, num);

            if(digit != 0 && nonZeroCnt + 1 <= 3) {
                res += f(pos+1, new_tight, nonZeroCnt+1, num);
            }
        }

        return dp[pos][tight][nonZeroCnt] = res;
    } 

public: 
    ll solve(ll a, ll b) {
        string num1 = std::to_string(a-1);
        string num2 = std::to_string(b);

        // for such range questions => result = solve(b) - solve(a-1)

        memset(dp, -1, sizeof(dp));
        ll ans_b = f(0, 1, 0, num2);

        memset(dp, -1, sizeof(dp));
        ll ans_a = f(0, 1, 0, num1);

        return ans_b - ans_a;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    int t;
    cin >> t;

    while(t--) {
        ll a, b;
        cin >> a >> b;

        cout << s.solve(a, b) << endl;
    }
}