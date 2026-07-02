// ====================================================== backtracking ==============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/subsets-ii/description/

/* Explanation: backtracking 
   similar to combination sum 2 => we must only return non duplicate subsets 
   sort the nums and then take the elements to consider all possible scenarios 
   and in not_take case skip out all the same occurrences of current element to prevent duplicates 
*/

class Solution {
private:
    int n;
    vector<vector<int>> res;

    void f(vector<int> &curr, int ind, vector<int> &nums) {
        // base case: all elements processed 
        if(ind == n) {
            res.push_back(curr);
            return;
        }

        // 0-1 knapsack logic of take and not take 
        curr.push_back(nums[ind]);
        f(curr, ind+1, nums);

        // backtrack 
        curr.pop_back();

        // not_take case skip all occurrences of nums[ind]
        int nxt = ind+1;
        while(nxt < n && nums[nxt] == nums[ind]) nxt++;

        f(curr, nxt, nums);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();

        // sort the given nums to get all subsets in sorted order and prevent duplicates
        sort(nums.begin(), nums.end());

        vector<int> curr = {};
        f(curr, 0, nums);
        
        return res;
    }
};