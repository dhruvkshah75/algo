// ================================================================== front partition dp ====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/word-break/description/

// very important example of fron partition dp

/* Explanation: question is based on partitioning the given string 
   based on front partition as we start creating partitions from the ind = 0 till ind = n 
   Pretty basic question on front partition we only create a valid partition if the substring 
   exists in the word dict

   recurrence => f(ind) => only 1 state needed for using the concept of front partition 
   and store all the words in unordered_set for easy check
*/

class Solution {
private:
    static constexpr int N = 300;
    int dp[N];
    unordered_set<string> words;

    bool f(int ind, string &s) {
        // base case: string could be completely divided into valid substrings 
        if(ind == s.length()) return true;

        if(dp[ind] != -1) return (dp[ind] == 1);

        // try all partitions starting from ind till n
        bool res = false;
        string curr = "";

        for(int j = ind; j < s.length(); j++) {
            // create a split bw j | j+1
            curr += s[j];

            if(words.count(curr)) 
                res = res || f(j+1, s);
        }

        return dp[ind] = res;
    }

public:
    bool wordBreak(string &s, vector<string>& wordDict) {
        
        words.clear();
        memset(dp, -1, sizeof(dp));

        // store all words in dict in a hash map for O(1) lookup
        for(string &s: wordDict)
            words.insert(s);

        // start by making partitions from the 0th index 
        return f(0, s);
    }
};