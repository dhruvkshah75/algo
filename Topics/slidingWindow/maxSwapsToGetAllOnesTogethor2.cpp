// ================================================== sliding window ==============================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/

/* Explanation: sliding window + pure two pointers 
   Swaps can be add at any position => so to get minimum number of swaps 
   To deal with the part of circular array => append the array to the end of itself

   The final answer to deal with would be minimum number of zeros in a window of size k
   So if there k ones in the entire array => in a segment with k elements 
   Min number of moves needed to make it 1s would be the zeros in it 
   Essentially the question => So calculate the min number of zeros in a window of size k
*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // base case: if size of the array is 1 
        if(n == 1) return 0;

        int ones = accumulate(nums.begin(), nums.end(), 0);

        // attach the nums to the end to deal with circular array 
        for(int i = 0; i < n; i++) nums.push_back(nums[i]);

        // use sliiding window of fixed size ones to get the minimum number of zeros in the window  

        int zeros = 0, l = 0, r = ones-1;
        // start with fixed window of size ones => [l...r] 
        for(int i = 0; i < ones; i++) 
            if(nums[i] == 0) zeros++;

        int res = zeros;

        while(r+1 < (int)nums.size()) {
            if(nums[r+1] == 0) zeros++;
            if(nums[l] == 0) zeros--;

            res = min(res, zeros);

            l++; r++;
        }

        return res;
    }
};