// ======================================================== multi state dp ======================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/student-attendance-record-ii/description/

/* Explanation: 3d dp + counting dp 
   Simple multi state dp where we need one state ind for the days 
   one for checking the L_streak for keeping count of consecutive Ls 
   one state A_cnt for counting the number of Absents for all n days */

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    static constexpr int N = 1e5;

    int dp[N][3][2];

    int f(int ind, int l_streak, int a_cnt, int n) {
        // base case: all days explored 
        if(ind == n) return 1;

        if(dp[ind][l_streak][a_cnt] != -1) return dp[ind][l_streak][a_cnt];

        // explore all possible cases => A, L, P
        // case 1: Present P at the ind th day 
        ll res = f(ind+1, 0, a_cnt, n) % MOD;

        // case 2: late L at the ind th day 
        if(l_streak+1 <= 2)
            res = (res + f(ind+1, l_streak+1, a_cnt, n)) % MOD;

        // case 3: absent A on the ind th day 
        if(a_cnt + 1 <= 1)
            res = (res + f(ind+1, 0, a_cnt+1, n)) % MOD;


        return dp[ind][l_streak][a_cnt] = res % MOD;
    }

public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));

        // starting from 0th day and l_streak = 0 and a_cnt = 0
        return f(0, 0, 0, n);
    }
};
// Space Complexity = O(6*N) + O(N), Time Complexity = O(6*N)
