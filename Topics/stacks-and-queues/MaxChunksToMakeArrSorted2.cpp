// ==================================== monotonic stacks =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/

// ============================= Very Important Question ========================================

/**
 * Each chunk can extend till the nse so that on sorting each individual chunks the entire array is sorted 
 * 
 * One property that needs to remain true is [max(chunk on the left) <= min(chunk on the right)]
 * on forward traversal create chunks if we get a bigger elements 
 * example: 2, 1, 3, 4, 4 
 * in the stack store the max elements of the chunks 
 * 2 -> [2]
 * 1 -> [2] (1 is smaller than 2 so merge into the chunk of 2)
 * 3 -> [2, 3] 
 * 4 -> [2, 3, 4]
 * 4 -> [2, 3, 4, 4]
 * number of chunks is the size of the stack 
 * 
 * when we merge chunks we must search all the elements of the stack 
 * eg [2, 1, 3, 4, 4, 1]
 * 2 -> [2]
 * 1 -> [2] (1 is smaller than 2 so merge into the chunk of 2)
 * 3 -> [2, 3] 
 * 4 -> [2, 3, 4]
 * 4 -> [2, 3, 4, 4]
 * 1 -> [4]  (this 1 will remove all the elements from the stack until it is bigger than the top of the stack)
 * and then merge all those passed chunks and keep a track of the max of the merged chunks 
 **/

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int n = arr.size();

        stack<int> st;
        // monotonic increasing stack to store the max elements of the chunks created so far 

        for(int i = 0; i < n; i++) {
        	int curr = arr[i];
        	int mx = curr;

        	// check if this curr can form a new chunk or merge it with the chunks created so far 
        	while(!st.empty() && curr < st.top()) {
        		mx = max(mx, st.top());
        		st.pop();
        	}

        	st.push(mx);
        }

        return st.size();
    }
};