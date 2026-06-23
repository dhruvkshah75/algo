#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/greatest-sum-divisible-by-three/description/

// ====================================================== Very Important Question ==================================================

// ================================================= Knapsack variant and multi state dp ===========================================

/* Explanation: linear dp or knapsack like dp + multi state (hidden 2nd state)
   recurrence f(ind) => returns the max sum that is divisible by 3 
   at each index => 2 options => 1. take the current element and add into the sum 
   2. do not take the current element into the sum and move to the next index 
   We need to check the divisibility at the end of exploring all cases => so we maintain the remainder of the sum 
   and in the base case after all choices of n elements => if rem = 0 then the sum maintained is valid => return 0
   if rem is not 0 then sum maintained is invalid => make the sum very small by adding INT_MIN */

class Solution {
private:
    static constexpr int N = 4e4+1;
    int dp[N][3];

    int f(int ind, int rem, vector<int> &nums, int n) {
        // base case: when all n elements are processed 
        if(ind == n) {
            if(rem == 0) return 0;
            else return INT_MIN;
        }

        if(dp[ind][rem] != -1) return dp[ind][rem];

        // explore 0-1 knapsack cases
        int not_take = f(ind+1, rem, nums, n);

        int new_rem = (rem + nums[ind]) % 3;
        int take = nums[ind] + f(ind+1, new_rem, nums, n);

        return dp[ind][rem] = max(take, not_take);
    }

public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));

        // starting from the 0th element and remainder as 0
        return f(0, 0, nums, n);
    }
};