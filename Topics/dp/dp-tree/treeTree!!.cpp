// ================================ rerooting dp + dfs =========================================

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

// question link: https://codeforces.com/problemset/problem/2167/F

/*
 * this can be thought of as a rerooting dp qustion 
 * when we fix the node = 1 as the root of the tree we can easily calculate all the nodes that 
 * can become LCA and get added to the set 
 * 
 * first of all store all the subtree cnt for each node 
 * when subtree_cnt[node] >= k => then this node can be part of the set of LCAs 
 * dp[1] can be calculated very easily in one dfs pass 
 * 
 * now comes the important rerooting dp logic where we reroot from 1 to its child 
 * 
 * consider u as the root and v as the child 
 * OLD: u (root) contributes always as subtree_cnt[u] = n >= k => always true 
 *      v (child of u) contributes to ans iff subtree_cnt[v] >= k 
 * NEW: v (new root) contributes always as subtree_cnt becomes n >= k
 *      u contributes if new_size = n - subtree_cnt[v] >= k 
 * 
 * This can be formulated as 
 * dp[v] = dp[u]
 * and then adjust based on the changes 
 * 
 * subtract one when u now does not contribute => n - subtree[v] < k
 * if(n - subtree[v] < k) dp[v]--;
 * 
 * add one to the ans when earlier v was not contributing => after rerooting it will definetly contribute 
 * if(subtree[v] < k) dp[v]++;
 */

int n, k;
vector<int> subtree_cnt;
vector<vector<int>> adj;
vector<int> dp;

void dfs2(int node, int parent) {
	// rerooting dp logic 

	for(int child: adj[node]) {
		if(child == parent) continue;

		// make the child node as the new root 
		dp[child] = dp[node];

		// subtract one as node with new size does not contribute to ans 
		if(n - subtree_cnt[child] < k) dp[child]--;

		// add one as child earlier did not contribute but now does because new_sz = n
		if(subtree_cnt[child] < k) dp[child]++;

		dfs2(child, node);
	}
}

void dfs1(int node, int parent) {

	subtree_cnt[node] = 1;

	for(int child: adj[node]) {
		if(child == parent) continue;

		dfs1(child, node);
		subtree_cnt[node] += subtree_cnt[child];
	}

	// update the dp[1] based on subtree size of node
	if(subtree_cnt[node] >= k) dp[1]++; 
}

void solve() {
	cin >> n >> k;

	adj.assign(n+1, {});
	subtree_cnt.assign(n+1, 0);
	dp.assign(n+1, 0);

	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// start with the node = 1 as the starting root 
	dp[1] = 0;
	dfs1(1, -1);

	// apply the rerooting dp logic to update the dp for all nodes 
	dfs2(1, -1);

	ll result = accumulate(dp.begin(), dp.end(), 0LL);
	cout << result << endl;
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