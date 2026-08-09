// ======================================== rerooting dp ============================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sum-of-distances-in-tree/description/

/**
 * Simple rerooting dp question 
 * precompute the dp[0] = sum(dist(0, i)) for all i using dfs 
 * we also need the number of nodes for each subtree rooted at x 
 * also precompute the subtree[x] 
 * 
 * Recurrence is pretty much straightforward 
 * node -> child
 * dp[child] = dp[node] + totalNodes - 2 * subtree[child]
 * */

class Solution {
private:
	int totalNodes;
	vector<int> subtree, dp;
	vector<vector<int>> adj;

	void dfs1(int node, int parent, int dist) {
		// update the subtree node count and dp[0]
		subtree[node] = 1;
		dp[0] += dist;

		for(int child: adj[node]) {
			if(child == parent) continue;

			dfs1(child, node, dist+1);
			subtree[node] += subtree[child];
		} 
	}

	void dfs2(int node, int parent) {

		for(int child: adj[node]) {
			if(child == parent) continue;

			// using recurrence update the dp values for each node 
			dp[child] = dp[node] + totalNodes - 2 * subtree[child];
			dfs2(child, node);
		}
	}

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    	// keep node = 0 as the initial root 

    	adj.assign(n, {});
        for(auto &e: edges) {
        	int u = e[0], v = e[1];
        	adj[u].push_back(v);
        	adj[v].push_back(u);
        }

        totalNodes = n;
        dp.assign(n, 0);
        subtree.assign(n, 0);
        // precmpute the dp[0] and subtree[x] = number of nodes in the subtree rooted at x
        dfs1(0, -1, 0);

        // compute the same for all other nodes using rerooting dp 
        dfs2(0, -1);

        return dp;
    }
};