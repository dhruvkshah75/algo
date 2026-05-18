#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/subarray-sum-equals-k/description/


/*
    In this method the map is filled simultaneously while adding up 
    counts of the val = pf[i] - k occuring before the index i as after the index i the map is not filled yet
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pf(n, nums[0]);

        for(int i = 1; i < n; i++){
            pf[i] = pf[i-1] + nums[i];
        }

        unordered_map<int,int> mp;
        int result = 0;

        for(int i = 0; i < n; i++){
            // if the prefix itslef is k then update the ans 
            if(pf[i] == k) 
                result++;
            // search for pf[i] - k in the previous elements and add the count to ans 
            if(mp.count(pf[i] - k)) 
                result += mp[pf[i] - k];

            mp[pf[i]]++;
        }

        return result;
    }
};