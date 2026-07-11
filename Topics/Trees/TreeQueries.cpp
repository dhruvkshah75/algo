#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

const int MAXN = 2e5+10;

// question link: https://codeforces.com/problemset/problem/1328/E

/**
 * For each query we are given a set of vertices S 
 * What does distance of 1 from the original path nodes from 1 to some vertex u means 
 * all the parent of nodes lie in the path from 1 to some vertex u 
 * So make a new set S' which contains all the parent of original vertices in S 
 * Now fix the vertex u which is the deepest vertex in the set S' as vertex x
 * just check if each vertex v in the S is the Kth Ancestor of x where K = depth[x]-depth[v]
 * */

class Solution {
private:
	int LOG;
	vector<vector<int>> adj;
	vector<int> depth;
	vector<vector<int>> up;

	void dfs(int node, int parent) {

		for(int nbg: adj[node]) {
			if(nbg == parent) continue;

			up[nbg][0] = node;
			depth[nbg] = depth[node]+1;
			dfs(nbg, node);
		}
	}

	int getKthAncestor(int node, int k) {

		for(int j = 0; j < LOG; j++) {
			int bit = k & (1 << j);
			if(bit) {
				node = up[node][j];
				if(node == -1) return -1;
			}
		}
		// node = kth ancestor of the query made 
		return node;
	}

public:
	void solve() {
		int n, m;
		cin >> n >> m;

		LOG = 0;
		while((1 << LOG) <= n+1) LOG++;

		adj.resize(n+1);
		up.resize(n+1, vector<int>(LOG, -1));
		depth.resize(n+1, 0);
		
		for(int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		// precompute the depth and parent (up[node][0]) of all nodes 
		dfs(1, -1);

		// fill the sparse table for binary lifting 
		for(int j = 1; j < LOG; j++) {
			for(int i = 1; i <= n; i++) {
				// 2 ^ j jump can be written as 2 ^ (j-1) + 2 ^ (j-1)
				int node = up[i][j-1];
				if(node != -1)
					up[i][j] = up[node][j-1];
			}
		}

		// queries => O(q * k * Log(N))
		while(m--) {
			int k;
			cin >> k;

			// s contains all the nodes in the path of 1 to some vertex u 
			unordered_set<int> s;
			for(int i = 0; i < k; i++) {
				int u;
				cin >> u;
				int p = up[u][0];
				// only insert if parent exists otherwise insert 1 (root)
				if(p != -1) s.insert(p);
				else s.insert(1);
			} 

			int x = -1, max_depth = -1;
			for(int node: s) {
				if(depth[node] > max_depth) {
					x = node;
					max_depth = depth[node];
				}
			}

			// check if every vertex v in the set is a kth ancestor of x 
			bool ok = true;

			for(int node: s) {
				if(node == x) continue;
				// node must be kth ancestor of x
				if(node != getKthAncestor(x, depth[x]-depth[node])) {
					ok = false;
					break;
				}
			}

			if(ok) {
				yes;
			}
			else {
				no;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Solution s;
	s.solve();
}