// =========================== segment trees with point updates =======================================

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

// question link: https://codeforces.com/problemset/problem/570/C

class SegmentTree {
private:
	vector<int> tree;
	string str;

	void merge(int ind, int mid) {
		// on merging two nodes compare the mid, mid+1
		int add = (str[mid] == '.' && str[mid+1] == '.') ? 1 : 0;
		tree[ind] = tree[2*ind+1] + tree[2*ind+2] + add;
	}

	void build(int ind, int low, int high) {
		// base case: single element reached
		if(low == high) {
			tree[ind] = 0;
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid);
		build(2*ind+2, mid+1, high);
		merge(ind, mid);
	}

public:
	SegmentTree(int n, string &str) {
		tree.assign(4 * n, 0);
		this->str = str;
		build(0, 0, n-1);
	}

	void update(int ind, int low, int high, int idx, char c) {
		// base case: reached the single element 
		if(low == high) {
			str[low] = c;
			return; 
		}

		int mid = low + (high - low) / 2;

		if(idx <= mid) update(2*ind+1, low, mid, idx, c);
		else update(2*ind+2, mid+1, high, idx, c);
		// update the segment answer 
		merge(ind, mid);
	}

	// return the value for the segment [0....n-1]
	int query() {
		return tree[0];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	string str;
	cin >> str;

	SegmentTree seg(n, str);

	while(q--) {
		int idx;
		char c;
		cin >> idx >> c;
		idx--; // make the index 0 based 

		seg.update(0, 0, n-1, idx, c);
		cout << seg.query() << endl;
	}
}