// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/delete-operation-for-two-strings/description/

/* This question involves deletions to be made to both the strings to get the same string 
   Simply get the lcs of both the strings => then the remaining chars must be deleted which are not the part of the lcs string 
   (n1 - lcs len) + (n2 - lcs len) => number of deletions needed to make the two strings indentical 
*/

// =================================================== Tabulation =======================================================

class Solution {
private: 
    const static int N = 501;
    int dp[N][N];

    /*
    int f(int i, int j, string &s1, string &s2) {
        // base case: index out of bounds 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // case1: chars match 
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i-1, j-1, s1, s2);

        // case 2: when chars dont match 
        return dp[i][j] = max(f(i-1, j, s1, s2), f(i, j-1, s1, s2));
    }
    */

public:
    int minDistance(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length(); 

        memset(dp, 0, sizeof(dp));
        // make the dp vector 1 based indexing => index shifting 

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // case 1: chars match 
                if(s1[i-1] == s2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int lcs = dp[n1][n2];

        return n1 + n2 - 2 * lcs;
    }
};

// This solution can be space optimised to O(min(N1, N2)) 

class SpaceOptimisedSolution {
private: 
    /*
    int f(int i, int j, string &s1, string &s2) {
        // base case: index out of bounds 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // case1: chars match 
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i-1, j-1, s1, s2);

        // case 2: when chars dont match 
        return dp[i][j] = max(f(i-1, j, s1, s2), f(i, j-1, s1, s2));
    }
    */

public:
    int minDistance(string &s1, string &s2) {
        // keep the s2 as the smaller string 
        if(s2.length() > s1.length()) swap(s1, s2);

        int n1 = s1.length(), n2 = s2.length(); 

        vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
        // prev => dp[i-1] and curr => dp[i] 
        // make the dp vector 1 based indexing => index shifting 

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // case 1: chars match and case 2: chars dont match
                if(s1[i-1] == s2[j-1]) 
                    curr[j] = 1 + prev[j-1];
                else 
                    curr[j] = max(prev[j], curr[j-1]);
            }

            swap(prev, curr);
        }

        int lcs = prev[n2];

        return n1 + n2 - 2 * lcs;
    }
};
// Space Complexity = O(min(N1, N2))