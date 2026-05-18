#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/contiguous-array/description/

// very similar to subarray with sum = k => in this question we mark 0 as -1 and then take prefix sum
// and then search for prefix[i] - prefix[j] = 0;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // similar question to contiguos subarray => solve using prefix sum 
        // consider 1 as +1 and 0 as -1 and search for the number of 0s 
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) 
                nums[i] -= 1;
        }

        int prefix = 0;
        unordered_map<int,int> mp;
         
        int maxLength = 0;

        for(int i = 0; i < n; i++) {
            prefix += nums[i];
            if(prefix == 0) {
                // 0 to i is the contiguous segment 
                maxLength = max(maxLength, i + 1);
            }

            if(mp.find(prefix) != mp.end()) {
                int j = mp[prefix];
                maxLength = max(maxLength, i - j);
            }
            else {
                // only add this entry to map if it does not exist in the map 
                mp[prefix] = i;
            }
        }

        return maxLength;
    }
};