// ========================================= dfs + sorting ==============================================

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

// question link: https://codeforces.com/contest/1337/problem/C

/**
 * For every node we make into a industrial node we cause damage to its descendents value 
 * the damage will be subtree_size[node] - 1 
 * so for each node value[node] = depth[node] - (subtree_size[node] - 1) 
 * so pick the ones with max values => always the descendents will be picked first so this formula works out 
 * */

vector<int> depth, subtree;
vector<vector<int>> adj;

void dfs(int node, int parent) {
	subtree[node] = 1;

	for(int child: adj[node]) {
		if(child == parent) continue;

		depth[child] = depth[node] + 1;
		dfs(child, node);
		subtree[node] += subtree[child];
	}
}

void solve() {
	int n, k;
	cin >> n >> k;

	adj.assign(n+1, {});
	depth.assign(n+1, 0);
	subtree.assign(n+1, 0);

	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	depth[1] = 0;
	dfs(1, -1);

	vector<int> value;
	for(int i = 1; i <= n; i++) {
		int val = depth[i]-(subtree[i]-1);
		value.push_back(val);
	}

	// sort the nodes on basis of the values 
	sort(rall(value));

	ll ans = 0;
	for(int i = 0; i < k; i++)
		ans += value[i];

	cout << ans << endl;
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}