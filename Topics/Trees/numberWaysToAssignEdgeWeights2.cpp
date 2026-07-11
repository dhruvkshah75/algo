// ========================================== binary lifting ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/description/

/* Explanation: binary lifting to calculate LCA 
 * it doesnt matter what intermediiate nodes come in a path 
 * We only care about the number of edges in the path of the query => u, v 
 * k = dist(a, b) 
 * dis(a, b) = depth[a] + depth[b] - 2*depth[LCA(a, b)]
 * to assign the weights to get odd sum path = number of ones should be odd 
 * to do that we need to use combinations to get the formula => 2 ^ k-1 
 */

class BinaryLifting {
private:
	int n, LOG;
	vector<vector<int>> up;
	vector<int> depth;
	vector<vector<int>> adj;

	void bfs() {

		queue<int> q;
		q.push(1);
		depth[1] = 0;

		while(!q.empty()) {
			int node = q.front();
			q.pop();

			for(int nbg: adj[node]) {
				if(up[node][0] == nbg) continue;

				q.push(nbg);
				depth[nbg] = depth[node]+1;
				// parent[nbg] = node
				up[nbg][0] = node; 
			}
		}
	}

public:
	BinaryLifting(int n, vector<vector<int>> &adj) {
		this->adj = adj;
		depth.resize(n+1);

		// nodes are 1 to n
		LOG = 0;
		while((1 << LOG) <= n+1) LOG++;

		up.resize(n+1, vector<int>(LOG, -1));

		// use bfs to build to get the depth and up[node][0]
		bfs();

		// fill the sparse up table for binary lifting 
		// 2 ^ j jump = 2 ^ (j-1) + 2 ^ (j-1)

		for(int j = 1; j < LOG; j++) {
			for(int i = 1; i <= n; i++) {
				int node = up[i][j-1];
				// node is 2 ^ j-1 jump 
				if(node != -1) {
					up[i][j] = up[node][j-1];
				}
			}
		}
	}

	int lca(int a, int b) {
		// bring node a and node b to the same depth 
		if(depth[a] < depth[b]) swap(a, b);

		int diff = depth[a] - depth[b];
		for(int j = 0; j < LOG; j++) {
			int bit = diff & (1 << j);
			if(bit) {
				a = up[a][j];
			}
		}

		// when a and b both on the same level and they are the same then a = b = lca 
		if(a == b) return b;

		// now lift both a, b at the same time => try bigger jumps first 
		for(int j = LOG-1; j >= 0; j--) {
			// if their 2 ^ j th ancestor are different then make this jump
			if(up[a][j] != up[b][j]) {
				a = up[a][j];
				b = up[b][j];
			}
		}

		// lca will be parent[a] or parent[b]
		return up[a][0];
	}

	int get_depth(int node) {
		return depth[node];
	}
};

class Solution {
private:
	const int MOD = 1e9+7;
	vector<int> pow2;

	void precompute(int n) {
		// compute powers of 2 modulo 1e9+7
		pow2.resize(n+10);
		pow2[0] = 1;
		for(int i = 1; i < n+10; i++) {
			pow2[i] = (pow2[i-1] * 2LL) % MOD;
		}
	}

public:
    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        int n = edges.size()+1;

        precompute(n);

        vector<vector<int>> adj(n+1);
        for(auto &e: edges) {
        	adj[e[0]].push_back(e[1]);
        	adj[e[1]].push_back(e[0]);
        }

        BinaryLifting bl(n, adj);

        vector<int> res;

        for(auto &q: queries) {
        	int u = q[0], v = q[1];
        	int k = bl.get_depth(u) + bl.get_depth(v) - 2*bl.get_depth(bl.lca(u, v));
        	res.push_back(((k > 0) ? pow2[k-1] : 0));
        }

        return res;
    }
};