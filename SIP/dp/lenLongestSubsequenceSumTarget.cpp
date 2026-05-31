// ==================================================================== dp on subsequences ===================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/description/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

/* If the case is not be considered in the result => return a very small number so it is not counted 
   very small number here is -1e9
*/

class RecursiveSolution {
private: 
    int f(int x, int W, vector<int> &nums, vector<vector<int>> &dp) {
        // base case: all indices proccessed => if sum is valid then return 0 else avery small number 
        if(x < 0) {
            if(W == 0) return 0;
            else return -1e9;
        }

        if(dp[x][W] != -1) return dp[x][W];

        // explore all the cases of picking the xth element or not 
        int not_take = f(x - 1, W, nums, dp);
        int take = -1e9;
        if(W >= nums[x]) take = 1 + f(x - 1, W - nums[x], nums, dp);

        return dp[x][W] = max(take, not_take);
    }

public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int res = f(n - 1, target, nums, dp);

        return (res <= 0) ? -1 : res;
    }
};

// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

/* If the case is not be considered in the result => return a very small number so it is not counted 
   very small number here is -1e9 => means reaching sum = target from here is not possible (unreachable)
   very important base case: dp[0][0] = 0;
   Empty subsequence with sum = 0 also has lenght = 0 => dp = 0 */

class Solution {
public: 
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1e9));
        // dp[i][j] = length of longest subsequence till i th index whose sum is j 

        // empty subsequence with sum = 0 has len = 0
        dp[0][0] = 0;

        // base case: x = 0 => then the for sum = nums[0] 
        if(nums[0] <= target) dp[0][nums[0]] = 1;

        for(int i = 1; i < n; i++) {
            for(int s = 0; s <= target; s++) {
                // apply 0/1 Knapsack => either take nums[i] or not 
                int not_take = dp[i - 1][s];

                int take = -1e9;
                if(s >= nums[i]) take = 1 + dp[i - 1][s - nums[i]];

                dp[i][s] = max(take, not_take);
            }
        }

        // return the longest length of subsequence till the end (n - 1 th index) whose sum is target
        int res = dp[n - 1][target];

        return (res <= 0) ? -1 : res;
    }
};

// the above solution can be space optimised to get space complexity = O(target)

// ====================================================== Space Optimised Solution ==========================================================================================

class SpaceOptimisedSolution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prev(target + 1, -1e9), curr(target + 1, -1e9);
        // dp[i][j] = length of longest subsequence till i th index whose sum is j 
        // prev => dp[i - 1] and curr => dp[i]

        // empty subsequence with sum = 0 has len = 0
        prev[0] = 0;

        // base case: x = 0 => then the for sum = nums[0] 
        if(nums[0] <= target) prev[nums[0]] = 1;

        for(int i = 1; i < n; i++) {
            for(int s = 0; s <= target; s++) {
                // apply 0/1 Knapsack => either take nums[i] or not 
                int not_take = prev[s];

                int take = -1e9;
                if(s >= nums[i]) take = 1 + prev[s - nums[i]];

                curr[s] = max(take, not_take);
            }

            swap(prev, curr);
        }

        // return the longest length of subsequence till the end (n - 1 th index) whose sum is target
        // after all iteration prev denotes dp[n - 1]
        int res = prev[target];

        return (res <= 0) ? -1 : res;
    }
};


// this can be further space optimised to use only one 1d array instead of prev and curr 
// since each calculation depends only the elements before it of the same row so start the inner loop in reverse direction 

class SuperSpaceOptimisedSolution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(target + 1, -1e9);
        // dp[j] = length of longest subsequence till iith index whose sum is j
        
        // empty subsequence with sum = 0 has len = 0
        dp[0] = 0;

        // base case: x = 0 => then the for sum = nums[0] 
        if(nums[0] <= target) dp[nums[0]] = 1;

        for(int i = 1; i < n; i++) {
            for(int s = target; s >= 0; s--) {
                // apply 0/1 Knapsack => either take nums[i] or not 
                int not_take = dp[s];

                int take = -1e9;
                if(s >= nums[i]) take = 1 + dp[s - nums[i]];

                dp[s] = max(take, not_take);
            }
        }

        // return the longest length of subsequence till the end (n - 1 th index) whose sum is target
        int res = dp[target];

        return (res <= 0) ? -1 : res;
    }
};