// =============================== segment trees + lazy propogation ==========================

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

/*
 * consider a simple range query and range update example where we calculate the range sum 
 * and we are given some queries based on ranges to add value to it 
 * like [1..5] => add 10 to all elements in the range 
 * 
 * so we cannot individually make the range updates as this can lead to O(N) update 
 * in worst case to solve this we use a concept called lazy propogation 
 * 
 * what do we do when we make updates and if there is a complete overlap 
 * i.e [l...low...high...r] then instead of going down to the children of [low...high]
 * update this node with lazy[node] as we dont make the changes to children we can make these changes 
 * later when we make updates or queries in that interval 
 * 
 * use the concept of push(node) so that the we update the changes that are to be made to further
 * nodes 
 * here the lazy[node] stores the changes that are to be made per element 
 * so for entire segment the new updated value will be tree[child] += lazy[node] * segment length
 */

class SegmentTree {
private:
	vector<int> tree;
	vector<int> lazy;

	void build(int ind, int low, int high, vector<int> &arr) {
		// base case: single element segment reached 
		if(low == high) {
			tree[ind] = arr[low];
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);

		tree[ind] = tree[2*ind+1] + tree[2*ind+2];
	}

	// push the lazy updates to the children of the node 
	void push(int ind, int low, int high) {
		// single element segment or no lazy update to make 
		if(lazy[ind] == 0 || low == high) 
			return;

		int mid = low + (high - low) / 2;

		// make the left and right child nodes to have correct values and store the lazy update rule
		tree[2*ind+1] += lazy[ind] * (mid - l + 1);
		lazy[2*ind+1] += lazy[ind];

		tree[2*ind+2] += lazy[ind] * (high - mid);
		lazy[2*ind+2] += lazy[ind];

		// parent no longer has any pending work or lazy updates left
		lazy[ind] = 0; 
	}

public: 
	SegmentTree(int n, vector<int> &arr) {
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);

		build(0, 0, n-1, arr);
	}

	void update(int ind, int low, int high, int l, int r, int val) {
		// update the segment [l..r]

		if(high < l || r < low) {
			// no overlap so do nothing 
			return;
		}
		else if(l <= low && high <= r) {
			// complete overlap so make changes to this node and update the lazy or pending work for its children 
			tree[ind] = val * (high - low + 1);
			lazy[ind] += val;
			return;
		}
		else {
			// case of partial overlap => first push the pending work or lazy update to its children so we can go down
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			update(2*ind+1, low, mid, l, r, val);
			update(2*ind+2, mid+1, high, l, r, val);

			// recompute the value for the node after updates 
			tree[ind] = tree[2*ind+1] + tree[2*ind+2];
		}
	}

	int query(int ind, int low, int high, int l, int r) {

		if(high < l || r < low) {
			// no overlap case => so no contribution 
			return 0;
		}
		else if(l <= low && high <= r) {
			// complete overlap case so return the ans for this segment 
			return tree[ind];
		}
		else {
			// partial overlap so first update the pending work to the children of node at ind 
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			return query(2*ind+1, low, mid, l, r) + query(2*ind+2, mid+1, high, l, r); 
		}
	}
};

