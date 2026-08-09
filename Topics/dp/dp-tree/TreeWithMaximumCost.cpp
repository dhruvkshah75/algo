// ======================================== rerooting dp ==================================================

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

// question link: https://codeforces.com/problemset/problem/1092/F

/**
 * Question is based on rerooting dp 
 * same logic => if we fix one node then we can easily get the sum(dist(i, v) * a[i]) 
 * in one dfs pass in O(N)
 * 
 * since dp[node] = dp[1] is known => we can easily get the result for the child of node 
 * using rerooting dp 
 * when we shift the root from node to i then the we increase the distance on one side 
 * containing the node by 1 and other nodes on child's side distance are decreased by 1 
 * so we need subtree_sum to be precalculated 
 * 
 * recurrence for dp is formed as 
 * dp[child] = dp[node] + totalSum - 2 * subtree[child]
 * totalSum = subtree_sum[root = 1] => entire tree needs to be considered 
 **/

ll totalSum;
vector<int> a;
vector<ll> subtree_sum, dp;
vector<vector<int>> adj;

void dfs1(int node, int parent, int dist) {
	subtree_sum[node] = a[node];
	dp[1] += dist * 1LL * a[node];

	for(int child: adj[node]) {
		if(child == parent) continue;

		dfs1(child, node, dist+1);
		subtree_sum[node] += subtree_sum[child];
	}
}

void dfs2(int node, int parent) {
	// reroot dp => shift the root from node to child
	for(int child: adj[node]) {
		if(child == parent) continue;

		dp[child] = dp[node] + totalSum - 2 * subtree_sum[child];
		dfs2(child, node);
	} 
}

void solve() {
	int n;
	cin >> n;

	a.assign(n+1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];

	adj.resize(n+1);
	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dp.assign(n+1, 0);
	subtree_sum.assign(n+1, 0);

	// precompute the dp[1] and subtree_sum for the tree 
	dfs1(1, -1, 0);
	totalSum = subtree_sum[1];

	// using anathor dfs traversal => apply rerooting dp
	dfs2(1, -1);

	cout << *max_element(dp.begin()+1, dp.end()) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}