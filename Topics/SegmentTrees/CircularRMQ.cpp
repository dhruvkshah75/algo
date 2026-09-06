// ================================ lazy propogation segment tree =========================================

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

// question link: https://codeforces.com/problemset/problem/52/C 

/*
 * Segment tree is used to range queries for minimum in the segment 
 * and we want to make range updates by increasing all the values in the segment
 * with v 
 * 
 * here the array is circular so here we want the array to wrap arround itslef 
 * if l <= r => normal segment no wrap around => make single range query or range update 
 * if l > r => wrap arround => make two queries or updates => [l...n-1] and [0..r]
 * 
 * incrementing every single element also updates the min by the same amount 
 * so lazy simply stores the value v of increment to denote the pending work
 */

class SegmentTree {
private:
	vector<ll> tree;
	vector<ll> lazy;

	void build(int ind, int low, int high, vector<int> &arr) {
		// single element in the segment 
		if(low == high) {
			tree[ind] = arr[low];
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);

		tree[ind] = min(tree[2*ind+1], tree[2*ind+2]);
	}

	void push(int ind, int low, int high) {
		// no pending work or leaf child
		if(lazy[ind] == 0 || low == high) return;

		int left = 2*ind+1, right = 2*ind+2;
		int mid = low + (high - low) / 2;

		// apply the pending work on left child and right child
		tree[left] += lazy[ind];
		lazy[left] += lazy[ind];

		tree[right] += lazy[ind];
		lazy[right] += lazy[ind];

		// mark no pending work
		lazy[ind] = 0;
	}

public:
	SegmentTree(int n, vector<int> &arr) {
		tree.resize(4 * n);
		lazy.assign(4 * n, 0);
		build(0, 0, n-1, arr);
	}

	void update(int ind, int low, int high, int l, int r, int val) {

		if(high < l || r < low) {
			// no overlap so do nothing 
			return;
		}
		else if(l <= low && high <= r) {
			// complete overlap so make changes to this node and update the lazy pending work for its children 
			tree[ind] += val;
			lazy[ind] += val;
			return;
		}
		else {
			// case of partial overlap => first push the pending work to the children
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			update(2*ind+1, low, mid, l, r, val);
			update(2*ind+2, mid+1, high, l, r, val);

			// recompute the value for the node after updates 
			tree[ind] = min(tree[2*ind+1], tree[2*ind+2]);
		}
	}

	ll query(int ind, int low, int high, int l, int r) {

		if(high < l || r < low) {
			// no overlap so no contribution 
			return LLONG_MAX;
		}
		else if(l <= low && high <= r) {
			// complete overlap just return 
			return tree[ind];
		}
		else {
			// partial overlap => so first push the pending work down first
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			return min(query(2*ind+1, low, mid, l, r), query(2*ind+2, mid+1, high, l, r));
		}
	}
};

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	SegmentTree seg(n, arr);

	int q;
	cin >> q;

	string line;
	getline(cin, line);  // consume the '\n' left after reading m

	while(q--) {
		getline(cin, line);

		// use this as we dont know if we have three integers or not 
		stringstream ss(line);

		int l, r, v;
		ss >> l >> r;

		if(ss >> v) {
			// rang inc operation 
			if(l <= r) {
				// simple segment with no wrap arround
				seg.update(0, 0, n-1, l, r, v);
			}
			else {
				seg.update(0, 0, n-1, l, n-1, v);
				seg.update(0, 0, n-1, 0, r, v);
			}
		}
		else {
			// range min query is made
			if(l <= r) {
				cout << seg.query(0, 0, n-1, l, r) << endl;
			}
			else {
				// wrap around because the query extends through the circular part
				ll mn1 = seg.query(0, 0, n-1, l, n-1);
				ll mn2 = seg.query(0, 0, n-1, 0, r);

				cout << min(mn1, mn2) << endl;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}