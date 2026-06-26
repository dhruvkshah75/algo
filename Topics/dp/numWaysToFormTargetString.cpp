// =================================================== multi state dp with string matchings ===========================================================

#include<bits/stdc++.h> 
using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

// question link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

// ======================================================== Critical Thinking based question ====================================

/* Explanation: multi state dp on strings with string matchings
   Very important Logic in this question
   Note: whenever space comes into a issue in terms of strings => we can always represent them as a vector<int> freq(26, 0)

   Consider the words as matrix of where col indicates which column are we indicating 
   When we match string chars then we only care if it matched and then move onto col+1 (prev column cant be accesed)
   we dont care that the char came from which string => so we can represent each column as a frequency array 

   eg. for the 1st testcase => (a=1, b=1, c=1), (a=1, b=1, c=1), (b=1, c=2), (a=2, b=1) => this becomes the freq vector 
   recurrence => f(ind, col) 

   Now at each col index => we have two options
   1. if possible match the chars and move to (ind+1, col+1) 
   2. dont match the char in this column and move onto next col => (ind, col+1)
*/

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    vector<vector<int>> freq;
    vector<vector<int>> dp;

    int f(int ind, int col, string &target, int m) {
        // base case: when target is exhausted then the word is matched 
        if(ind == target.length()) return 1;

        // base case: words[j] (for all j) is completely exhausted => target not reached  
        if(col == m) return 0;

        if(dp[ind][col] != -1) return dp[ind][col];

        // try all cases of matching the char 
        ll res = 0;
        int c = target[ind]-'a';

        // case 1: match the char if freq > 0
        if(freq[col][c] > 0) 
            res = (res + freq[col][c] * 1LL * f(ind+1, col+1, target, m)) % MOD;

        // case 2: dont match the char in this col 
        res = (res + f(ind, col+1, target, m)) % MOD;

        return dp[ind][col] = res % MOD;
    }

public:
    int numWays(vector<string> &words, string &target) {
        int n = target.size(), m = words[0].length();
        // m = number of cols 

        // initialise freq and dp vectors 
        freq.resize(m, vector<int>(26, 0));
        dp.resize(n, vector<int>(m, -1));

        // populate the freq (frequence of letters in the ith column)
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < m; j++) {
                int c = words[i][j]-'a';
                // j is the current column of the words matrix 
                freq[j][c]++;
            }
        }

        // return the number of ways to form target => f(0, 0)
        return f(0, 0, target, m);
    }
};