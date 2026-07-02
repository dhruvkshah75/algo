// ============================================= monotonic stack ===========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/

/* Explanation: monotonic increasing stack 
   consider each element as the min element of the subarray and check till where it extends 
   we want to maximize the score so maximize the length in a way and keeping an account of the min 
   so maximize => min * len

   so keeping the current element as min the subarray will extend till pse and nse 
   pse = x, nse = y ==> subarray is [x+1,...y-1] => size = y-x-1
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int res = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : nums[i];
            // curr element is the nse 

            while(!st.empty() && nums[st.top()] > curr) {
                int idx = st.top();
                st.pop();

                // subarray is [x+1,...,y-1]
                int x = -1, y = i;
                if(!st.empty()) x = st.top();

                if(k > x && k < y) {
                    int score = nums[idx] * (y-x-1);
                    res = max(res, score);
                }
            }

            st.push(i);
        }

        return res;
    }
};