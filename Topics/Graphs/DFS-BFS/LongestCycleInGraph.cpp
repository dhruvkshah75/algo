// ============================================== dfs ==============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/longest-cycle-in-a-graph/description/

/**
 * each node has at most one outgoing edge 
 * for a node to be a part of one cycle it must have at least one outgoing edge and one incoming edge 
 * So combining these two cases we get that one node can have only one outgoing edge so it can have 
 * only one cycle => one node can be a part of only one cycle 
 * 
 * So we can use dfs and tin (time of entry of a node) to calculate the length of the cycle 
 * apply dfs on all unvisited nodes to check the length of the longest path
 * 
 * detect cycle in directed node using the state logic
 * state[node] = 1 -> node is in the recursion stack 
 * state[node] = 2 -> node is not in recursion stack so already explored differently
 * 
 * This Logic is Very Important in cycle detection in directed graphs 
 * the already visited node must be in the recursion stack space so form the cycle => start[node] = 1 
 * this means a back edge detected 
 * */

class Solution {
private:
	int n, max_len, time;
	vector<vector<int>> adj;
	vector<int> tin, state;

	void dfs(int node) {
		tin[node] = time++;
		state[node] = 1;

		for(int nbg: adj[node]) {
			// cycle detected (back edge) => as the nbg is already in recursion stack space 
			if(state[nbg] == 1) max_len = max(max_len, tin[node]-tin[nbg]+1);
			// state = 0 => node is not yet explored 
			else if(state[nbg] == 0) dfs(nbg);
		}

		state[node] = 2;
	}

public:
    int longestCycle(vector<int> &edges) {
        n = edges.size();

        adj.resize(n);
        tin.resize(n);
        state.resize(n, 0);

        for(int i = 0; i < n; i++) {
        	if(edges[i] == -1) continue;
        	// i -> edges[i]
        	adj[i].push_back(edges[i]);
        }

        // start the global timer for assigning the tin
        time = 0;
        max_len = -1;
        for(int i = 0; i < n; i++) {
        	// state[node] = 0 means the node is not explored yet 
        	if(state[i] != 0) continue;
        	// start dfs from the unvisited node 
        	dfs(i);
        }

        return max_len;
    }
};