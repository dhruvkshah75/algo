// ============================================ backtracking ===========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/valid-binary-strings-with-cost-limit/description/

class Solution {
private:
    int n, k;
    vector<string> res;

    void f(string &curr, int curr_sum) {
        int sz = curr.size();

        // base case: when entire string is formed and curr_sum <= k
        if(sz == n) {
            if(curr_sum <= k) res.push_back(curr);
            return;
        }

        // put a zero at the end of the string 
        curr.push_back('0');
        f(curr, curr_sum);

        // backtrack 
        curr.pop_back();

        // put a one at the end of string only if condition is satisfied 
        if(sz == 0 || (sz >= 1 && curr.back() != '1' && curr_sum + sz <= k)) {
            curr.push_back('1');
            // the 1 is placed at index = sz of string curr
            f(curr, curr_sum + sz);

            // backtrack
            curr.pop_back();
        }
    }

public:
    vector<string> generateValidStrings(int n, int k) {
        this->n = n;
        this->k = k;

        string curr = "";
        f(curr, 0);

        return res;
    }
};