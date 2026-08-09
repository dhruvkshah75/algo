// ========================== sparse table + binary jumping + monotonic stack ============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/

/**
 * to answer the queries effeciently we use the concept of binary lifting / jumping 
 * this allows us to answer the queries in O(LogN)
 * here note that jump table is the nge table => alice / bob can jump only to bigger buiildings not to smaller ones 
 * jump[i][j] = building that can be reached from position i (index) using 2 ^ j jumps 
 * and jumps[i][0] = nge[i] (next greater element)
 * 
 * Now for each query q[i] = [a, b] => for uniformity keep a < b (a and b are indices)
 * 1. a == b => return b => alice and bob are on the same position 
 * 2. heights[a] < heights[b] => alice can reach to bobs position => they can meet at bobs building 
 * 3. heights[a] >= heights[a] => this is where binary lifting comes in
 *    simply jump bob to the building with least index such that heights[index] > heights[a]
 *    this will be the one where bob and alice can meet up 
 * jump from the max jump to smallest, this ensures that we dont overshoot
 * */

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries) {
        int n = heights.size(), q = queries.size();

        int LOG = log2(n) + 1;
        vector<vector<int>> jump(n, vector<int>(LOG, -1));

        stack<int> st;
        // monotonic descreasing stack 

        for(int i = n-1; i >= 0; i--) {
        	int curr = heights[i];

        	while(!st.empty() && curr >= heights[st.top()]) 
        		st.pop();

        	// top of the stack will be the nge of curr 
        	if(!st.empty()) jump[i][0] = st.top();

        	st.push(i);
        }

        // build the sparse jump table 
        for(int j = 1; j < LOG; j++) {
        	for(int i = 0; i < n; i++) {
        		// 2 ^ j jump can be done in jumps of 2 ^ j-1
        		int node = jump[i][j-1];
        		if(node != -1) {
        			jump[i][j] = jump[node][j-1];
        		}
        	}
        }

        // ===================== processing the queries ====================================
        vector<int> ans(q, -1);

        for(int i = 0; i < q; i++) {
        	int a = queries[i][0], b = queries[i][1];

        	// keep a as the smaller index for uniformity 
        	if(a > b) swap(a, b);

        	// simple case where alice can jump to bob's position 
        	if(a == b || heights[a] < heights[b]) {
        		ans[i] = b;
        		continue;
        	}

        	// lift bob to the building where height > heights[alice] 
			int curr = b;      	
        	for(int j = LOG-1; j >= 0; j--) {
        		int nxt = jump[curr][j];
        		// if the jumped buidling is far too short or equal then we must more 
        		if(nxt != -1 && heights[nxt] <= heights[a]) {
        			curr = nxt;
        		}
        	}

        	// after all the jumps => curr is the farthest building such that height <= height[a] 
        	// so jump to the nge of curr => that will have height > height[a]
        	ans[i] = jump[curr][0];
        }

        return ans;
    }
};