// ================================================= dfs + trees ============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/982/C

/* Explanation: 2 dfs solution 
 * similar logic to max number of edge removals to get k divisible components 
 *
 * use dfs1 to calculate the number of nodes in each subtree rooted at that node 
 * fix the root of the tree to be 1
 *
 * use dfs2 to check where cuts can be made 
 * start dfs2 from the root = 1 and keep a track of the number of nodes in the component 
 * and if we cut an edge => only allowed if on cutting the edge if both components have even number of nodes 
 * otherwise dont cut the edge and call dfs for the next node
 */

class Solution {
private:
	int n, cuts;
	vector<vector<int>> adj;
	vector<int> subtree_cnt;

	void dfs2(int node, int parent, int comp_cnt) {

		for(int nbg: adj[node]) {
			if(nbg == parent) continue;

			if(subtree_cnt[nbg] % 2 == 0 && (comp_cnt - subtree_cnt[nbg]) % 2 == 0) {
				cuts++;

				// this edge is cut so we can call the dfs for the updated components 
				dfs2(nbg, node, subtree_cnt[nbg]);
				comp_cnt -= subtree_cnt[nbg];
			}
			else {
				// this edge cannot be cut so call the next component 
				dfs2(nbg, node, comp_cnt);
			}
		}
	}

	void dfs1(int node, int parent) {

		subtree_cnt[node] = 1;

		for(int nbg: adj[node]) {
			if(nbg == parent) continue;

			dfs1(nbg, node);
			subtree_cnt[node] += subtree_cnt[nbg];
		}
	}

public: 
	int solve(int n) {
		this->n = n;

		adj.resize(n+1);
		subtree_cnt.resize(n+1, 0);

		for(int i = 0; i < n-1; i++) {
			int x, y;
			cin >> x >> y;

			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		// build the subtree_cnt = no of nodes in the subtree rooted at x using dfs1
		dfs1(1, -1);

		// cout << "dfs1 done" << endl;

		// use dfs2 to count the number of cuts that can be made 
		int total_nodes = subtree_cnt[1];
		cuts = 0;

		dfs2(1, -1, total_nodes);

		if(cuts == 0) {
			if(total_nodes & 1) return -1;
			else return 0;
		}

		return cuts;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	Solution s;
	cout << s.solve(n) << endl;
}

