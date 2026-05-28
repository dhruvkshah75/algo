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

class Solution {
public: 
    int findTargetSum(vector<int> &nums, int target) {
        int n = nums.size();

        vector<unordered_map<int,int>> dp(n);

        // base case: index = 0 
        
    }
};