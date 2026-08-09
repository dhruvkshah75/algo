// ================================================ DSU =============================================================

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

// question link: https://codeforces.com/problemset/problem/1702/E

/**
 * Use 2 dsu to keep the track of two sets 
 * dsu d1 for set1 and dsu d2 for set2 => initially mark all the nodes as -1 
 * and then add each domino tile into either of the sets if not clashing 
 * eg: add domino {x, y} => so check parent of x and parent of y in set1 
 * and if both are -1 then we can add them to this set otherwise try adding to other one 
 * and if both additions fail then ans = no
 **/

const int MAXN = 2e5+10;

class DSU {
private:
	vector<int> parent, size;

	int find(int u) {
		if(parent[u] == -1) return parent[u];
		if(parent[u] != u) parent[u] = find(parent[u]);
		return parent[u];
	}

public:
	DSU(int n) : parent(n, -1), size(n, 1) {}

	bool unite(int u, int v) {
		int pu = find(u), pv = find(v);
		// merge the components if these nodes are not in the set 
		if(pu != -1 || pv != -1) return false;
		// mark those nodes as unlocked as pu = -1 and pv = -1
		parent[u] = parent[v] = u;
		size[u] += size[v];
		return true;
	}
};

void solve() {
	int n;
	cin >> n;

	DSU set1(n+1), set2(n+1);
	
	int flag = true;	
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		// base case: both sides have the same number cannot place anywhere 
		if(x == y) flag = false;

		// try adding in the set1 or set2 and return false if cant be added to both 
		if(set1.unite(x, y)) {}
		else if(set2.unite(x, y)) {}
		else flag = false;
	}

	if(flag) {
		yes;
	}
	else {
		no;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}