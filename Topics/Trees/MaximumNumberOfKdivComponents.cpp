// ========================================== trees ===================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/ 


/* Explanation: 2 dfs approach 
 *  	
 * This approach can be used when we want to cut some number of edges to make sum number of components 
 * 
 * Apply dfs 1 to get the subtree_sum[x] = sum of values of nodes with the subtree rooted at x
 * This is the most important step in solving the question further 
 * 
 * use anathor dfs to check if which edge is cuttable or not 
 * edge (u -> v) can cut only if comp_sum - subtree[nbg] and subtree[nbg] are div by k
 * so when the edge is cut subtree rooted at nbg is split and left out component is there 
 * => component 1 = subtree_sum[v] and component 2 => comp_sum - subtree_sum[v]
 * 
 * max number of components = cuts + 1 
 */

typedef long long ll;

class Solution {
private:
	vector<vector<int>> adj;
	vector<ll> subtree_sum;
	int cuts;

	void dfs2(int node, int parent, ll comp_sum, int k) {

		for(int nbg: adj[node]) {
			if(nbg == parent) continue;

			// check if this cut is valid => one component = subtree_sum[nbg] and the second will be (comp_sum - subtree_sum[nbg]) 
			if((subtree_sum[nbg] % k == 0) && ((comp_sum - subtree_sum[nbg]) % k == 0)) {
				cuts++;
				// node -> nbg is cut so call the neighbour with subtree_sum[nbg] and update the comp_sum as we split into 2 components 
				dfs2(nbg, node, subtree_sum[nbg], k);	
				comp_sum -= subtree_sum[nbg];
			}
			else {
				// cut of this edge node -> nbg is not possible 
				dfs2(nbg, node, comp_sum, k);
			}
		}
	}

	void dfs1(int node, int parent, vector<int> &values) {

		subtree_sum[node] = values[node];

		for(int nbg: adj[node]) {
			if(nbg == parent) continue;

			dfs1(nbg, node, values);
			// dfs calculates the sum[nbg]
			subtree_sum[node] += subtree_sum[nbg];
		}
	}

public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
        // nodes are 0 to n-1
        adj.resize(n);
        subtree_sum.resize(n, 0);

        for(auto &e: edges) {
        	adj[e[0]].push_back(e[1]);
        	adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        // fix root = 0
        dfs1(0, -1, values);

        // now use bfs to make cuts depending on the property 
        cuts = 0;

        // call the dfs with entire component sum of the entire tree = subtree_sum[root = 0] 
        dfs2(0, -1, subtree_sum[0], k);

        return cuts + 1;
    }
};