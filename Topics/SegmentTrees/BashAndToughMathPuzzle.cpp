// ==================================== segment trees + number theory =========================================

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

// question link: https://codeforces.com/contest/914/problem/D

/**
 * Here we can use segment trees to answer the queries in O(LogN) time complexity 
 * as these are range based queries, and gcd for a segment can be calculated using this 
 * this segment tree supports point updates => query type 2 
 * the query method of the segment tree is different from usual 
 * since the gcds of ranges are build down to up in the seg tree we can count the number of bad leaves 
 * bad leaves => whose gcd is not a multiple of x 
 * query method uses the usual 3 cases of no overlap, complete overlap or partial overlap for answering the 
 * range based queries 
 **/

class SegmentTree {
private:
	int n;
	vector<int> tree;

	void build(int ind, int low, int high, vector<int> &arr) {
		// base case: reached a leaf node 
		if(low == high) {
			tree[ind] = arr[low];
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);

		tree[ind] = __gcd(tree[2*ind+1], tree[2*ind+2]);
	}

	void cntBad(int ind, int low, int high, int l, int r, int x, int &bad) {
		// base case: more than 1 bad leaves found 
		if(bad > 1) return;

		if(r < low || high < l) { // no overlap case 
			return;
		}
		else if(l <= low && high <= r) {  // complete overlap 
			// low..high is valid as gcd is a multiple of x
			if(tree[ind] % x == 0) return;

			// leaf node reached and is a bad node 
			if(low == high) {
				bad++; return;
			}

			int mid = low + (high - low) / 2;
			cntBad(2*ind+1, low, mid, l, r, x, bad);
			cntBad(2*ind+2, mid+1, high, l, r, x, bad);
		}
		else { // partial overlap => recurse left and right
			int mid = low + (high - low) / 2;
			cntBad(2*ind+1, low, mid, l, r, x, bad);
			cntBad(2*ind+2, mid+1, high, l, r, x, bad);
		}
	}

public:
	SegmentTree(int _n, vector<int> &arr) : n(_n) {
		tree.resize(4 * n);

		build(0, 0, n-1, arr);
	}

	bool query(int l, int r, int x) {
		int bad = 0;
		cntBad(0, 0, n-1, l, r, x, bad);
		return bad <= 1;
	}

	void update(int ind, int low, int high, int i, int y) {
		// base case: reached the node => low = high = i
		if(low == high) {
			tree[ind] = y;
			return;
		}

		int mid = low + (high - low) / 2;
		if(i <= mid) update(2*ind+1, low, mid, i, y);
		else update(2*ind+2, mid+1, high, i, y);

		tree[ind] = __gcd(tree[2*ind+1], tree[2*ind+2]); 
	}
};

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	SegmentTree seg(n, arr);

	// answer the queries 
	int q;
	cin >>q;

	while(q--) {
		int type;
		cin >> type;
		
		// note: the inputed l, r are 1 based indexed => convert to 0 based indexing 
		if(type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			
			if(seg.query(l-1, r-1, x)) {
				yes;
			}
			else {
				no;
			}
		}
		else {
			// point update query 
			int i, y;
			cin >> i >> y;
			seg.update(0, 0, n-1, i-1, y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}