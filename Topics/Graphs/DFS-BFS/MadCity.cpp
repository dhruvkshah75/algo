// ===================================== dfs + bfs ===========================================

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

// question link: https://codeforces.com/problemset/problem/1873/H

/*
 * when can person B escape person A all the time only when they are 
 * stuck in cycle => so basically person B must reach some cyclic node 
 * in time < time taken by person A to reach that node 
 * 
 * using 1 dfs mark all the nodes that are part of the cycle => use cycle 
 * detection using dfs and parent to get all the nodes 
 * 
 * now run the bfs for person A from node a to all the nodes to get the time 
 * taken by person A to reach 
 * and now in the second run of bfs from person B try to reach those nodes 
 * whose time taken < time taken by person A and if cyclic node is ever reached
 * then return yes
 */

vector<vector<int>> adj;

void dfs(int node, vector<int> &state, vector<bool> &isCyclic, vector<int> &parent) {
	// mark the node visited 
	state[node] = 1;

	for(int child: adj[node]) {
		if(child == parent[node]) continue;

		if(state[child] == 1) {
			// back edge detected => cycle detected 
			// child is the ancestor of node in dfs tree
			int curr = node;
			isCyclic[child] = true;

			while(curr != child) {
				isCyclic[curr] = true;
				curr = parent[curr];
			}
		}
		else if(state[child] == 0) {
			// unvisited node so explore further 
			parent[child] = node;
			dfs(child, state, isCyclic, parent);
		}
	}

	state[node] = 2;
}

void bfs(int a, vector<int> &dist, int n) {

	queue<int> q;
	vector<bool> vis(n+1, false);

	q.push(a);
	dist[a] = 0;
	vis[a] = true;

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(int child: adj[node]) {
			if(vis[child]) continue;

			dist[child] = dist[node] + 1;
			q.push(child);
			vis[child] = true;
		}
	}
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	adj.assign(n+1, {});
	for(int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> isCyclic(n+1, false);
	vector<int> state(n+1, 0);
	vector<int> parent(n+1, -1);
	// 0 = unvisted, 1 = in recursion stack space, 2 = visited and not in recursion stack
	dfs(1, state, isCyclic, parent);

	// apply bfs for person A from node A 
	vector<int> distA(n+1, 0);
	bfs(a, distA, n);

	// apply bfs from person B from node b and check if cyclic node is reachable 
	vector<bool> vis(n+1, false);
	queue<pair<int,int>> q;

	q.push({b, 0});
	vis[b] = true;
	bool flag = false;

	while(!q.empty()) {
		auto [node, dist] = q.front();
		q.pop();

		if(isCyclic[node] && dist < distA[node]) {
			flag = true;
			break;
		}

		for(int child: adj[node]) {
			if(vis[child]) continue;

			if(dist + 1 < distA[child]) {
				q.push({child, dist+1});
				vis[child] = true;
			}
		}
	}
 
	if(flag) {
		yes;
	}
	else {
		no;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}