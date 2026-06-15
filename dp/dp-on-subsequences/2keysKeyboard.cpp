// ================================================================== dp on subsequences ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/2-keys-keyboard/description/

// This is not the most effecient way to solve the question 

/* Explanation: dp on multiple states 
   To define the recurrence we would need 2 states 
   We start with curr = 1 (A on the screen) and we need a sequence of steps of
   copy and pasting to get the n characters at the end. if we get > n chars => invalid sequence of steps => return 1e8
   Two options => 1. copy and paste the current string (2 steps) 2. paste the prev copied case and this uses only 1 step 
*/

class Solution {
private:
    static constexpr int N = 1e3+1;
    int dp[N][N];

    int f(int curr, int prev, int n) {
        // base case: when we have reached n (written n characters)
        if(curr == n) return 0;
        
        // base case: curr becomes invalid (out of bounds)
        if(curr > n) return 1e8;

        if(dp[curr][prev] != -1) return dp[curr][prev];

        int res = 1e8;
        // case 1: use the existing prev copy (1 step)
        if(prev != 0) res = min(res, 1 + f(curr+prev, prev, n));

        // case 2: copy the curr and add it to the curr (2 steps)
        res = min(res, 2 + f(2*curr, curr, n));

        return dp[curr][prev] = res;
    }

public:
    int minSteps(int n) {
        memset(dp, -1, sizeof(dp));

        return f(1, 0, n);
    }
};