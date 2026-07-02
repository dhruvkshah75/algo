// ================================================= backtracking ============================================== 

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/permutations-ii/description/

/* Explanation: backtracking 
   since this involves the nums having duplicate values 
   we must prevent the same permutation to appear => we must sort the array for skipping generation of same permutations 

   similar to permutations-I => we maintain a used or seen array to mark which number is already in the permutation 
   here we use a trick of skipping the number 
   if(nums[i] == nums[i-1] && !used[i-1]) continue; 
*/

class Solution {
private:
    int n;
    vector<vector<int>> res;

    void f(vector<int> &curr, vector<int> &nums, vector<bool> &used) {
        // base case: curr is now a permutation of the number 
        if((int)curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(used[i]) continue;

            // skip consecutive same elemtents to avoid duplicate perms 
            if(i >= 1 && nums[i] == nums[i-1] && !used[i-1]) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            f(curr, nums, used);

            // backtrack 
            curr.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> curr = {};
        vector<bool> used(n, false);

        f(curr, nums, used);

        return res;
    }
};