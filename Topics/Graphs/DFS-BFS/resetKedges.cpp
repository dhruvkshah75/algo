// ================================== binary search + dfs ===============================================

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

// question link: https://codeforces.com/problemset/problem/1739/D

/*
 * apply binary search on answer that is the smallest height after k operations 
 * now how to decide when to make the cut in a effecient way 
 * let the smallest height be x 
 * 
 * so if we want the height of the tree to be x
 * we keep a track of max depth when when we apply dfs through the tree 
 * make the cut from node u - node v when the mx depth of the any node in the subtree 
 * of node v is x-1 and dont make cuts such that u = 1 i.e. (1 - v) as cutting 
 * it makes no sense 
 */

vector<vector<int>> adj;

int dfs(int node, int parent, int &cuts, int x) {
	int mx = 0;

	for(int child: adj[node]) {
		if(child == parent) continue;

		int d = dfs(child, node, cuts, x);
		mx = max(mx, d + 1);
	}

	// while backtracking check if here cut can be made or not 
	if(mx == x-1 && parent != 1 && node != 1) {
		// subtree rooted at node has max depth of x-1 so make a cut 
		cuts++;

		// disconneting the edge so the mx depth for above nodes needs to change 
		return -1;
	}

	return mx;
}

bool predicateF(int x, int k) {
	// can we make <= k cuts to get the tree with height <= x

	int cuts = 0;
	int temp = dfs(1, -1, cuts, x);

	return cuts <= k;
}

void solve() {
	int n, k;
	cin >> n >> k;

	adj.assign(n+1, {});
	for(int i = 2; i <= n; i++) {
		// edge => i -> p[i]
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}

	int low = 1, high = n;
	int ans = -1;

	// predicate function returns => FFFFFTTTTT
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(predicateF(mid, k)) {
			ans = mid;
			high = mid-1;
		}
		else low = mid + 1;
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