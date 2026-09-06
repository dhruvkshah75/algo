// ========================================= dfs + bfs ========================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(x) cerr << " " << x << " ";
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

// question link: https://codeforces.com/problemset/problem/813/C

/*
 * Alice starts traversal from node 1 so the time taken for alice to reach each node 
 * is the depth of the node and Bob will try to go to the deepest node such that 
 * he does not cross path with alice 
 * so bob can go to the node such that dist[node] < depth[node]
 * 
 * so apply bfs from bobs node and try to reach the next node only if 
 * dist_bob[node] < dist_alice[node] i.e bob reaches the node first 
 */

vector<vector<int>> adj;

void dfs(int node, int parent, vector<int> &depth) {

	for(int child: adj[node]) {
		if(child == parent) continue;

		depth[child] = depth[node] + 1;
		dfs(child, node, depth);
	}
}

void solve() {
	int n, x;
	cin >> n >> x;

	adj.assign(n+1, {});
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> depth(n+1, 0);
	// depth[node] = time taken to reach some node by alice 

	dfs(1, -1, depth);

	// now apply bfs from bobs node and check if that node can be reached 
	queue<int> q;
	vector<int> dist(n+1, 0);
	vector<bool> vis(n+1, false);

	q.push(x);
	dist[x] = 0;
	vis[x] = true;

	int ans = 0;

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		// this node is reached so update the answer
		int val = 2 * max(depth[node], dist[node]); 
		ans = max(ans, val);

		for(int child: adj[node]) {
			if(vis[child]) continue;

			// check if this node can be explored 
			if(dist[node] + 1 < depth[child]) {
				dist[child] = dist[node] + 1;
				q.push(child);
				vis[child] = true;
			}
		}
	}
	
	cout << ans << endl;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}