// ======================================== tree dp ========================================

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

// question link: https://codeforces.com/problemset/problem/2070/D 

/*
 * This is like a simple dfs traversal with dp involved in it 
 * so store all the depths of the vertices and store all the 
 * vertices level wise => level[d] = {} all vertices at depth d 
 * so try to move to the next vertex (depth + 1) from the current one 
 * 
 * cannot do a dfs traversal from all the nodes as this forms a dense graph 
 * instead use a formula 
 * => dp[node] = 1 - sum(dp[children of node]) + sum(dp[other nodes])
 * levelSum[d] = sum of dp[v] for all v at depth d;
 */

const int MOD = 998244353;

vector<int> parent, depth;
vector<vector<int>> level, adj;
vector<ll> dp, levelSum;

int dfs(int node) {

	if(dp[node] != -1) return dp[node];

	// we can stop the sequence at node 
	ll res = 1;

	int d = depth[node];
	if(d + 1 >= level.size()) return dp[node] = res;

	// dp[node] = 1 + levelSum[d+1] - sum(dp[child])
	res = (res + levelSum[d+1]) % MOD;

	// node != 1 then we must remove the dp[child]
	if(node != 1) {
		for(int child: adj[node]) {
			if(child == parent[node]) continue;
			// subtract the forbiddent movement to all the nbgs
			res = (res - dfs(child) + MOD) % MOD;
		}
	}

	return dp[node] = res;
}

void solve() {
	int n;
	cin >> n;

	parent.assign(n+1, 0);
	depth.assign(n+1, 0);
	adj.assign(n+1, {});
	int max_depth = 0;

	for(int i = 2; i <= n; i++) {
		// i - parent
		cin >> parent[i];
		adj[i].push_back(parent[i]);
		adj[parent[i]].push_back(i);

		depth[i] = depth[parent[i]] + 1;
		max_depth = max(max_depth, depth[i]);
		// update the max depth 
	}

	// store all the nodes level wise => level[depth]
	level.assign(max_depth+1, {});
	for(int i = 1; i <= n; i++) {
		level[depth[i]].push_back(i);
	}

	dp.assign(n+1, -1);
	levelSum.assign(max_depth+1, 0);

	/* calculate the levelSum for all nodes as dfs requires it 
	   so start levelSum computation for deepest levels first */

	for(int d = max_depth; d >= 0; d--) {
		// call dfs for all nodes at level d 
		for(int node: level[d]) {
			int temp = dfs(node);
		}

		// update the level sum for all nodes at depth d
		for(int node: level[d]) {
			levelSum[d] = (levelSum[d] + dp[node]) % MOD;
		}
	}

	cout << dp[1] << endl;
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