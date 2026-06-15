// ==================================== dp on subsequences ========================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// question link: https://leetcode.com/problems/integer-break/description/ 

/* Explanation: Unbounded Knapsack type dp 
   it is always better to split the number into as many numbers 
   this comes down to the case of splitting the number into 2s and 3s 
   Never split the number into a 1 => as 1 doesnt contribute the multiplication factor 
   The solution wont go out of bounds of INT */

// ==============================================================================================
//                              top down approach memoization dp
// ==============================================================================================

class Solution {
private:
    static constexpr int N = 59;
    int dp[N];

    int f(int x) {
        if(x == 0) return 1;

        if(dp[x] != -1) return dp[x];

        // try all possible sums 
        int res = 0;

        for(int num: {1, 2, 3}) {
            if(x >= num) res = max(res, num * f(x - num));
        }

        return dp[x] = res;
    }

public:
    int integerBreak(int n) {
        // splitting n into k numbers such that k >= 2
        // 1 + 1 = 2
        if(n == 2) return 1;
        // 2 + 1 = 3
        if(n == 3) return 2;

        memset(dp, -1, sizeof(dp));

        return f(n);
    }
};
// Time Complexity = O(3 * N), Space Complexity = O(N) + O(N)