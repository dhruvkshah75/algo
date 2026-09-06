// ================================================ dfs ======================================================

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

// question link: https://codeforces.com/problemset/problem/1760/G

/*
 * Very Important Question 
 * we need a path from A to B such that xor all weights along the path = 0 
 * and we have one teleportation allowed in this 
 * 
 * consider how this traversal will look
 * A --------- U => teleport => V -------- B (such that V != B)
 * so in 2 dfs passes store the distA[U] for all U => start traversal from node A
 * and in the other pass stores the distB[V] for all nodes (V != B)
 * start the traversal from node B
 * 
 * use set to avoid tle because of collisions
 */

int n, a, b;
vector<vector<pair<int,int>>> adj;

void dfs1(int node, int parent, vector<int> &dist) {

	for(auto [child, wt]: adj[node]) {
		if(child == parent) continue;

		dist[child] = dist[node] ^ wt;
		dfs1(child, node, dist);
	}
}

void dfs2(int node, int parent, int path, set<int> &st, bool &possible) {

	// try teleporting from this node itself
	if(st.find(path) != st.end()) {
		possible = true;
			return;
	}

	for(auto [child, wt]: adj[node]) {
		if(child == parent || child == b) continue;

		// go to the child node and check if we can teleport 
		int new_path = path ^ wt;
		dfs2(child, node, new_path, st, possible);

		if(possible) return;
	}
}

void solve() {
	cin >> n >> a >> b;

	adj.assign(n+1, {});
	for(int i = 0; i < n-1; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}

	// get all the dist(B, V) for all V (V != B)
	vector<int> distB(n+1, 0);
	dfs1(b, -1, distB);

	set<int> st;
	// store all the nodes V => dist(B, V) such that V != B
	for(int node = 1; node <= n; node++) {
		if(node == b) continue;
		st.insert(distB[node]);
	}

	// apply dfs from node A and move to the nbgs and check if we can teleport or not 
	bool possible = false;
	dfs2(a, -1, 0, st, possible);

	if(possible) { yes; }
	else { no; }
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

