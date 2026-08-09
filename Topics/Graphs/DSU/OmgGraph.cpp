// ====================================== Kruskals Algorithm ==================================================

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

// question link: https://codeforces.com/contest/2117/problem/G

/**
 * question can be solved with a variant of Kruskal 
 * we want to add min edges => the path here is not simple so we can 
 * make detour to go get the smallest edge 
 * sort the edges in increasing order => and update the min + max 
 * only if 1 and n are of the same component 
 * 
 * max edge => while processing we get this one 
 * for getting the smallest edge store that in the dsu itself as mn[]
 * of that component 
 **/

struct DSU {
	vector<int> parent, size, mn;

	DSU(int n) : parent(n), size(n, 1), mn(n, 1e9) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int u) {
		if(parent[u] != u) parent[u] = find(parent[u]);
		return parent[u];
	}

	void merge(int u, int v, int wt) {
		int pu = find(u), pv = find(v);
		// update the mn edge of the component (cyclic edge)
		if(pu == pv) {
			mn[pu] = min(mn[pu], wt);
			return;
		}

		if(size[pu] < size[pv]) swap(pu, pv);
		parent[pv] = pu;
		size[pu] += size[pv];
		// update the mn for pu, pv and this edge 
		mn[pu] = min({mn[pu], mn[pv], wt});
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	DSU d(n+1);

	vector<tuple<int,int,int>> edges;
	// keep adding the edges and update the min ans if 1 and n are in the same component 
	for(int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({wt, u, v});
	}

	sort(edges.begin(), edges.end());

	ll ans = 1e18;
	for(int i = 0; i < m; i++) {
		auto [wt, u, v] = edges[i];

		d.merge(u, v, wt);

		// update the ans if 1 and n become connected 
		if(d.find(1) == d.find(n)) {
			// min_edge will be mn of the component and wt will be the max edge 
			ans = min(ans, 1LL * d.mn[d.find(1)] + wt);
		}	
	}

	cout << ans << endl;
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