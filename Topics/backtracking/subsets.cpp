// ========================================== backtracking ========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/subsets/description/

/* Explanation: backtracking 
   Creating the subsets => two ways in which this can be done => using bit masking and backtracking + recursion 
   simple example of take or not take => duplicate subsets are not created because nums contains unique elements  
*/

class Solution {
private:
    int n;
    vector<vector<int>> res;

    void f(vector<int> &subset, int ind, vector<int> &nums) {
        // base case: when all numbers are processed 
        if(ind == n) {
            res.push_back(subset);
            return;
        }

        // two cases => pick the element or not 
        subset.push_back(nums[ind]);
        f(subset, ind+1, nums);

        subset.pop_back();
        f(subset, ind+1, nums);

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> subset = {};

        f(subset, 0, nums);

        return res;
    }
};