// ============================================================ 0-1 knapsack dp =================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

// ====================================================== Very Important Question ===============================================================

/* Explanation: knapsack dp variant 
   Firstly use prefix sum for getting sum of the subarry in O(1)
   At each index we have two choices 
   1. take the subarray starting at the current index (ind) and move on to the next non overlapping subarry (ind+k)
   2. skip this subarray starting at (ind) => move onto the next subarray ind+1
   Take the max of these to get the max sum 

   But the answer is not the to print the maximum subarray sum => we need the starting indices for that 
   so we must trace back from from dp[i][j] array back when the subarray is selected 

   recurrence => f(ind, picked) => picked {0,1,2}

   we start tracing back from the result => dp[1][0] 
   i.e i = 1 and j = 0 => we then move onto the the next indices on how exactly how we got here 
   using the main code of tabulation 
   Whenever take >= not_take we add to the sum so add that index to the resulting array 

   Avoid using INT_MIN for invalid cases as it might cause overflow => so we keep -1e9 to prevent overflow
*/

class Solution {
private:
    vector<vector<int>> dp;

    /*
    ll f(int ind, int picked, int n, int k, vector<int> &prefix) {
        // base case: when all 3 subarrays picked 
        if(picked == 3) return 0;

        // base case: reached last index and 3 subarrays are not picked (invalid case)
        if(ind > n) return -1e15;

        // 0-1 knapsack logic 
        ll not_take = f(ind+1, picked, n, k, prefix);

        ll take = INT_MIN;
        if(ind+k-1 <= n) take = prefix[ind+k-1] - prefix[ind-1] + f(ind+k, picked+1, n, k, prefix);

        return max(not_take, take);
    } */

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        dp.resize(n+2, vector<int>(4, -1e9));

        vector<int> prefix(n+1, 0);

        for(int i = 1; i <= n; i++) 
            prefix[i] = prefix[i-1] + nums[i-1];


        // base case: picked = 3 => dp = 0
        for(int i = 0; i <= n+1; i++)
            dp[i][3] = 0;

        // base case: last index is invalid dp = INT_MIN
        
        for(int ind = n; ind >= 1; ind--) {
            for(int picked = 2; picked >= 0; picked--) {
                // 0-1 knapsack logic 
                int not_take = dp[ind+1][picked];

                int take = -1e9;
                if(ind+k-1 <= n) take = prefix[ind+k-1] - prefix[ind-1] + dp[ind+k][picked+1];

                dp[ind][picked] = max(take, not_take);
            }
        }

        cout << dp[1][0] << endl;

        vector<int> res;
        // we start backtracking from the result on exactly how we reached the final result 
        int i = 1, j = 0;   

        while(i <= n && j < 3) {
            int not_take = dp[i+1][j];
            
            int take = -1e9;
            if(i+k-1 <= n) take = prefix[i+k-1] - prefix[i-1] + dp[i+k][j+1];

            if(take >= not_take) {
                res.push_back(i-1);
                i += k;
                j += 1;
            }
            else i++;
        } 

        return res;
    }
};
// Time Complexity = O(N), Space Complexity = O(N)
