// ========================================================= dp on strings ===================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/interleaving-string/description/

/* Explaination: dp on strings 
   total 3 pointers will be needed to apply recursive solution 
   f(i, j, k) => 3 states wont work => exceeds time complexity 
   pointer for s3 wont be needed as k = i+j 
   Try out all possible matchings of s1 with s3 and s2 with s3 

   Recurrence => f(i, j) => returns true if s1 and s2 interleave to get s3 

   Space Complexity = O(min(s1.length, s2.length())) => space optimised tabulation 
*/

class Solution {
private:
    static constexpr int N = 1e2 + 1;
    int dp[N][N];

    bool f(int i, int j, string &s1, string &s2, string &s3) {
        // base case: when s1 and s2 are both are processed then it works 
        if(i == s1.length() && j == s2.length()) {
            return (i + j == s3.length());
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool res = false;

        // try matching s1[i] with s3[k]
        if(i < s1.length() && s1[i] == s3[i+j]) 
            res = res || f(i+1, j, s1, s2, s3);

        if(j < s2.length() && s2[j] == s3[i+j])
            res = res || f(i, j+1, s1, s2, s3);

        return dp[i][j] = res;
    }

public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        memset(dp, -1, sizeof(dp));

        return f(0, 0, s1, s2, s3);
    }
};