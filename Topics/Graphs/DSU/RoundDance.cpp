// ======================================= dsu ========================================

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

// question link: https://codeforces.com/problemset/problem/1833/E

/*
 * When can a round dance or a connected component merge with anathor 
 * component => when it is open i.e. when a node among that component 
 * has degree != 2 
 * 
 * closed component is the one in which all the nodes are part of a cylce 
 * degree[all nodes] = 2
 * 
 * minimum round dances = closed + (open > 0) => merge all the opens into one 
 * and maximum round dances = closed + open => directly from dsu 
 */

struct DSU {
	vector<int> parent, size;

	DSU(int n) : parent(n), size(n, 1) {
		iota(all(parent), 0);
	}

	int find(int u) {
		if(parent[u] != u) parent[u] = find(parent[u]);
		return parent[u];
	}

	void merge(int u, int v) {
		int pu = find(u), pv = find(v);
		if(pu == pv) return;
		if(size[pu] < size[pv]) swap(pu, pv);
		parent[pv] = pu;
		size[pu] += size[pv];
	}
};

void solve() {
	int n;
	cin >> n;

	vector<int> degree(n+1);
	DSU d(n+1);

	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		// edge i -> x (undirected)
		d.merge(i, x);
		degree[i]++;
		degree[x]++;
	}

	unordered_map<int,vector<int>> mp;
	// mp stores the components => nodes in that component

	for(int i = 1; i <= n; i++) {
		int p = d.find(i);
		mp[p].push_back(i);
	}

	int open = 0, closed = 0;
	for(auto &[p, nodes]: mp) {
		bool flag = true;

		if(nodes.size() == 2) {
			// only 2 nodes in the cycle => by default a open component 
			open++;
			continue;
		}

		for(int x: nodes) {
			if(degree[x] != 2) {
				open++;
				flag = false;
				break;
			}
		}
		// all nodes in the component have degree = 2 then it is closed 
		if(flag) {
			closed++;
		}
	}

	int min_components = closed + ((open > 0) ? 1 : 0);
	int max_components = closed + open;

	cout << min_components << " " << max_components << endl;
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