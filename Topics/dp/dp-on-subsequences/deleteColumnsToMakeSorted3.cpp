// ============================================== dp knapsack variant =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/

/* Explanation: dp => knapsack like 
   here we have two choices at each indexed column to either delete the col or do not delete 
   we can simply delete the column at any ind without checking any constraint 
   but we can only choose not to delete is when => s[prev] <= s[ind] for all strings in strs 

   To explore all possible paths we use recurision with memoization 
   why is dp needed at all ??
   cannot apply greedy as some choice made at this point can influence choice later on and 
   can significantly affect the result
*/

class Solution {
private:
    int n, m;
    static constexpr int N = 1e2+1;
    int dp[N][N];

    int f(int ind, int prev, vector<string> &strs) {
        // base case: all columns explored 
        if(ind == m) return 0;

        if(dp[ind][prev] != -1) return dp[ind][prev];

        // 0-1 knapsack like choice 
        int del = 1 + f(ind+1, prev, strs);

        int not_del = 1e9;

        if(prev == m) 
            not_del = f(ind+1, ind, strs);
        else {
            // check if s[prev] <= s[ind] is valid for all strings 
            bool flag = true;

            for(int i = 0; i < n; i++) {
                if(strs[i][prev] > strs[i][ind]) {
                    flag = false;
                    break;
                }
            }

            if(flag) not_del = f(ind+1, ind, strs);
        }
        
        return dp[ind][prev] = min(not_del, del);
    }


public:
    int minDeletionSize(vector<string>& strs) {
        n = strs.size();
        m = strs[0].length();
        // n is the number of string in strs and m is the number of columns (length of each string)

        memset(dp, -1, sizeof(dp));

        // start with prev = n (meaning no prev row to check on)
        return f(0, m, strs);
    }
};