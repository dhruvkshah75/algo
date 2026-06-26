// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

/* Explaination: 
   The minimum number of insertions to make the string a palindorme is quite easy 
   suppose len of the longest palindromic subsequence is x => the characters whose identical palindromic 
   letter is missing are n - x => only these number of letters must be added to make the string palindrome */

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

#define all(x) x.begin(), x.end()

class RecursiveSolution {
private:
    const static int N = 501;
    int dp[N][N];

    int lcs(int i, int j, string &s1, string &s2) {
        // calculate the length of the longest common subsequence (LCS)
        // base case: index out of bounds 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all the cases of characters matching and not matching 
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2);

        return dp[i][j] = max(lcs(i - 1, j, s1, s2), lcs(i, j - 1, s1, s2));
    }

public:
    int minInsertions(string &s) {
        int n = s.length();

        string r = s;
        reverse(all(r));

        memset(dp, -1, sizeof(dp));

        int len = lcs(n - 1, n - 1, s, r);

        // minimum insertions => n - len
        return n - len;
    }
};


// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

#define all(x) x.begin(), x.end()

class Solution {
private:
    const static int N = 501;
    int dp[N][N];

    /*
    int lcs(int i, int j, string &s1, string &s2) {
        // calculate the length of the longest common subsequence (LCS)
        // base case: index out of bounds 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all the cases of characters matching and not matching 
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2);

        return dp[i][j] = max(lcs(i - 1, j, s1, s2), lcs(i, j - 1, s1, s2));
    }
    */

public:
    int minInsertions(string &s) {
        int n = s.length();

        string r = s;
        reverse(all(r));

        memset(dp, 0, sizeof(dp));

        // tabulation to get the lcs of string s and r 
        // dp vector is 1 based indexing and strings are 0 based 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // case 1: chars match and case 2: chars dont match
                if(s[i - 1] == r[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int len = dp[n][n];

        // minimum insertions => n - len
        return n - len;
    }
};


// this solution can be space optimised 

// ======================================================= Space Optimised Solution ==================================================================================

#define all(x) x.begin(), x.end()

class SpaceOptimisedSolution {
private:
    const static int N = 501;
    int prev[N], curr[N];

    /*
    int lcs(int i, int j, string &s1, string &s2) {
        // calculate the length of the longest common subsequence (LCS)
        // base case: index out of bounds 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all the cases of characters matching and not matching 
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2);

        return dp[i][j] = max(lcs(i - 1, j, s1, s2), lcs(i, j - 1, s1, s2));
    }
    */

public:
    int minInsertions(string &s) {
        int n = s.length();

        string r = s;
        reverse(all(r));

        memset(prev, 0, sizeof(prev));
        memset(curr, 0, sizeof(curr));
        // prev => dp[i - 1] and curr => dp[i]

        // tabulation to get the lcs of string s and r 
        // dp vector is 1 based indexing and strings are 0 based 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // case 1: chars match and case 2: chars dont match
                if(s[i - 1] == r[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
        }

        // after all iterations prev denotes dp[n]
        int len = prev[n];

        // minimum insertions => n - len
        return n - len;
    }
};