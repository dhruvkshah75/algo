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

// question link: https://codeforces.com/problemset/problem/1528/A

/**
 * for each node it is logical to take a value as the end point 
 * of the interval either l or r 
 * so we can use dp to calculate the max value of choosing the value 
 * two states needed will be one for knowing which value is taken l or r 
 * use 0/1 state 
 * 
 * recurrence = f(node, state = 0/1)
 * for each edge or child of the current node call the dfs function for both 
 * states of the node 0 and 1 so that we get the max value 
 * */

vector<pii> mark;
vector<vector<int>> adj;
vector<vector<ll>> dp;

ll dfs(int node, int state, int parent) {

	if(dp[node][state] != -1) return dp[node][state];

	int cnt = 0;
	ll node_val = (state == 1) ? mark[node].second : mark[node].first;
	ll res = 0;

	for(int child: adj[node]) {
		if(child == parent) continue;

		cnt++;
		// add the val for edge => node -- child
		ll max_val = max(abs(node_val - mark[child].first) + dfs(child, 0, node), 
			abs(node_val - mark[child].second) + dfs(child, 1, node));
		res += max_val;
	}

	// if this is the leaf node then no edge further down so return 0
	if(cnt == 0) return dp[node][state] = 0;
	
	return dp[node][state] = res;
}

void solve() {
	int n;
	cin >> n;

	mark.assign(n+1, {});
	for(int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		mark[i] = {l, r};
	}

	adj.assign(n+1, {});
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dp.assign(n+1, vector<ll>(2, -1));

	// call the dfs recurrence for both states of the root 1 => 0 and 1
	ll result = max(dfs(1, 0, -1), dfs(1, 1, -1));
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