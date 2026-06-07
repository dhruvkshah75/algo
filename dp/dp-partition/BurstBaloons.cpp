// ================================================ partition dp ================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

// question link: https://leetcode.com/problems/burst-balloons/description/

// ========================================= Very Important Question ======================================================

/* This is a type of question where we are supposed to remove element and then analyze the rest of the array and keep doing this 
   until all of them proccessed 
*/

/* Explaination:
   Bursting the ballon removes the balloon => not create partition 
   Why use partition DP ??
   Different order of bursting balloons => gives diff results => therfore partition dp 

   Cannot solve the question in the forward direction by choosing which one to burst first 
   as this does not have independent subproblems 

   Instead start from the end (burst the balloon) which would be bursted at the last (in reverse order)
   i, j => denotes the subproblem of balloons not bursted yet 
   coins gained on bursting some ind (index) balloon in [i, j] would give use coins += arr[i - 1] * arr[ind] * arr[j + 1]
   Now the subproblem becomes f(i, ind-1) and f(ind+1, j)=> these subproblems are independent on dont depend on each other 

   f(i, j) => All balloons within [i,j] can be bursted in the reverse order 
*/

// ========================================================================================================================
//                                  Memoization - Top Down Approach dp 
// ========================================================================================================================

class Solution {
private:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        // base case: simply when the range is invalid 
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // try bursting all balloons [i,j] in the reverse order 
        int res = -1;

        for(int k = i; k <= j; k++) {
            int coins = nums[i-1] * nums[k] * nums[j+1] + f(i, k-1, nums, dp) + f(k+1, j, nums, dp);
            res = max(coins, res);
        } 

        return dp[i][j] = res;
    }

public:
    int maxCoins(vector<int>& nums) {
        // add a 1 in the start and in the end of the nums array 
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // first and last element are paddings of 1 => balloons lie in [1, n-2] 
        return f(1, n-2, nums, dp);
    }
};

// =========================================================================================================================
//                                Tabulation - Bottom Up approach dp
// =========================================================================================================================

class Solution {
private:
    /*
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        // base case: simply when the range is invalid 
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // try bursting all balloons [i,j] in the reverse order 
        int res = -1;

        for(int k = i; k <= j; k++) {
            int coins = nums[i-1] * nums[k] * nums[j+1] + f(i, k-1, nums, dp) + f(k+1, j, nums, dp);
            res = max(coins, res);
        } 

        return dp[i][j] = res;
    }
    */

public:
    int maxCoins(vector<int>& nums) {
        // add a 1 in the start and in the end of the nums array 
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // [i, j] contains all the valid balloons that can be bursted following the reverse order 

        // base case: i > j (partition is invalid) dp = 0
        // in memo => i went from 1 to n-2 => here i goes reverse (tabulation)
        // in memo => j went from n-2 to i (valid cases)

        for(int i = n-2; i >= 1; i--) {
            for(int j = i; j <= n-2; j++) {
                // try bursting all the balloons [i,j] in reverse 
                int res = -1;

                for(int k = i; k <= j; k++) {
                    int coins = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    res = max(res, coins);
                }

                dp[i][j] = res;
            }
        }

        // the final valid sequence of balloons is from [1....n-2]
        return dp[1][n-2];
    }
};