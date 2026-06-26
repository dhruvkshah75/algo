// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/shortest-common-supersequence/description/

// ===================================== Very Important Question =================================================

/* Explaination:
   SuperSequence is the shortest string such that str1 and str2 are both the subsequences of supersequence   
   The characters in the lcs of string 1 and string 2 => should only be taken once (common chars must be taken once)
   The length of the shortest supersequence is n1 + n2 - len(lcs) 
   Now the main part is how to build the supersequence => that can be done with the help of the dp table from the tabulation 

   Note: dp[i][j] => rows indicate the string s1 and columns indicate s2

   How to build the final supersequence string ?
   Start from the end number and go back like backtracking 
   where does the lcs part come from => 1. dp[i][j] = 1 + dp[i -1][j - 1] (when chars dont match)
   Now when do we add the remaining characters 
   2. when chars dont match => dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
      So when dp[i][j] came from dp[i - 1][j] => we processed the char s1[i] (1 based)
      and similarly for the case when dp[i][j] came from dp[i][j-1] => we processed s2[j]
    In  the end it is possible that either of the two strings were not completely visited so add the remaining part to it 
*/

#define all(x) x.begin(), x.end()

class Solution {
public:
    string shortestCommonSupersequence(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // dp[i][j] => use this to calculate the longest common subsequence 
        
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // case 1: when chars match 
                if(s1[i-1] == s2[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                // case 2: when chars dont match 
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int lcs = dp[n1][n2];
        // length of shortest supersequence is n1 + n2 - lcs 

        // ============= print the string using backtrack on dp table ===============
        // build the super sequence from the dp array 
        string res = "";

        int i = n1, j = n2;

        while(i > 0 && j > 0) {
            // case 1: when both the characters match 
            if(s1[i-1] == s2[j-1]) {
                res += s1[i-1];
                i--; j--;
                // dp[i][j] = 1 + dp[i-1][j-1] 
            }
            else {
                // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                if(dp[i-1][j] > dp[i][j-1]) {
                    // processed the s1[i] => 1 based indexing
                    res += s1[i-1];
                    i--;
                }
                else {
                    // processed the s2[j] => 1 based indexing 
                    res += s2[j-1];
                    j--;
                }
            }
        }

        // now add the remaining characters from the string s1 or string s2 
        // both the while loops will not execute as the above while loop stops when either of i or j becomes 0
        while(i > 0) {
            res += s1[i-1];
            i--;
        }

        while(j > 0) {
            res += s2[j-1];
            j--;
        }

        // since we backtracked the res is in reverse order 
        reverse(all(res));

        return res;
    }
};