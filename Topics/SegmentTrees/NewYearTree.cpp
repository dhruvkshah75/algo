// ============================ euler tour + lazy propogation segment trees ====================================

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

// question link: https://codeforces.com/problemset/problem/620/E

/*
 * since we must deal with the subtree of a tree at the same time we must consider 
 * the euler tour of the tree 
 * to answer the queries we must a segment trees with lazy propogation as 
 * we need to change the colour of all the nodes in the subtree of a node 
 * since there are only 60 different colours we can use long long bitmask 
 * to store the what all colours exist in the subtree 
 * 
 * Query in the Segment tree returns the mask rather than the setbits 
 * to prevent overcounting 
 */

int timer = 0;
vector<int> tin, tout;
vector<int> euler, color;
vector<vector<int>> adj;

void dfs(int node, int parent) {

	tin[node] = timer;
	euler[timer] = node;
	timer++;

	for(int child: adj[node]) {
		if(child == parent) continue;

		dfs(child, node);
	}

	tout[node] = timer-1;
}

class SegmentTree {
private:
	vector<ll> tree;
	vector<ll> lazy;

	void build(int ind, int low, int high) {
		// base case: single element segment 
		if(low == high) {
			int node = euler[low];
			int c = color[node];
			tree[ind] = (1LL << c);
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid);
		build(2*ind+2, mid+1, high);

		tree[ind] = tree[2*ind+1] | tree[2*ind+2];
	}

	void push(int ind, int low, int high) {
		// base case: no changes to push to the children of the ind
		if(lazy[ind] == 0 || low == high) return;

		int left = 2*ind+1, right = 2*ind+2;
		int mid = low + (high - low) / 2;

		// update the new mask for the left child of ind
		tree[left] = lazy[left] = lazy[ind];

		tree[right] = lazy[right] = lazy[ind];

		// mark no pending work left for the node 
		lazy[ind] = 0;
	}

public:
	SegmentTree(int n) {
		tree.resize(4 * n);
		lazy.assign(4 * n, 0);

		build(0, 0, n-1);
	}

	void update(int ind, int low, int high, int l, int r, int c) {

		if(high < l || r < low) {
			// no overlap case => no contribution 
			return;
		}
		else if(l <= low && high <= r) {
			// complete overlap => update the ans for this node and mark the pending work 
			tree[ind] = (1LL << c);
			lazy[ind] = tree[ind];
			return;
		}
		else {
			// partial overlap => complete the pending work first 
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			update(2*ind+1, low, mid, l, r, c);
			update(2*ind+2, mid+1, high, l, r, c);

			tree[ind] = tree[2*ind+1] | tree[2*ind+2];
		}
	}

	ll query(int ind, int low, int high, int l, int r) {

		if(r < low || high < l) {
			// no overlap so no contribution
			return 0;
		}
		else if(l <= low && high <= r) {
			// complete overlap simply return the mask of this node 
			return tree[ind];
		}
		else {
			// partial overlap => first complete the pending work
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			ll left = query(2*ind+1, low, mid, l, r);
			ll right = query(2*ind+2, mid+1, high, l, r);

			return left | right; 
		}
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	color.resize(n+1);
	for(int i = 1; i <= n; i++) cin >> color[i];

	adj.assign(n+1, {});
	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	tin.resize(n+1);
	tout.resize(n+1);
	euler.resize(n);

	// get the euler tour of the tree 
	dfs(1, -1);

	SegmentTree seg(n);

	while(m--) {
		int type;
		cin >> type;

		if(type == 1) {
			int v, c;
			cin >> v >> c;
			int l = tin[v], r = tout[v];
			seg.update(0, 0, n-1, l, r, c);
		}
		else {
			int v;
			cin >> v;
			int l = tin[v], r = tout[v];

			ll mask = seg.query(0, 0, n-1, l, r);
			ll result = setbitsll(mask);
			cout << result << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}