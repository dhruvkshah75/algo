// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/longest-palindromic-subsequence/

/* Explaination: 
   Note => getting the length of subsequence in any dp on strings is direct => but to get the actual string result => 
   we must backtrack in the tabulation and see where we the result came from 

   To solve this question => we think about something like bringing this question into the LCS section 

   take s as s1 and reverse s => r to get s2 
   and then the lcs of string s and r will be the longest palindromic subsequence 
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

#define all(x) x.begin(), x.end()

class RecursiveSolution {
private: 
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: when the indices go out of bounds 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // consider the case of chars matching and not matching 
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    } 

public:
    int longestPalindromeSubseq(string &s) {
        int n = s.length();

        string r = s;
        reverse(all(r));

        // now simply calculate the lcs of r and s => this will be the longest palindromic subsequence

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(n - 1, n - 1, s, r, dp);
    }
};


// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

#define all(x) x.begin(), x.end()

class Solution {
private: 
    /*
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: when the indices go out of bounds 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // consider the case of chars matching and not matching 
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    } 
    */

public:
    int longestPalindromeSubseq(string &s) {
        int n = s.length();

        string r = s;
        reverse(all(r));

        // now simply calculate the lcs of r and s => this will be the longest palindromic subsequence
        // using the tabulation version of lcs => make the dp vector as 1 based indexing 

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // dp[i][j] = length of longest palindromic subsequence 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // case 1: chars match, case 2: chars dont match
                if(s[i - 1] == r[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int len = dp[n][n];


        // print the longest palindrome subsequence => the method is same as printing LCS
        int i = n, j = n;
        string res = "";

        while(i > 0 && j > 0) {
            // when chars match 
            if(s[i - 1] == r[j - 1]) {
                res += s[i - 1];
                i--; j--;
                // move from [i][j] to [i-1][j-1]
            }
            else {
                if(dp[i - 1][j] > dp[i][j - 1]) i--;
                else j--;
            }
        }
        
        cout << res << endl;

        return len;
    }
};

// ======================================================== Space Optimised Solution ============================================================

// solution can be space optimised to 1d arrays prev and curr 

#define all(x) x.begin(), x.end()

class Solution {
private: 
    /*
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: when the indices go out of bounds 
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // consider the case of chars matching and not matching 
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    } 
    */

public:
    int longestPalindromeSubseq(string &s) {
        int n = s.length();

        string r = s;
        reverse(all(r));

        // now simply calculate the lcs of r and s => this will be the longest palindromic subsequence
        // using the tabulation version of lcs => make the dp vector as 1 based indexing 

        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        // prev => dp[i -1] and curr => dp[i]
        // dp[i][j] = length of longest palindromic subsequence 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // case 1: chars match, case 2: chars dont match
                if(s[i - 1] == r[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
        }

        return prev[n];
    }
};