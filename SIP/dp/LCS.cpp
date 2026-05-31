// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://takeuforward.org/plus/dsa/problems/longest-common-subsequence

// ===================================================== Longest Common Subsequence =============================================================================

/* Explaination: 
   dp ons strings involves => comparision, edits or replacements

   Brute force => form all the subsequences 2 ^ n => exponential time complexity 

   Recurrence => we use to two indexes => which point to their respective strings 
   i => s1 and j => s2

   1. Express recurrence in terms of indices: f(i, j) => lcs till the ith index of s1(0....i) and jth index of s2(0....j)
   2. Explore all possible cases => do comparision character wise to get the lcs => compare s1[i] and s2[j] 
   3. return the max length among all the possible cases or paths explored 

   Memoization => space complexity = O(n1 * n2) + O(n1 + n2) 
   Auxiliary stack space is the depth of the recursion => which can go on till both the strings end 

*/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

class RecursiveSolution {
private:    
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: index went out of bounds
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // case1: chars match
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        
        // case2: not match explore all the 2 possible cases of i, j 
        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    }

public:
    int longestCommonSubsequence(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return f(n1 - 1, n2 - 1, s1, s2, dp);
    }
};

// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

class Solution {
private: 
    /*
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: index went out of bounds
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // case1: chars match
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        
        // case2: not match explore all the 2 possible cases of i, j 
        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    }
    */

public:
    int longestCommonSubsequence(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // dp[i][j] = length on lcs till the ith index of string s1 and jth index of string s2
        // make dp 1 based => for i = 0 or j = 0 => invalid indices dp must be 0 

        // base case: from memo => i < 0 and j < 0 => return 0 
        // => apply shifting of index so now i = j = 0 complete row and col must be 0

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // dp is 1 based indexing but s1 and s2 are 0 based indexing 
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};


// the above solution can be space optimised as this uses the prev row elements or just the prev column elements 

class SpaceOptimisedSolution {
private: 
    /*
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: index went out of bounds
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // case1: chars match
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        
        // case2: not match explore all the 2 possible cases of i, j 
        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    }
    */

public:
    int longestCommonSubsequence(string &s1, string &s2) {
        // keep the smallest string as s2 => to minimise prev(n2 + 1)
        if(s2.length() > s1.length()) swap(s1, s2);

        int n1 = s1.length(), n2 = s2.length();

        vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
        // prev => dp[i - 1] and curr => dp[i]

        // dp[i][j] = length on lcs till the ith index of string s1 and jth index of string s2
        // make dp 1 based => for i = 0 or j = 0 => invalid indices dp must be 0 

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // dp is 1 based indexing but s1 and s2 are 0 based indexing 
                if(s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            swap(prev, curr);
        }

        return prev[n2];
    }
};


// =============================================================================================================================================================
// ========================================================= Print the LCS =====================================================================================
// =============================================================================================================================================================

/* To get the lcs we simulate the dp building in tabulation in reverse 
   if chars dont match then it must have come from => dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); (left or top element)
   and if chars match then it must come from dp[i][j] = 1 + dp[i - 1][j - 1]; (prev diagonally)

   How is exactly the dp array in tabulation built 
   every time the calculation of dp[i][j] happens in 2 ways 
   1. dp[i][j] = 1 + dp[i - 1][j - 1]; (when the characters match each other)
   2. dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); (when characters dont match each other) 

   so we start simulating from i = n1 and j = n2 and we move in the backward direction depending on where it came from 
   => if at curr i and j position (1 based) chars match then we came from [i - 1][j - 1] => so now move there 
   => if chars dont match at the curr pos then chars came from [i - 1][j] or [i][j - 1] so move there 
*/

#define all(x) x.begin(), x.end()

class Solution {
private: 
    /*
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: index went out of bounds
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // case1: chars match
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        
        // case2: not match explore all the 2 possible cases of i, j 
        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    }
    */

public:
    string longestCommonSubsequence(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // dp[i][j] = length on lcs till the ith index of string s1 and jth index of string s2
        // make dp 1 based => for i = 0 or j = 0 => invalid indices dp must be 0 

        // base case: from memo => i < 0 and j < 0 => return 0 
        // => apply shifting of index so now i = j = 0 complete row and col must be 0

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // dp is 1 based indexing but s1 and s2 are 0 based indexing 
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lenLCS = dp[n1][n2];

        // ============================== build the lcs string using Backtrack on dp array ==================================== 

        // now to get the actual lcs string => we simulate back in the dp table 
        string res = "";
        int i = n1, j = n2;

        while(i > 0 && j > 0) {
            if(s1[i - 1] == s2[j - 1]) {
                res += s1[i - 1];
                i--; j--; // move to the diagnolly prev element when chars match 
            }
            else {
                // if chars dont match then move to the top or left element in the dp matrix
                if(dp[i][j - 1] > dp[i - 1][j]) j--;
                else i--;
            }
        }

        // string res will be reversed as we simulated in the backward direction 
        reverse(all(res));

        return res;
    }
};


// =======================================================================================================================================================================================
//                                                          Modified version of LCS => Longest Common Substring
// =======================================================================================================================================================================================


// question link: https://takeuforward.org/plus/dsa/problems/longest-common-substring

/* Similar to LCS here the substring means a contiguous subsequence 
   
   Recollect the concept of LCS: 
   1. matching => dp[i][j] = 1 + dp[i - 1][j - 1]]
   2. not matching => dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

   Why this doesnt work here => because of the not matching part => 
   what it does essentially is it skips the current character and moves to the next => causing the subsequence check 

*/

// the recursion method involves the use of 3 states => not optimal => start from the tabulation method

class Solution{
public: 
    int longestCommonSubstr(string &s1, string &s2){
        int n1 = s1.length(), n2 = s2.length();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // index shifting from 0 based indexed strings to 1 based dp array 

        // dp[n1][n2] does not contain the final length 
        // final length of the longest common subtring will be the max value in the 2d dp vector 

        int res = 0;

        for(int i = 1; i < n1; i++) {
            for(int j = 1; j < n2; j++) {
                // matching chars case and not matching case
                if(s1[i - 1] == s2[j - 1]) {  
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res = max(res, dp[i][j]);
                }
                else dp[i][j] = 0; // since nothing matches so dont do anything 
            }
        }

        return res;
    }
};