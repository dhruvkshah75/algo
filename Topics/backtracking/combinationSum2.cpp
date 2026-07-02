// =================================================== backtracking =============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/combination-sum-ii/description/

/* Explanation: backtracking 
   Very Important logic => candidates here are not unique 
   the result array must have number in sorted order => so sort the array in the start 
   so all the same occurences of the number will be toegthor

   this has the same logic of take or not_take the element (0-1 knapsack)
   here the modifaction comes in case of not_taking the element 
   we skip all the occurrences of the same element to prevent duplicates being generated 

   Take => will figure out how many times we want to take some number x 
   not_take => skipping all the occurrences => directly go onto the next number preventing duplicates 
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
            f(curr, ind+1, curr_sum + nums[ind], nums);

            // backtrack 
            curr.pop_back();
        }

        // skip the current element (all occurrences of the num)
        int nxt = ind;
        while(nxt < n && nums[nxt] == nums[ind]) nxt++;

        f(curr, nxt, curr_sum, nums);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        n = nums.size();
        this->target = target;
        
        // the combinations formed must be in sorted order 
        sort(nums.begin(), nums.end());

        vector<int> curr = {};

        f(curr, 0, 0, nums);

        return res;
    }
};