// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/distinct-subsequences/description/

/* Dp on strings: => this question is based on dp on string matching 
   
   Explaination of this question: 
   We will match character by character ins string s1 and s2 and check for each match => similar to exploring all the paths 
   so we apply recursion + memoization for optimal solution 
*/

/* How to write the reccurrence for this question ?
   Express the recurrence in terms of all the indices => here i and j for denoting the pointers to their respective string 
   i => string s, j => string t
   explore all possibilities 

   1 <= s.length, t.length <= 1000

   Start the pointers from i = n - 1 and j = m - 1 
   f(i, j) => number of subsequences of string t[0...j] in s[0....i]
   In recursion when we are finding the number of something => make the base cases to be either returning 1 or returning 0

   To count the number of subsequences => explore all possible paths and base cases must return 0 or 1 

   base case => return 0 => ran out of string s but string t not yet completed  
   base case => return 1 => when string t ran out => irrespective of s as we found 1 subsequence with this path

   explore all possible paths or cases:
   when f(i, j) => i and j chars match => 2 possible paths => pick this char or search for the same char in s[0...i-1]
   and when the chars dont match => just search in s[0...i-1]
*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecursiveSolution {
private: 
    
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // base case: ran out of index in s but j is done yet 
        if(i < 0 && j >= 0) return 0;

        // base case: when j ran out => subsequence found 
        if(j < 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all possible cases 
        // case 1: current chars matches => we can take this or not 
        if(s[i] == t[j]) 
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        
        // case 2: chars dont match 
        return dp[i][j] = f(i-1, j, s, t, dp);
    }

public:
    int numDistinct(string &s, string &t) {
        int n = s.length(), m = t.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n-1, m-1, s, t, dp); 
    }
};

// =========================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

// must use unsigned long long ull => as the intermediate steps might cause overflow 

typedef unsigned long long ull;

class Solution {
private: 
    /*
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // base case: ran out of index in s but j is done yet 
        if(i < 0 && j >= 0) return 0;

        // base case: when j ran out => subsequence found 
        if(j < 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all possible cases 
        // case 1: current chars matches => we can take this or not 
        if(s[i] == t[j]) 
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        
        // case 2: chars dont match 
        return dp[i][j] = f(i-1, j, s, t, dp);
    }
    */

public:
    int numDistinct(string &s, string &t) {
        int n = s.length(), m = t.length();

        vector<vector<ull>> dp(n + 1, vector<ull>(m + 1, 0));
        // make the dp vector 1 based indexing for dealing with base cases

        // base case: j < 0 => dp = 1 for all i
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        // base case: i < 0 && j >= 0 (0 based indexing)=> dp = 0 for all j
        // for(int j = 1; j <= m; j++) dp[0][j] = 0

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // explore all the cases 
                if(s[i-1] == t[j-1]) {
                    // when chars match, we can either:
                    // 1. Use s[i-1] to match t[j-1] (dp[i-1][j-1])
                    // 2. Ignore s[i-1] and look for t in s[0...i-2] (dp[i-1][j])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};


// This solution can be space optimised => as each caluclation uses the prev row or prev column 

// ====================================================================================================================================================================================
//                                                     Space Optimised Bottom up approach (Tabulation) dp
// ====================================================================================================================================================================================

typedef unsigned long long ull;

class Solution {
private: 
    /*
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // base case: ran out of index in s but j is done yet 
        if(i < 0 && j >= 0) return 0;

        // base case: when j ran out => subsequence found 
        if(j < 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        // explore all possible cases 
        // case 1: current chars matches => we can take this or not 
        if(s[i] == t[j]) 
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        
        // case 2: chars dont match 
        return dp[i][j] = f(i-1, j, s, t, dp);
    }
    */

public:
    int numDistinct(string &s, string &t) {
        int n = s.length(), m = t.length();

        vector<ull> prev(m + 1, 0), curr(m + 1, 0);
        // prev => dp[i-1] and curr => dp[i]
        // make the dp vector 1 based indexing for dealing with base cases

        // base case: j < 0 => dp = 1 for all i => dp[i][0] = 1
        prev[0] = 1;

        // base case: i < 0 && j >= 0 (0 based indexing)=> dp = 0 for all j
        // for(int j = 1; j <= m; j++) dp[0][j] = 0

        for(int i = 1; i <= n; i++) {
            // base case
            curr[0] = 1;

            for(int j = 1; j <= m; j++) {
                // explore all the cases 
                if(s[i-1] == t[j-1]) {
                    // when chars match, we can either:
                    // 1. Use s[i-1] to match t[j-1] (dp[i-1][j-1])
                    // 2. Ignore s[i-1] and look for t in s[0...i-2] (dp[i-1][j])
                    curr[j] = prev[j-1] + prev[j];
                }
                else {
                    curr[j] = prev[j];
                }
            }

            swap(prev, curr);
        }

        // after all n iterations prev => dp[n]
        return (int)prev[m];
    }
};