#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/

typedef long long ll;

class Solution {
public:
    ll gcdSum(vector<int> &nums) {
        int n = nums.size();

        vector<int> prefixGCD(n);
        int mx = nums[0];
        prefixGCD[0] = nums[0];

        for(int i = 1; i < n; i++) {
        	mx = max(mx, nums[i]);
        	prefixGCD[i] = __gcd(mx, nums[i]);
        }

        sort(prefixGCD.begin(), prefixGCD.end());

        ll res = 0;
        int i = 0, j = n-1;

        while(i < j) res += __gcd(prefixGCD[i++], prefixGCD[j--]) * 1LL;
        // skip the middle element if the n is odd 

        return res;
    } 
};