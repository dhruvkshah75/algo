#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;


#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/longest-palindromic-substring/description/

/* @brief dp on strings => logic is different than the longest palindromic subsequence 
   recurrence f(i, j) = bool function returns true if s[i...j] is a palindromic substring 
   Now check which s[i...j] is a palindrome among all possible i and j combinations 
   */

class Solution {
private: 
    static constexpr int N = 1e3+1;
    int dp[N][N];

    bool f(int i, int j, string &s) {
        // f returns true if s[i...j] is a suffix 
        // base case: complete part is checked out 
        if(i > j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        // if the ith and jth chars match then check further
        if(s[i] == s[j])  
            return dp[i][j] = f(i+1, j-1, s);
        else 
            return dp[i][j] = false;
    }

public:
    string longestPalindrome(string &s) {
        int n = s.length();

        memset(dp, -1, sizeof(dp));

        int maxi = 1, ind = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(j-i+1 > maxi && f(i, j, s)) {
                    maxi = j-i+1;
                    ind = i;
                }
            }
        }

        // return the substring starting at ind of length maxi
        return s.substr(ind, maxi);
    } 
};

