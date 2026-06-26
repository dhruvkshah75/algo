// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/wildcard-matching/description/

// ========================================================== Very Important Question ===============================================================================

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

/* Explaination
   Question is based on string matching and explore all possible matchings 
   f(i, j-1) => * matches empty sequence so j moves on to the next 
   f(i-1, j) => * matches the current char in the sequence and so j moves to the next
   
   explore all paths or cases:
   3 cases => p[j] = '*' or '?' or 'x' 
   All the cases are simple string matching cases 

   Base Case: 
   total of 3 base cases => very important cases:
   1. i < 0 and j < 0 => both strings s and p completely processed => return true (p correcly matches s)
   2. j < 0 => pattern string p processed completely => return false
   3. i < 0 => string s completely processed => the only way true comes up is when 
      all remaining chars in string p are '*' which represent empty sequence otherwise return false
      
*/

class RecursiveSolution {
private: 
    bool f(int i, int j, string &s, string &p, vector<vector<int8_t>> &dp) {
        // base cases: both ran out of indexes 
        if(i < 0 && j < 0) return true;

        // base case: pattern string ran is completely processed 
        if(j < 0) return false;

        // base case: string s is completely processed => true only when the all remaining chars in p are '*'
        if(i < 0) {
            if(p[j] == '*') return f(i, j-1, s, p, dp);
            else return false;
        }

        if(dp[i][j] != -1) return (dp[i][j] == 1);

        // explore all possible cases 
        bool res = false;

        if(p[j] == '*') {
            // either match empty subsequence or match the current char and move on to the next
            res = f(i, j-1, s, p, dp) || f(i - 1, j, s, p, dp);
        }
        else if(p[j] == '?') {
            // match the current char and move onto the next
            res = f(i-1, j-1, s, p, dp);
        }
        else {
            // if p[j] is a normal character 
            if(s[i] == p[j]) res = f(i-1, j-1, s, p, dp);
            else res = false;
        }

        return dp[i][j] = res;
    }

public:
    bool isMatch(string &s, string &p) {
        int n1 = s.length(), n2 = p.length();

        // use int8_t (8 bits) as dp stores only {1, 0, -1} 
        vector<vector<int8_t>> dp(n1, vector<int8_t>(n2, -1));

        return f(n1-1, n2-1, s, p, dp);
    }
};

// =========================================================================================================================================================
//                                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

class Solution {
private: 
    /*
    bool f(int i, int j, string &s, string &p, vector<vector<int8_t>> &dp) {
        // base cases: both ran out of indexes 
        if(i < 0 && j < 0) return true;

        // base case: pattern string ran is completely processed 
        if(j < 0) return false;

        // base case: string s is completely processed => true only when the all remaining chars in p are '*'
        if(i < 0) {
            if(p[j] == '*') return f(i, j-1, s, p, dp);
            else return false;
        }

        if(dp[i][j] != -1) return (dp[i][j] == 1);

        // explore all possible cases 
        bool res = false;

        if(p[j] == '*') {
            // either match empty subsequence or match the current char and move on to the next
            res = f(i, j-1, s, p, dp) || f(i-1, j, s, p, dp);
        }
        else if(p[j] == '?') {
            // match the current char and move onto the next
            res = f(i-1, j-1, s, p, dp);
        }
        else {
            // if p[j] is a normal character 
            if(s[i] == p[j]) res = f(i-1, j-1, s, p, dp);
            else res = false;
        }

        return dp[i][j] = res;
    }
    */

public:
    bool isMatch(string &s, string &p) {
        int n1 = s.length(), n2 = p.length();

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        // dp[i][j] = does string s[0.....i] match p[0....j]
        // make dp 1 based indexing 

        // base case: i < 0 and j < 0 => true
        dp[0][0] = true;

        // base case: j < 0 => return false

        // base case: i < 0 => string s is now processed 
        for(int j = 1; j <= n2; j++) {
            // since s is done then p's starting chars must be * (to represent empty subsequence)
            if(p[j-1] == '*') dp[0][j] = true;
            else break;
        }

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // explore all possible cases of p[j]
                if(p[j-1] == '*') {
                    // '*' can match multiple chars or empty subsequence 
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else if(p[j-1] == '?') {
                    // match the current char and move on 
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // p[j] is a normal character 
                    if(p[j-1] == s[i-1]) dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = false;
                }
            }
        }

        // dp[n1][n2] = does string s[0...n1] match p[0...n2]
        return dp[n1][n2];
    }
};

// The above solution can be space optimised to get the space complexity to O(N2)  

// ===============================================================================================================================================================
//                                                     Space Optimised Bottom up approach (Tabulation) dp
// ===============================================================================================================================================================

class SpaceOptimisedSolution {
private: 
    /*
    bool f(int i, int j, string &s, string &p, vector<vector<int8_t>> &dp) {
        // base cases: both ran out of indexes 
        if(i < 0 && j < 0) return true;

        // base case: pattern string ran is completely processed 
        if(j < 0) return false;

        // base case: string s is completely processed => true only when the all remaining chars in p are '*'
        if(i < 0) {
            if(p[j] == '*') return f(i, j-1, s, p, dp);
            else return false;
        }

        if(dp[i][j] != -1) return (dp[i][j] == 1);

        // explore all possible cases 
        bool res = false;

        if(p[j] == '*') {
            // either match empty subsequence or match the current char and move on to the next
            res = f(i, j-1, s, p, dp) || f(i-1, j, s, p, dp);
        }
        else if(p[j] == '?') {
            // match the current char and move onto the next
            res = f(i-1, j-1, s, p, dp);
        }
        else {
            // if p[j] is a normal character 
            if(s[i] == p[j]) res = f(i-1, j-1, s, p, dp);
            else res = false;
        }

        return dp[i][j] = res;
    }
    */

public:
    bool isMatch(string &s, string &p) {
        int n1 = s.length(), n2 = p.length();

        vector<bool> prev(n2 + 1, false), curr(n2 + 1, false);
        // prev => dp[i-1] and curr = dp[i]
        // dp[i][j] = does string s[0.....i] match p[0....j]
        // make dp 1 based indexing 

        // base case: i < 0 and j < 0 => true
        prev[0] = true;

        // base case: j < 0 => return false => dp[i][0] = false

        // base case: i < 0 => string s is now processed 
        for(int j = 1; j <= n2; j++) {
            // since s is done then p's starting chars must be * (to represent empty subsequence)
            if(p[j-1] == '*') prev[j] = true;
            else break;
        }

        for(int i = 1; i <= n1; i++) {
            curr[0] = false;

            for(int j = 1; j <= n2; j++) {
                // explore all possible cases of p[j]
                if(p[j-1] == '*') {
                    // '*' can match multiple chars or empty subsequence 
                    curr[j] = curr[j-1] || prev[j];
                }
                else if(p[j-1] == '?') {
                    // match the current char and move on 
                    curr[j] = prev[j-1];
                }
                else {
                    // p[j] is a normal character 
                    if(p[j-1] == s[i-1]) curr[j] = prev[j-1];
                    else curr[j] = false;
                }
            }

            swap(prev, curr);
        }

        // prev[n2] => dp[n1][n2] = does string s[0...n1] match p[0...n2]
        return prev[n2];
    }
};