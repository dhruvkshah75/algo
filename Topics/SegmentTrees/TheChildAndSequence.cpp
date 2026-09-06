// =============================== segment trees + pruning + math ===============================

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

// question link: https://codeforces.com/contest/438/problem/D

/*
 * note: (a1 + a2 + a3 + a4 + ... + an) mod x = (a1 mod x + a2 mod x + ...) mod x
 * but taking individually mod is simply (a1 mod x + a2 mod x + ... + an mod x) 
 * 
 * so simply lazy propogation wont work on this question so simply use the idea of pruning 
 * certain segments that do not need to reach and update all the leaf nodes 
 * this includes => case when each segments elements < x => so the mod operation wont make sense 
 * 
 * this simple pruning makes the solution work out within the time constraints
 * as after updates are made the values of elements in the segment actualy become very less 
 */


class SegmentTree {
private:
	struct Node {
		ll sum;
		int mx;

		Node() : sum(0), mx(0) {}
		Node(ll _sum, int _mx) : sum(_sum), mx(_mx) {}
	};

	vector<Node> tree;

	void merge(int ind) {
		tree[ind].sum = tree[2*ind+1].sum + tree[2*ind+2].sum;
		tree[ind].mx = max(tree[2*ind+1].mx, tree[2*ind+2].mx);
	}

	void build(int ind, int low, int high, vector<int> &arr) {
		// single element segment => leaf node 
		if(low == high) {
			tree[ind] = Node((ll)arr[low], arr[low]);
			return;
		}

		int mid = low + (high - low) / 2;

		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);
		merge(ind);
	}

public:
	SegmentTree(int n, vector<int> &arr) {
		tree.resize(4 * n);
		build(0, 0, n-1, arr);
	}

	void point_update(int ind, int low, int high, int index, int val) {
		// update the single element to arr[index] = val

		// single element => leaf node reached so update the value
		if(low == high) {
			tree[ind] = Node((ll)val, val);
			return;
		}

		int mid = low + (high - low) / 2;

		if(index <= mid) point_update(2*ind+1, low, mid, index, val);
		else point_update(2*ind+2, mid+1, high, index, val);

		merge(ind);
	}

	void range_update(int ind, int low, int high, int l, int r, int x) {

		if(high < l || r < low) { 
			// no overlap => no contribution 
			return;
		}
		else if(tree[ind].mx < x) {  
			// pruning step => mx[l...r] < x so mod changes nothing
			return;
		}
		else if(low == high) { 
			// leaf node 
			tree[ind].sum %= x;
			tree[ind].mx %= x;
			return;
		}

		int mid = low + (high - low) / 2;

		range_update(2*ind+1, low, mid, l, r, x);
		range_update(2*ind+2, mid+1, high, l, r, x);
		merge(ind);
	}

	ll query_sum(int ind, int low, int high, int l, int r) {

		if(high < l || r < low) {
			// no contribution => no contribution to the answer 
			return 0;
		}
		else if(l <= low && high <= r) {
			// complete overlap so return the ans 
			return tree[ind].sum;
		}
		else {
			// partial overlap => so traverse through the segments 
			int mid = low + (high - low) / 2;
			ll left = query_sum(2*ind+1, low, mid, l, r);
			ll right = query_sum(2*ind+2, mid+1, high, l, r);

			return left + right;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	SegmentTree seg(n, arr);

	while(q--) {
		int type;
		cin >> type;

		if(type == 1) {
			int l, r;
			cin >> l >> r;
			l--; r--;
			// make the segment 0 based indexing 
			cout << seg.query_sum(0, 0, n-1, l, r) << endl;
		}
		else if(type == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			l--; r--; 
			// make the segment 0 based indexing 
			seg.range_update(0, 0, n-1, l, r, x);
		}
		else {
			int idx, val;
			cin >> idx >> val;
			idx--;
			seg.point_update(0, 0, n-1, idx, val);
		}
	}
}
