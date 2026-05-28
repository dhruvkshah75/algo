// ==================================================== dp on Subsequences ==============================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pii pair<int,int>
#define pll pair<ll,ll>

// question link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

// the actual question constraints cannot be solved by dp => rather can be solved by generating all subsets (as N <= 15)

/* NOTE:
   to solve the question when the numbers lie in the range of question subset sum equal to target 

   We use the concept of subset sum equal to target (tabulation approach) => Important note is what does the dp[index][target] indicate here 
   it tells what all sums of the subsets is possible for the given array 

   dp[n-1][0 ... target] = true / false => this will give all the possible subset sums => take the min subset difference in the end 

   This method fails if the nums values are very bigger in the range of 1e5 or 1e6 and breaks if there are negative numbers 
   as dp[index][target] => target cant become negative 
*/

class Solution {
public: 
    int minSubsetSumDiff(vector<int> &nums) {
        int n = nums.size();

        int total = accumulate(all(nums), 0);

        vector<vector<bool>> dp(n, vector<bool>(total + 1, false));

        // base cases => for index 0 
        dp[0][nums[0]] = true;

        // base case for target = 0;
        for(int i = 0; i < n; i++) 
            dp[i][0] = true;

        for(int i = 1; i < n; i++) {
            for(int target = 1; target <= total; target++) {
                bool not_take = dp[i - 1][target];

                bool take = false;
                if(target >= nums[i]) take = dp[i - 1][target - nums[i]];

                dp[i][target] = (take || not_take);
            }
        }


        // now the last row of dp vector gives all the possible sums of subsets in the array => now calculate the min of them 
        int res = 1e8;

        for(int sum = 1; sum < total; sum++) {
            // dont consider the case when either subset is empty set 
            if(dp[n - 1][sum]) {
                int diff = abs(total - 2 * sum);
                res = min(res, diff);
            }
        }

        return res;
    }
};