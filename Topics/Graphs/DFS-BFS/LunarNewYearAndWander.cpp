// ================================== bfs ====================================================

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

// question link: https://codeforces.com/problemset/problem/1106/D

/**
 * We want the lexicographically smallest print of the order of wandering 
 * this question involves picking the smallest node from all the visited nodes
 * so technically maintain a min heap containing the nbgs of all vis nodes 
 * this is essentially prims alfgorithm without any weights 
 * 
 * => why not simple dfs with smallest nodes to be visited first 
 * because we can visit one node multiple times, so we can go to the smallest nbg of all
 * similar to prim mark the node visited later 
 * Greedy + bfs (prims style)
 **/

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n+1);

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> vis(n+1, false);
	vector<int> res;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	// min heap to store the nbg of all visited nodes 

	pq.push(1);

	while(!pq.empty()) {
		int node = pq.top();
		pq.pop();

		if(vis[node]) continue;

		// visit this node and mark its neighbours
		res.push_back(node);
		vis[node] = true;

		for(int nbg: adj[node]) {
			if(vis[nbg]) continue;

			pq.push(nbg);
		}
	}

	for(int node: res)
		cout << node << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}