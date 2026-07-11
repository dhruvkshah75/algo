// ================================================== Segment Trees ================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/339/D

// explanation in the notes 

class SegmentTree {
private:
	vector<int> tree, arr;

	void build(int ind, int low, int high, int iter) {
		// base case: single element 
		if(low == high) {
			tree[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2*ind+1, low, mid, iter-1);
		build(2*ind+2, mid+1, high, iter-1);

		// for odd iterations => operation used is bitwise OR
		if(iter & 1) 
			tree[ind] = tree[2*ind+1] | tree[2*ind+2];
		else 
			tree[ind] = tree[2*ind+1] ^ tree[2*ind+2];
	}

public:
	SegmentTree(int n, vector<int> &arr) {
		int sz = arr.size();
		this->arr = arr;
		tree.resize(4*sz);
		build(0, 0, sz-1, n);
	}

	int get_v() {
		// v is the top node in the segment tree
		return tree[0];
	}

	void update(int ind, int low, int high, int iter, int i, int val) {
		// base case: reached the target index i
		if(low == high) {
			tree[ind] = val;
			return;
		}

		int mid = (low + high) / 2;

		if(i <= mid) update(2*ind+1, low, mid, iter-1, i, val);
		else update(2*ind+2, mid+1, high, iter-1, i, val);

		// for odd iterations => to get the next element we do bitwise OR
		if(iter & 1) 
			tree[ind] = tree[2*ind+1] | tree[2*ind+2];
		else 
			tree[ind] = tree[2*ind+1] ^ tree[2*ind+2];
	}
};


void solve() {
	// note: The array is 1 based indexing => segment tree that is written is 0 based indexing
	int n, q;
	cin >> n >> q;

	int sz = (1 << n);

	// 1 <= n <= 17 => array has 2^n elements => size of array = (1 << n)
	vector<int> arr(sz);

	for(int i = 0; i < arr.size(); i++) 
		cin >> arr[i];

	SegmentTree seg(n, arr);

	while(q--) {
		int p, b;
		cin >> p >> b;
		// query means a[p] = b (update query) 
		// make the update queries 0 based indexing 
		seg.update(0, 0, sz-1, n, p-1, b);

		// the top node in the segment tree will be the v => result after all the iterations 
		cout << seg.get_v() << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}