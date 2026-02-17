#include<bits/stdc++.h>
using namespace std;

// questionLink: https://leetcode.com/problems/next-greater-element-ii/description/
// MONOTONIC STACK => decreasing monotonic stack 

/*
    Virtually double the array:
    [2, 10, 12, 1, 11] 2, 10, 12, 1, 11 => doubling the array 
    what will the circular array for 10 
    [2, || 10, 12, 1, 11] 2 ||,  10, 12, 1, 11 
    circular array for 10 => 10, 12, 1, 11, 2 
*/

// problem occurs when there are -1s in the result after the max element 

class Solution {
public:
    vector<int> ngeCircular(vector<int>& nums) {
        // problem occurs for the elements after the max element in the array
        int n = nums.size();
        vector<int> result(n, -1);

        stack<int> st;
        // we virtually double the array and do it in the revserse direction 
        // we run the this loop for the virtual part 
        for(int i = 2*n-1; i>=0; i--) {
            int curr = nums[i % n];    // i % n gives the index in the real array 
            
            while(!st.empty() && curr >= nums[st.top() % n]) {
                st.pop();
            }

            if(i < n) {
                if(!st.empty()) {
                    int ngeIndex = st.top() % n;
                    result[i] = nums[ngeIndex];
                }
            }

            st.push(i);
        }

        return result;
    }
};