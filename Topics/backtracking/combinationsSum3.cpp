// ======================================================== backtracking ========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/combination-sum-iii/description/

/* Explanation: backtracking 
   We are supposed to form a sum of n using K unique numbers between [1..9]
   form all possible combinations => for this we place numbers in the increasing order 
   so maintain a prev value => prev => start new possible combinations from prev+1
   and when k numbers are used then we stop execution
*/

class Solution {
private:
    int n, k;
    vector<vector<int>> res;

    void f(vector<int> &curr, int prev, int curr_sum, vector<bool> &used) {
        // base case: when k numbers are used (sum should be n)
        if((int)curr.size() == k) {
            if(curr_sum == n) res.push_back(curr);
            return;
        }

        // try using new numbers 
        for(int num = prev+1; num <= 9; num++) {
            if(used[num] || curr_sum + num > n) continue;

            curr.push_back(num);
            used[num] = true;

            f(curr, num, curr_sum + num, used);

            // backtrack => to allow other combinations 
            curr.pop_back();
            used[num] = false;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->n = n;

        vector<int> curr = {};
        vector<bool> used(10, false);

        f(curr, 0, 0, used);

        return res;
    }
};
