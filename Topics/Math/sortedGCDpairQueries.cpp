// =================================== math + number theory ======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sorted-gcd-pair-queries/description/

/**
 * all nums[i] <= 5e4
 * so all the gcds lie in this range as well 
 * we must figure out a way to calculate the number of pairs from the nums array that have gcd = g
 * so we can do this for all g's 
 * and then taking the prefix sum of this array will help us to answer the queries using binary search 
 * as prefix sum is sorted in increasing order => lower bound 
 * 
 * Now how to calculate the number of pairs whose gcd = g for all values <= 5e4
 * We use the concept of inclusion and exclusion 
 * 
 * PairsDivisible[g] = no of pairs that are divisible by g from the nums array
 * gcdCnt[g] = number of pairs whose gcd = g 
 * 
 * use the formula => gcdCnt[g] = pairsDivisible[g] - 
 * */

typedef long long ll;

class Solution {
public:
    vector<int> gcdValues(vector<int> &nums, vector<ll> &queries) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

       	vector<int> freq(mx+1, 0);
       	for(int x: nums)
       		freq[x]++;

       	vector<ll> gcdCnt(mx+1, 0);

       	// build the pairsDivisible array 
       	for(int g = mx; g >= 1; g--) {
       		ll cnt = 0;

       		// cnt numbers divisible by g 
       		for(int m = g; m <= mx; m += g) 
       			cnt += freq[m];

       		// gcdCnt[g] = pairsDivisible[g] - gcdCnt[2*g] - gcdCnt[3*g] - ....
       		ll pairs_div = cnt * (cnt - 1) / 2;
       		gcdCnt[g] = pairs_div;

       		for(int m = 2 * g; m <= mx; m += g) 
       			gcdCnt[g] -= gcdCnt[m]; 

       	}

       	// form the prefix sum of the gcdCnt array for answering the queries 
       	vector<ll> prefix(mx+1, 0);
       	for(int g = 1; g <= mx; g++) 
       		prefix[g] = prefix[g-1] + gcdCnt[g];

       	// Answer the queries in O(Log(mx))
       	vector<int> ans;

       	for(ll q: queries) {
       		// queries are 0 based indexing => convert to 1 based indexing 
       		auto it = lower_bound(prefix.begin(), prefix.end(), q+1);
       		int gcd = distance(prefix.begin(), it);

       		ans.push_back(gcd);
       	}

       	return ans;
    }
};