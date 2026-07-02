// ===================================================== backtracking =============================================

#include<bits/stdc++.h> 
using namespace std;

// question link: https://leetcode.com/problems/combination-sum/description/

/* Explanation: bactracking 
   similar to knapsack with unlimited supply of each candidate 
   we use similar to logic of unbounded knapsack used in dp
*/

class Solution {
private:
    int n, target;
    vector<vector<int>> res;

    void f(vector<int> &curr, int ind, int curr_sum, vector<int> &nums) {
        // base case: all elements processed 
        if(ind == n) {
            if(curr_sum == target) res.push_back(curr);
            return;
        }

        // case of take and not take 
        if(curr_sum + nums[ind] <= target) {
            curr.push_back(nums[ind]);
            f(curr, ind, curr_sum + nums[ind], nums);

            // backtrack 
            curr.pop_back();
        }

        // skip the current element 
        f(curr, ind+1, curr_sum, nums);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        n = nums.size();
        this->target = target;

        vector<int> curr = {};

        f(curr, 0, 0, nums);

        return res;
    }
};