// ============================================================== dp on strings ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

/* Explanation: dp on strings involving string matchings or string comparision
   recurrence => f(i, j) pointers needed for both the strings
   When chars match => keep the char but when chars dont match we must delete either of them
*/

class Solution {
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case: both strings completely explored (nothing more to delete)
        if(i == s1.length() && j == s2.length()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        // 2 possible cases of => chars match or dont 
        int res = 1e9;
        
        // when chars match => we keep both the chars and move to next 
        if(i < s1.length() && j < s2.length() && s1[i] == s2[j]) {
            res = min(res, f(i+1, j+1, s1, s2, dp));
        }
        else {
            int del1 = 1e9, del2 = 1e9;

            // delete the ith char in s1 
            if(i < s1.length()) del1 = s1[i] + f(i+1, j, s1, s2, dp);

            // delete the jth char in s2
            if(j < s2.length()) del2 = s2[j] + f(i, j+1, s1, s2, dp);

            res = min({res, del1, del2});
        }

        return dp[i][j] = res;
    }

public:
    int minimumDeleteSum(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        return f(0, 0, s1, s2, dp);
    }
};

// Tabulation based code is more optimal as this very heavy recursion overhead 