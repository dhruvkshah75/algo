// ================================================ backtracking ====================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

/* Explanation: backtracking 
   each number maps to certain characters => store them in a map and then try updating each one to a letter 
   Apply simple backtracking for getting all possible combinations 
*/

class Solution {
private:
    int n;
    unordered_map<int,string> mp;
    vector<string> res;

    void f(string &curr, int ind, string &digits) {
        // base case: all digits explored 
        if(ind == n) {
            res.push_back(curr);
            return;
        }

        for(char c: mp[digits[ind]-'0']) {
            curr.push_back(c);
            f(curr, ind+1, digits);

            // backtrack 
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string &digits) {
        n = digits.length();

        mp[2] = "abc"; mp[3] = "def"; mp[4] = "ghi";
        mp[5] = "jkl"; mp[6] = "mno"; mp[7] = "pqrs";
        mp[8] = "tuv"; mp[9] = "wxyz";

        string curr = "";
        f(curr, 0, digits);

        return res;
    }
};