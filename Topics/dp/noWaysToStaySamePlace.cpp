// =============================================== counting num of ways dp =============================================================

#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/

/* Explanation: Simple multi state dp or counting dp 
   Each move (Left, right, stay) counts as one step 
   At each step the position should not become invalid outside range of array 
   since max steps is 500 then max steps to the right can go to 500 so if arrLen > 500
   then it doesnt matter to us => using recursion explore all possible paths 
   f(pos, steps_left) => this is the recurrence relation 
*/

typedef long long ll;

class Solution {
private: 
    const int MOD = 1e9+7;
    static constexpr int N = 501;
    int dp[N][N];

    int f(int pos, int steps, int len) {
        // base case: all steps are completed 
        if(steps == 0) return (pos == 0);

        if(dp[pos][steps] != -1) return dp[pos][steps];

        // 3 options => right, left, stay 
        ll res = f(pos, steps-1, len);

        if(pos+1 < len) res = (res + f(pos+1, steps-1, len)) % MOD;

        if(pos-1 >= 0) res = (res + f(pos-1, steps-1, len)) % MOD;

        return dp[pos][steps] = res % MOD;
    }

public:
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));

        return f(0, steps, arrLen);
    }
};