// ================================================================== front partition dp ====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/word-break-ii/description/

/* Explanation: using front partition dp 
   Since this question involves printing the sentence separating the word 
   this involves using the concept of backtracking and rest of code is similar to word break 1 
   The recurrence must return something as this question involves the use of dp
   This question does not use pure backtracking as the question is non void return type 
*/

#define all(x) x.begin(), x.end()

class Solution {
private: 
    unordered_set<string> w;
    unordered_map<int,vector<string>> dp;

    vector<string> f(int ind, string &s, int n) {
        // base case: reached the end of the string => return empty string vector
        if(ind == n) return {""};

        if(dp.count(ind)) return dp[ind];

        vector<string> res;
        string curr = "";

        for(int j = ind; j < n; j++) {
            // create a partition j | j+1
            curr += s[j];

            if(w.count(curr)) {
                vector<string> nxt = f(j+1, s, n);
                // if nxt[i] string is not empty then add space 

                for(string &str: nxt) {
                    // if this string from next is empty 
                    if(str.empty()) 
                        res.push_back(curr);
                    else 
                        res.push_back(curr + " " + str);
                    // curr + (recursive work)
                }
                
            }
        }

        return dp[ind] = res;
    } 

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        w = unordered_set<string>(all(wordDict));

        dp.clear();
        // equivalent to memset(dp, -1, sizeof(dp))

        return f(0, s, n);
    }
};