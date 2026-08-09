// ============================== dp ============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description

/**
 * Explanation: knapsack style dp 
 * Here we can use simple pick or not pick dp here for each element we would have 3 options to work out with 
 * 1. skip the element do not use it for any of the sequences 
 * 2. pick the element for seq1 and update the gcd for the sequence 1 
 * 3. similarly do this for seq2 and update the gcd of the second seq 
 * 
 * recurrence => f(ind, g1, g2)
 * 
 * note: nums[i] <= 200 so gcd of elements <= 200 
 * */

typedef long long ll;

class Solution {
private:
	const int MOD = 1e9+7;
	int n;
	vector<vector<vector<int>>> dp;

	int f(int ind, int g1, int g2, vector<int> &nums) {
		// base case: explored all elements in the nums
		if(ind == n) {
			if(g1 == 0 || g2 == 0) return 0;

			return (g1 == g2); 
		}

		if(dp[ind][g1][g2] != -1) return dp[ind][g1][g2];

		// try all 3 possible options for nums[ind]
		ll res = 0;
		res = (res + f(ind+1, g1, g2, nums)) % MOD;

		int nxt_g1 = (g1 == 0) ? nums[ind] : __gcd(g1, nums[ind]);
		res = (res + f(ind+1, nxt_g1, g2, nums)) % MOD;

		int nxt_g2 = (g2 == 0) ? nums[ind] : __gcd(g2, nums[ind]);
		res = (res + f(ind+1, g1, nxt_g2, nums)) % MOD;

		return dp[ind][g1][g2] = res % MOD;
	}	

public:
    int subsequencePairCount(vector<int> &nums) {
        n = nums.size();

        // g1 and g2 <= mx
        int mx = *max_element(nums.begin(), nums.end());

        dp.resize(n, vector<vector<int>>(mx+1, vector<int>(mx+1, -1)));

        // initially g1 = 0 and g2 = 0 => indicating no element in the seq yet 
        return f(0, 0, 0, nums);
    }
};