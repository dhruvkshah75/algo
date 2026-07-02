// ==================================================== backtracking ========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/word-squares-ii/description

/* Explanation: backtracking
   Simple brute force recursion to try out all possible options
   Pick the first string top with no conditions 
   and then pick in the order {top, left, right, bottom} with the required conditions 
*/ 

class Solution {
private:
    int n;
    vector<vector<string>> res;

    void f(vector<string> &curr, vector<string> &words, vector<bool> &seen) {
        int sz = curr.size();

        // base case: word sqaure is complete {top, left, right, bottom}
        if(sz == 4) {
            res.push_back(curr);
            return;
        }

        // try picking any string as the next in the curr 
        for(int i = 0; i < n; i++) {
            if(seen[i]) continue;

            // condition 1: pick top, conditions 2: pick left, condition 3: pick right, condition 4: pick bottom  

            if(sz == 0 || (sz == 1 && words[i][0] == curr[0][0]) || (sz == 2 && words[i][0] == curr[0][3])
               || (sz == 3 && words[i][0] == curr[1][3] && words[i][3] == curr[2][3])) {
                
                seen[i] = true;
                curr.push_back(words[i]);
                f(curr, words, seen);

                // backtrack
                seen[i] = false;
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words.size();

        vector<bool> seen(n, false);
        vector<string> curr = {};

        f(curr, words, seen);

        // the result must be sorted in lexicographically ascending order based on {top, left, right, bottom}
        sort(res.begin(), res.end());

        return res;
    }
};