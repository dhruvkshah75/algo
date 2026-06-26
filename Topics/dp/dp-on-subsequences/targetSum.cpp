// ==================================================================== dp on subsequences ===================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/target-sum/description/

// ==================================================================================================================================================================
//                                                          Top Down Approach dp (Memoization) 
// ==================================================================================================================================================================

/* We add the symbol + or - to the current number being processed and explore all possibilities and then we get 
   Pretty standard memoization solution where we explore all the paths 
   We use vector<unordered_map<int,int>> dp as the sums can go negative so we use a map to store 
   Or we could also add a offset that makes every value positive so it can be stored in the array 
*/

class RecursiveSolution {
private:    
    int target;

    int f(int x, int sum, vector<int> &nums, vector<unordered_map<int,int>> &dp) {
        // base case: last index reached
        if(x == 0) {    
            // + or - wont matter if element = 0
            if(nums[0] == 0 && sum == target) return 2;

            if((sum + nums[x] == target) || (sum - nums[x] == target)) return 1;
            else return 0;
        }

        if(dp[x].count(sum)) 
            return dp[x][sum];

        // explore all possible cases
        int plus = f(x - 1, sum + nums[x], nums, dp);
        int minus = f(x - 1, sum - nums[x], nums, dp);

        return dp[x][sum] = plus + minus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        this->target = target;

        // since the sum can go negative we must use maps 
        vector<unordered_map<int,int>> dp(n);

        return f(n - 1, 0, nums, dp);
    }
};


// =========================================================================================================================================================
//                                          Bottom up Approach (Tabulation) dp
// =========================================================================================================================================================

/* Constraints: 
   target is in range of [-1000, 1000]

   Simply start from the base cases: 
   for x == 0 => last index or first index 

   what sum can nums[0] make up to => this will be our base case 
   sum can be nums[0] or -nums[0] with offset (to prevent index going negative)

   if nums[0] = 0 then dp[0][offset] = 2 => so we use += 1 

   dp[0][nums[0] + offset] += 1;
   dp[0][-nums[0] + offset] += 1;

*/

class Solution {
public: 
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        int offset = 1000;

        int dp[n][2001];

        memset(dp, 0, sizeof(dp));

        // base case: index = 0 => sum +- nums[0] => here the sum = 0
        // with just nums[0] => we can either reach nums[0] or -nums[0]
        dp[0][nums[0] + offset] += 1;
        dp[0][-nums[0] + offset] += 1;

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= 2000; t++) {
                // t = sum + offset
                int plus = 0, minus = 0;

                if(t + nums[i] <= 2000) plus = dp[i - 1][t + nums[i]];

                if(t - nums[i] >= 0) minus = dp[i - 1][t - nums[i]];

                dp[i][t] = plus + minus;
            }
        }

        return dp[n - 1][target + offset];
    }
};


// This tabulation solution can be space optimised to get space Complexity to O(N) where N = 2001

class SpaceOptimisedSolution {
public: 
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        int offset = 1000;

        int prev[2001], curr[2001];
        // prev => [i - 1]th row and curr => [i]th row 

        memset(prev, 0, sizeof(prev));
        memset(curr, 0, sizeof(curr));

        // base case: index = 0 => sum +- nums[0] => here the sum = 0
        // with just nums[0] => we can either reach nums[0] or -nums[0]
        prev[nums[0] + offset] += 1;
        prev[-nums[0] + offset] += 1;

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= 2000; t++) {
                // t = sum + offset
                int plus = 0, minus = 0;

                if(t + nums[i] <= 2000) plus = prev[t + nums[i]];

                if(t - nums[i] >= 0) minus = prev[t - nums[i]];

                curr[t] = plus + minus;
            }
            swap(prev, curr);
        }

        // after all the iterations prev denotes the dp[n - 1][0....2000]
        return prev[target + offset];
    }
};

//                                                         Very Important Logic 
// ===========================================================================================================================================================
//                                         Different Approach => Solution using concept of (Count Subsets with sum K)
// ===========================================================================================================================================================

/* Important Note: 
   This question can be thoought of dividing the numbers into 2 subsets 
   subset 1: having positive sign in front 
   subset 2: having negative sign in front 
   
   eg: [1, 3, 2, 1]
   we do some assignment like => -1 + 2 + 3 - 1
   3 + 2 - (1 + 1)
   Subset 1: 3, 2 and Subset 2: 1, 1. The question is esentially S1 - S2 = diff = target

   This question is exactly same as count Subsets with sum K (note: case when the nums can be 0) where K = (target + total) / 2
   This solution is better as the dp size is reduced too dp[21][1001]
*/

#define all(x) x.begin(), x.end()

class Solution {
private: 
    int target;

    int dp[21][1001];
    // n <= 20 and sum(nums[i]) <= 1001

    int f(int x, int sum, vector<int> &nums) {
        // base case: last index reached 
        if(x == 0) {
            if(sum == 0 && nums[0] == 0) return 2; 

            if(sum == 0 || sum == nums[0]) return 1;
            else return 0;
        }

        if(dp[x][sum] != -1) return dp[x][sum];

        // explore all options of selecting the num in subset 
        int not_take = f(x - 1, sum, nums);
        int take = 0;
        if(sum >= nums[x]) take = f(x - 1, sum - nums[x], nums);

        return dp[x][sum] = take + not_take;
    }

public:     
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();

        int total = accumulate(all(nums), 0);

        // simple base checks to prevent complete calc
        if(target > total || target < -total) return 0;

        // S1 - S2 = tar and S1 + S2 = total => idealy find a subset whose sum is (tar + total)/ 2
        // since subset S1 sum is (target + total) / 2 => it must be even 
        if((target + total) & 1) return 0;

        this->target = (target + total) / 2;

        memset(dp, -1, sizeof(dp));

        return f(n - 1, this->target, nums);
    }
};