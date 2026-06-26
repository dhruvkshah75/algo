// ======================================================== dp on strings ==================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;


#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/regular-expression-matching/description/

// ============================================= Important Question ==============================================

/* Explanation: dp on strings with string matchings 
   the only difference between regular expression matching and wildcard matching is that in this question we 
   * represents any number of precedding element or empty subsequence i.e. s2[i] = '*' then * can match any number of 
   characters that are equal to s2[i-1] = c and a char in p cannot match with any char is s (we can skip chars in p)
    
   Note: a* means "", "a", "aa", "aaa", "aaa...."
   similarly .* means => "", "a", "b", ... , "abcd..", "xyz.." => basically .* translates to everything 
   so we deal with a* togethor and not by considering the prev */

class Solution {
private:
    vector<vector<int>> dp;

    bool f(int i, int j, string &s, string &p, int n1, int n2) {
        // return true => when s and p togethor are completely explored 
        // if p finishes early thhen retunr false
        if(j == n2) return (i == n1);

        // if i finishes early then all next in p must be of the form a*b*..
        if(i == n1) {
            if(j+1 < n2 && p[j+1] == '*') return f(i, j+2, s, p, n1, n2);
            return false;
        }

        if(dp[i][j] != -1) return (dp[i][j] == 1);

        // try out the cases of character matchings
        bool res = false;

        if(j+1 < n2 && p[j+1] == '*') {
            // of the form a* => either match the current character or skip to j+2 as a* = ""
            res = res || f(i, j+2, s, p, n1, n2);

            // match the char 
            if(p[j] == '.' || s[i] == p[j]) 
                res = res || f(i+1, j, s, p, n1, n2);
        }
        else if(p[j] == '.' || s[i] == p[j]) {
            // single char => match it with the s[i]
            res = res || f(i+1, j+1, s, p, n1, n2);
        }   

        return dp[i][j] = res;
    }

public:
    bool isMatch(string &s, string &p) {
        int n1 = s.length(), n2 = p.length();

        dp.resize(n1, vector<int>(n2, -1));
        // dp[i][j][prev] = true if the s[i...n1] matches p[j...n2]

        return f(0, 0, s, p, n1, n2);
    }
};

