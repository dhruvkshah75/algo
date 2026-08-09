// ============================================ dsu + combinatorics ============================================

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

// question link: https://codeforces.com/problemset/problem/1534/C

/*
 * Very Important question 
 * hard to recognize that this question is based on dsu 
 * 
 * when we swap values in a column then this forces us to swap more columns 
 * so technically they form a sort of connected component i.e. whenever a column 
 * is swapped then all the columns that are a part of the same component are forced 
 * to swap 
 * 
 * for each component we have 2 choices 
 * 1. dont swap leave as it is 
 * 2. swap all the columns of this component 
 * 
 * finally total number of configurations = 2 ^ c
 * where c = number of connected components 
 */

const int MOD = 1e9+7;

class DSU {
private:
	vector<int> parent, size;
	int comp;

	int find(int u) {
		if(parent[u] != u) parent[u] = find(parent[u]);
		return parent[u];
	}

public:
	DSU(int n) : parent(n), size(n, 1), comp(n-1) {
		iota(parent.begin(), parent.end(), 0);
	}

	void merge(int u, int v) {
		int pu = find(u), pv = find(v);
		if(pu == pv) return;

		if(size[pu] < size[pv]) swap(pu, pv);
		parent[pv] = pu;
		size[pu] += size[pv];
		comp--;
	}

	int get_comps() {
		return comp;
	}
};

void solve() {
	int n;
	cin >> n;

	DSU d(n+1);
	// numbers are 1...n

	vector<vector<int>> puzzle(2, vector<int>(n));
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < n; j++) {
			cin >> puzzle[i][j];
		}
	}

	for(int col = 0; col < n; col++) {
		// same column = edge => merge them 
		d.merge(puzzle[0][col], puzzle[1][col]);
	}
	
	int c = d.get_comps();
	// final result is 2 ^ c

	ll res = 1;
	for(int x = 1; x <= c; x++) {
		res = (res * 2LL) % MOD;
	}

	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) 
		solve();
}