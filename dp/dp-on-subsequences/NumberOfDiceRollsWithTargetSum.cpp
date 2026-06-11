// ========================================== dp on subsequences ======================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

/* Explaination: simple counting dp based on dp on subsequences 
   recurrence => f(ind, target) => ind denotes the dice and target is the sum left 
   base case: all the dices are rolled then the sum should be 0 => we found one way to roll the dice
   cannot have the base case of sum = 0 before all dice are processed as each dice adds the case of even 1  
*/

typedef long long ll;

class Solution {
private: 
    const int MOD = 1e9+7;

    int dp[30][1001];

    int f(int ind, int sum, int k) {
        // base case: all the dices explored 
        if(ind < 0) {
            if(sum == 0) return 1;
            else return 0;
        }

        if(dp[ind][sum] != -1) return dp[ind][sum];

        // explore all possible options of dice rolls (1 to k)
        ll cnt = 0;

        for(int dice = 1; dice <= k; dice++) {
            if(sum >= dice) 
                cnt = (cnt + f(ind-1, sum-dice, k)) % MOD;
        }

        return dp[ind][sum] = cnt % MOD;
    }


public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));

        return f(n-1, target, k);
    }
};
// Space Complexity = O(N * Target) + O(N), Time Complexity = O(N * Target)