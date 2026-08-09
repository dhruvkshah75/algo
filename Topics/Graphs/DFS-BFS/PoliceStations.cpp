// ============================================== multi source bfs =============================================

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

// question link: https://codeforces.com/problemset/problem/796/D

/*
 * Apply mutli source bfs from all the nodes with police stations 
 * run the bfs only till the nodes reach distance d
 * when can a edge be remove => some edge that was already visited 
 * (not the parent edge) as some police station reached there earlier <= d distance
 * note that the same node can have multiple police stations so only
 * store non duplcates for them 
 */

void solve() {
	int n, k, d;
	cin >> n >> k >> d;

	unordered_set<int> stations;
	for(int i = 0; i < k; i++) {
		int x;
		cin >> x;
		stations.insert(x);
	}

	map<pair<int,int>,int> edges;
	// store the edges[{u, v}] -> idx
	vector<vector<int>> adj(n+1);
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[{min(u, v), max(u, v)}] = i+1;
	}

	queue<int> q;
	vector<int> dist(n+1, 0), parent(n+1, -1);
	vector<bool> vis(n+1, false);

	for(int node: stations) {
		q.push(node);
		dist[node] = 0;
		vis[node] = true;
		parent[node] = -1;
	}

	unordered_set<int> ans;

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(int child: adj[node]) {
			if(parent[node] == child) continue;
			
			if(vis[child]) {
				// this is the edge that can be removed 
				int u = min(node, child);
				int v = max(node, child);
				int ind = edges[{u, v}];
				ans.insert(ind);
				continue;
			}
			else if(!vis[child] && dist[node] + 1 <= d){
				// push this node in the queue 
				q.push(child);
				dist[child] = dist[node] + 1;
				vis[child] = true;
				parent[child] = node;
			}
		}
	}

	// check if all nodes were reached or not 
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			cout << 0 << endl;
			cout << endl;
			return;
		}
	}

	cout << ans.size() << endl;
	for(int index: ans) cout << index << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}