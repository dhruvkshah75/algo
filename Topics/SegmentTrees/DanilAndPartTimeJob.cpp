// ============================ lazy propogation segment trees + euler tour ===================================

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

// question link: https://codeforces.com/problemset/problem/877/E

/*
 * we must deal with all the nodes present in some nodes subtree at the same time 
 * so using euler tour is the best option 
 * subtree of each node in euler tour is the segment [tin[node], tout[node]]
 * 
 * pow v => switch the lights in the subtree of vertex v => on becomes off and vice versa
 * get v => returns the count of nodes in the subtree of v where light is turned on 
 * 
 * we can make the leaf nodes (single element segments) can be marked as 0, 1 
 * 0 = light is turned off and 1 = light is turned on 
 * and take the sum across all the nodes in the segment tree 
 * 
 * in the segment tree what does update at the current node look like 
 * flipping all the switches right => tree[ind] = sz - tree[ind]
 * here the lazy only store 0 or 1 => indicates if the flip is pending or not
 * flip the lazy[ind] as there may already be pending work and then we flip again restoring 
 * the original configuration 
 */

int timer = 0;
vector<int> tin, tout;
vector<int> euler, light;
vector<vector<int>> adj;

void dfs(int node, int parent) {
	// each nodes subtree = [tin[node], tout[node]]
	tin[node] = timer;
	euler[timer] = node;
	timer++;

	for(int child: adj[node]) {
		if(child == parent) continue;

		dfs(child, node);
	}

	tout[node] = timer - 1;
}


class SegmentTree {
private:
	vector<int> tree;
	vector<int> lazy;

	void build(int ind, int low, int high) {
		// base case: single element segment 
		if(low == high) {
			int node = euler[low];
			tree[ind] = light[node];
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid);
		build(2*ind+2, mid+1, high);

		tree[ind] = tree[2*ind+1] + tree[2*ind+2];
	}

	void push(int ind, int low, int high) {
		// when no lazy changes to make or single element segment 
		if(lazy[ind] == 0 || low == high) return;

		int mid = low + (high - low) / 2;
		int left = 2*ind+1, right = 2*ind+2;

		// for the child flip all the lights and mark pending work for its children
		tree[left] = (mid - low + 1)  - tree[left];
		lazy[left] ^= 1;

		tree[right] = (high - mid) - tree[right];
		lazy[right] ^= 1;

		// unmark the pending work of ind
		lazy[ind] = 0;
	}

public:
	SegmentTree(int n) {
		tree.resize(4*n);
		lazy.assign(4*n, 0);

		build(0, 0, n-1);
	}

	void update(int ind, int low, int high, int l, int r) {
		
		if(high < l || r < low) {
			// no overlap case => no contribution
			return;
		}
		else if(l <= low && high <= r) {
			// complete overlap for this node => make this update here and mark pending work
			tree[ind] = (high - low + 1) - tree[ind];
			lazy[ind] ^= 1;
		}
		else {
			// partial overlap so first push the pending work 
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			update(2*ind+1, low, mid, l, r);
			update(2*ind+2, mid+1, high, l, r);

			tree[ind] = tree[2*ind+1] + tree[2*ind+2];
		}
	}

	int query(int ind, int low, int high, int l, int r) {

		if(high < l || r < low) {
			// no overlap so no contribution 
			return 0;
		}
		else if(l <= low && high <= r) {
			// complete overlap so just return the score 
			return tree[ind];
		}
		else {
			// partial overlap case => complete the pending work of the children
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			return query(2*ind+1, low, mid, l, r) + query(2*ind+2, mid+1, high, l, r);
		}
	}
};

void solve() {
	int n;
	cin >> n;

	adj.resize(n+1);
	tin.resize(n+1);
	tout.resize(n+1);
	euler.resize(n);

	for(int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		// edge is from p to i
		adj[p].push_back(i);
		adj[i].push_back(p);
	}

	light.resize(n+1);
	for(int i = 1; i <= n; i++) cin >> light[i];

	dfs(1, -1);

	SegmentTree segs(n);

	int q;
	cin >> q;

	while(q--) {
		string str;
		int v;
		cin >> str >> v;
		int l = tin[v], r = tout[v];

		if(str == "get") {
			int result = segs.query(0, 0, n-1, l, r);
			cout << result << endl;
		}
		else {
			segs.update(0, 0, n-1, l, r);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}