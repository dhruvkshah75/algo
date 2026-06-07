// ==================================================== state-machine-dp =========================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/

/* Explaination: state-machine dp
   Here in each iteration assign colors in 1 row in the same iteration 
   states needed for each case => f(ind, prev1, prev2, prev3) 
   {prev1, prev2, prev3} => prev row entries to ensure no adjacent cols get the same color  
   Red => 1, Yellow => 2, Green => 3, invalid => 0 
*/

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    static constexpr int N = 5e3+1;

    int dp[N][4][4][4];

    int f(int ind, int prev1, int prev2, int prev3, int n) {
        // base case: all rows are painted 
        if(ind == n) return 1;

        if(dp[ind][prev1][prev2][prev3] != -1) return dp[ind][prev1][prev2][prev3];

        // try out all possible assignments of color 
        ll cnt = 0;

        // c1, c2, c3 => all possible 27 combinations to paint => assign the valid colors 
        for(int c1: {1, 2, 3}) {
            for(int c2: {1, 2, 3}) {
                // skip the adj same case 
                if(c1 == c2) continue;

                for(int c3: {1, 2, 3}) {
                    if(c2 == c3) continue;
                    // each color entry should be different from the prev row color 
                    if(c1 != prev1 && c2 != prev2 && c3 != prev3)
                        cnt = (cnt + f(ind+1, c1, c2, c3, n)) % MOD;
                }
            }
        }

        return dp[ind][prev1][prev2][prev3] = cnt % MOD;
    }

public:
    int numOfWays(int n) {
        
        memset(dp, -1, sizeof(dp));

        return f(0, 0, 0, 0, n);
    }
};