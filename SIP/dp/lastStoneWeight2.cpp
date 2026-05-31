// ==================================================================== dp on subsequences =====================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), s.rend()

// question link: https://leetcode.com/problems/last-stone-weight-ii/description 

/* Very Important Question: this question looks like simulation but is 0/1 knapsack 
   Dividing the stones into 2 subsets => S1 - S2 = diff (we want to minimize this diff) 
   This is the same as target sum where we assign + and - sign in front of each weight and get the min possible wieght 
   which is equivalent to dividing numbers into 2 subsets S1, S2 and S1 - S2 = diff 

   eg: {a, b, c, d} => 
       1. smash stones a and b => new stone = |a - b| 
       2. smash stones c and d => new stone = |c - d| 
       3. now smash stone |a - b| and |c - d| = ||a - b| - |c - d|| => (a + c) - (c + d)
          Which is similar to S1 - S2 = diff (minimize the diff)
*/

// ====================================================================================================================================================================
//                                                           Tabulation (Bottom up Approach) dp 
// ====================================================================================================================================================================

#define all(x) x.begin(), x.end()

class Solution {
private:
    /*
    // does there exist a subset with sum = target
    bool f(int x, int curr_sum, vector<int> &stones, vector<vector<int>> &dp) {
        // base case: curr_sum becomes 0 
        if(curr_sum == 0) return true;

        // base case: last index reached 
        if(x == 0) return (curr_sum == stones[0]);

        if(dp[x][curr_sum] != -1) 
            return dp[x][curr_sum];

        // apply 0/1 Knapsack 
        bool not_take = f(x - 1, curr_sum, stones, dp);

        bool take = false;
        if(curr_sum >= stones[x]) take = f(x - 1, curr_sum - stones[x], stones, dp);

        return dp[x][curr_sum] = (take || not_take);
    }
    */

public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size(), total = accumulate(all(stones), 0);

        // this is the max sum required for optimal ans for subset sum
        int target = total / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // S1 - S2 = diff and S1 + S2 = total ==> from this we get diff = |total - 2S1|

        // base cases: x = 0 and sum = 0
        if(stones[0] <= target) dp[0][stones[0]] = true;

        for(int i = 0; i < n; i++)  
            dp[i][0] = true;

        for(int i = 1; i < n; i++) {
            for(int sum = 1; sum <= target; sum++) {
                // 0/1 kanpsack conditions
                bool not_take = dp[i - 1][sum];
                bool take = false;
                if(sum >= stones[i]) take = dp[i - 1][sum - stones[i]];

                dp[i][sum] = take || not_take;
            }
        }

        // Now the dp[n - 1] contains all the possible subset sums of s1 => [0, target]
        // using dp[n - 1] get the minimum possible diff of s1 - s2 => diff = total - 2*s1
        int res = 1e8;

        for(int s1 = 0; s1 <= target; s1++) {
            if(dp[n - 1][s1]) {
                res = min(res, total - 2 * s1);
            }
        }
        
        return (res == 1e8) ? 0 : res;
    }
};

// ================================================================= Space Optimised Solution ==========================================================================

#define all(x) x.begin(), x.end()

class Solution {
private:
    /*
    // does there exist a subset with sum = target
    bool f(int x, int curr_sum, vector<int> &stones, vector<vector<int>> &dp) {
        // base case: curr_sum becomes 0 
        if(curr_sum == 0) return true;

        // base case: last index reached 
        if(x == 0) return (curr_sum == stones[0]);

        if(dp[x][curr_sum] != -1) 
            return dp[x][curr_sum];

        // apply 0/1 Knapsack 
        bool not_take = f(x - 1, curr_sum, stones, dp);

        bool take = false;
        if(curr_sum >= stones[x]) take = f(x - 1, curr_sum - stones[x], stones, dp);

        return dp[x][curr_sum] = (take || not_take);
    }
    */

public:
    int lastStoneWeightII(vector<int>& stones) {
        // this question looks like simulation but is 0/1 knapsack 
        int n = stones.size();
        int total = accumulate(all(stones), 0);

        // this is the max sum required for optimal ans for subset sum
        int target = total / 2;

        vector<bool> prev(target + 1, false), curr(target + 1, false);

        // S1 - S2 = diff and S1 + S2 = total ==> from this we get diff = |total - 2S1|

        // base cases: x = 0 and sum = 0
        if(stones[0] <= target) prev[stones[0]] = true;
        // base case: sum = 0 => dp[0][0] = true
        prev[0] = true;

        for(int i = 1; i < n; i++) {
            // base case: sum = 0 
            curr[0] = true;

            for(int sum = 1; sum <= target; sum++) {
                // 0/1 kanpsack conditions
                bool not_take = prev[sum];
                bool take = false;
                if(sum >= stones[i]) take = prev[sum - stones[i]];

                curr[sum] = take || not_take;
            }

            swap(prev, curr);
        }

        // Now the dp[n - 1] contains all the possible subset sums of s1 
        // using dp[n - 1] get the minimum possible diff of s1 - s2
        int res = 1e8;

        for(int s1 = 0; s1 <= target; s1++) {
            if(prev[s1]) {
                res = min(res, total - 2 * s1);
            }
        }
        
        return (res == 1e8) ? 0 : res;
    }
};