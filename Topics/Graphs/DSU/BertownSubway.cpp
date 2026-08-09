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

// question link: https://codeforces.com/contest/884/problem/C

struct DSU {
	vector<int> parent, size;

	DSU(int n) : parent(n), size(n, 1) {
		iota(parent.begin(), parent.end(), 0);
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

	DSU d(n+1);

	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		// i -> x
		d.merge(i, x);
	}

	vector<int> v;
	for(int i = 1; i <= n; i++) {
		if(d.find(i) == i) {
			// a new component found 
			v.push_back(d.size[i]);
		}
	}
 
	sort(rall(v));

	ll ans = 0;
	if(v.size() == 1) {
		ans = v[0] * 1LL * v[0];
	}
	else {
		// merge the two biggest components
		ans = (v[0] + v[1]) * 1LL * (v[0] + v[1]);

		for(int i = 2; i < v.size(); i++) {
			ans += v[i] * 1LL * v[i];
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}