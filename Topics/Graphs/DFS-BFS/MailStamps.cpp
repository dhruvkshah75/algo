// ============================= dfs ========================================

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

// question link: https://codeforces.com/problemset/problem/29/C

/**
 * The question is actually very straightforward 
 * eaach stamp is a edge in the graph 
 * the graph formed will be a simple path 
 * so it will have all vertices with degree = 2 and only two end nodes 
 * with a degree of 1 
 * 
 * start the dfs from any one of the node with degree = 1 to begin with 
 **/

unordered_map<int,vector<int>> adj;

void dfs(int node, int parent) {
	// print the node value and move to its neighbour 
	cout << node << " ";

	for(int child: adj[node]) {
		if(child == parent) continue;
		dfs(child, node);
	}
}

void solve() {
	int n;
	cin >> n;
	// n is the number of edges 

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// now get the node with degree 1 to start the traversal 
	int start = -1;
	for(auto &[node, nbgs]: adj) {
		if(nbgs.size() == 1) {
			start = node;
			// dfs traversal from this starting node 
			dfs(start, -1);
			cout << endl;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
