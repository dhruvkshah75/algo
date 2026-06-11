// =============================================== Longest Increasing Subsequence ===============================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/largest-divisible-subset/

// ===============================================================================================================================================
//                                              Bottom Up Approach Tabulation dp
// ===============================================================================================================================================

// simple lis questions => direct tabulation can easily be written without memoization 

/* Explaination: This is LIS variant => O(N^2) is allowed 
   assume the sequence to be x, y, z (x <= y <= z)
   Check the condition on adjacent pairs 
   y % x = 0 => y = k1x
   and z % y = 0 => z = k2y = k2k1x therefore z % x = 0
   So only validate the condition for consecutive pairs => LIS can be used 

   To not check the condition twice x % y or y % x => sort the array 
*/

#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(all(nums));

        vector<int> dp(n, 1), prev(n, -1);
        // dp[i] = length of longest seq ending in ith element 
        // prev array is used for bactracking and printing the sequence 

        for(int ind = 0; ind < n; ind++) {
            // get the max length in prefix [0...ind-1]
            int maxi = 1;

            for(int i = 0; i < ind; i++) {
                if(nums[ind] % nums[i] == 0 && maxi < 1 + dp[i]) {
                    maxi = 1 + dp[i];
                    prev[ind] = i;
                }
            }

            dp[ind] = maxi;
        }

        int longest = 1, max_ind = 0;

        for(int j = 0; j < n; j++) {
            if(longest < dp[j]) {
                longest = dp[j];
                max_ind = j;
            }
        }

        // now using prev and backtrackiing get the sequence 
        vector<int> res;

        while(max_ind != -1) {
            res.push_back(nums[max_ind]);
            max_ind = prev[max_ind];
        }

        // res array will be stored in the reverse order as we bactrack in the reverse dir 
        reverse(all(res));

        return res;
    }
};