// ========================================= backtracking =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/permutations/description/

/* Explanation: backtracking 
   what is a permutation ? => aranging the elements in any order 
   mainatain a hash table to mark which number is already included in the curr 
   try placing any possible number at the current position if not already placed 
*/

class Solution {
private:
    int n;
    vector<vector<int>> res;

    void f(vector<int> &curr, vector<bool> &seen, vector<int> &nums) {
        // base case: curr contains all elements 
        if((int)curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(seen[i]) continue;

            curr.push_back(nums[i]);
            seen[i] = true;
            f(curr, seen, nums);

            // backtrack
            seen[i] = false;
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();

        vector<int> perm = {};
        vector<bool> seen(n, false);

        f(perm, seen, nums);

        return res;
    }
};