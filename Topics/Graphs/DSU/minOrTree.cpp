
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

template <typename T>
void printVec(const vector<T>& v) {
    for(const auto &x: v) cout << x << " ";
    cout << endl;
}

template <typename T> 
void print(const T& x) { cerr << x; }

template <typename A, typename B>
void print(const pair<A, B> &p) {
    cerr << "{"; print(p.first); cerr << " ";
    print(p.second); cerr << "}";
}

template <typename T>
void print(const vector<T> &v) {
    cerr << "[";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << "]" << endl;
}

/**
 * we want the spanning tree with the min total or
 * how exactly do we do this => cannot simply just sort the values as that wont work
 * 
 * think like in a bitwise manner => can i make the spanning tree without any number involving the 30th bit
 * considering the kth bit => if we want this to be 0 in the final total or 
 * then for all edges chosen in the spanning tree this bit must be 0 for all edges in the spanning tree
 * 
 * so run for all bits from k = 30 to 0 and delete all edges with this bit as set and ask the question whether 
 * this graph is still connected or not => if yes then dont set this bit in the ans 
 * if no then this bit must be set in the result
 * starting top down ensures that the ans is minimal
 * */

struct DSU {
	vector<int> parent, size;
	int components;

	DSU(int n) : parent(n+1), size(n+1, 1), components(n) {
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
		components--;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	// n nodes and m edges 

	vector<tiii> edges(m);
	for(auto &[u, v, w]: edges) cin >> u >> v >> w;


	int result = 0;
	int forbidden = 0;
	// form the result bit by bit => by checking if this bit can be kept 0

	for(int bit = 30; bit >= 0; bit--) {
		// also make the forbidden to ensure that the edge does not contain any forbidden bit previously
		int candidate = forbidden | (1 << bit);

		DSU d(n);

		for(auto &[u, v, w]: edges) {
			if((w & candidate) == 0) {
				// this edge does not have any forbidden bits marked 
				d.merge(u, v);
			}
		}

		if(d.components == 1) {
			// this bit can remain zero
			forbidden = candidate;
		}
		else {
			// impossible to connect the graph without this bit
			result = result | (1 << bit);
		}
	}

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