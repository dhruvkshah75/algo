// ================================================================== dp-LIS ============================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/longest-string-chain/description/


/* Explaination: This is lis variant where we are supposed to get the length of longest sequence 
   The sequence [w1, w2, w3, ....., wk] => w1 is the predecessor to w2 and so on 
   so if the above sequence is a valid sequence then w1 is also a predecessor of wk

   As we go on from w1 -> w2 -> w3 => the length increases as we go 
   So we must sort the words on the basis of str length 

   Important Question: How to know if w1 is a predecessor of w2 
   W1 is the predecessor of W2 when exactly one insertion in w1 converts into w2 
   1. w2.length() - w1.length() == 1 
   2. lcs of w1, w2 => length of w1 => or use 2 pointers to simply calculate the 
*/

#define all(x) x.begin(), x.end()

class Solution {
private:

    bool isPredecessor(string &w1, string &w2) {
        // w1 -> w2 => by adding exactly one letter in w1 
        if(w2.length() - w1.length() != 1) return false;

        int n = w1.length();

        int i = 0, j = 0;
        // w1 = n and w2 = n+1
        while(i < n && j <= n) {
            if(w1[i] == w2[j]) {
                i++; j++;
            }
            else j++;
            // when chars dont match => move to next char in w2 
        }

        // true => when the w1 string is completely check out 
        return (i == n);
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        auto cmp = [&](const string &a, const string &b) {
            // smaller length words must appear first
            return a.length() < b.length();
        };

        sort(all(words), cmp);

        // now find out the length of longest string chain 
        vector<int> dp(n, 1);
        // dp[i] = length of the longest string chain ending in the ith word 

        for(int ind = 0; ind < n; ind++) {
            int maxi = 1;

            for(int j = 0; j < ind; j++) {
                if(isPredecessor(words[j], words[ind])) 
                    maxi = max(maxi, 1 + dp[j]);
            }

            dp[ind] = maxi;
        }

        // the res will be the max length of any sequence ending at any i 
        return *max_element(all(dp));
    }
};