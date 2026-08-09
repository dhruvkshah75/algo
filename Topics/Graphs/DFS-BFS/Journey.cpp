// =========================================== probability + dfs =============================================

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

// question link: https://codeforces.com/problemset/problem/839/C

double ans = 0.0;
vector<vector<int>> adj;

void dfs(int node, int parent, int depth, double prob) {
	// root has no parent
	int k = adj[node].size() + ((parent == -1) ? 0 : -1);

	// leaf then add to the result (no children)
	if(k == 0) {
		ans += prob * depth;
		return;
	}

	for(int child: adj[node]) {
		if(child == parent) continue;

		dfs(child, node, depth+1, prob / k);
	}
}

void solve() {
	int n;
	cin >> n;

	adj.assign(n+1, {});
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1, 0, 1.0);
	cout << fixed << setprecision(15) << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}