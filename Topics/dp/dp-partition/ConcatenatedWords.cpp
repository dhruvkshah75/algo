#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/concatenated-words/description/

// Simple question based on front partition dp 

/* Explanation: front partition dp 
   The logic to identify if the words[i] is a concatenated word is using front partition dp 
   and is very similar to word break. For each word check if is a concatenated word in O(L^2) 
   Recurrence => f(ind) returns max number of partitions created 
   Note => (a concatenated word must have at least 2 partitions) 
   
   Note on Time Complexity: 
   Time Complexity = O(N * L * L)
   Given constraints: 1 <= sum(words[i].length()) <= 1e5  ==> O(N * L) <= 1e5
   Total time complexity <= 3 * 1e6
   */

class Solution {
private:
    static constexpr int N = 30;
    int dp[N];
    unordered_set<string> w;

    int f(int ind, string &s) {
        // base case: entire string processed 
        if(ind == s.length()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int maxi = -1e9;
        string curr = "";

        for(int j = ind; j < s.length(); j++) {
            // create a partition j | j+1
            curr += s[j];
            
            if(w.count(curr)) 
                maxi = max(maxi, 1 + f(j+1, s));
        }

        return dp[ind] = maxi;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        
        // store all the strings in the hash set
        w = unordered_set<string>(words.begin(), words.end());

        vector<string> res;

        for(int i = 0; i < n; i++) {
            memset(dp, -1, sizeof(dp));

            if(f(0, words[i]) >= 2) {
                res.push_back(words[i]);
            }
        }

        return res;
    }
};
