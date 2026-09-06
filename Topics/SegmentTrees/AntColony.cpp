// =========================== segment trees + binary search =====================================

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

// question link: https://codeforces.com/problemset/problem/474/F

/*
 * in a segment a ant is only freed when si can divide all elements in the segment 
 * that is when the gcd of the segment is eqaul to that value 
 * using a map<int,vector<int>> pos we can get what are all the occurrences of a number
 * mp[val] = all the indexes i such that arr[i] = val
 * in the segment [l...r] 
 * cnt = upperbound(mp[gcd], r) - lowerbound(mp[val], l) => number of occurrences of gcd 
 * in the segment [l...r]
 */

class SegmentTree {
private:
	vector<int> tree;

	void build(int ind, int low, int high, vector<int> &arr) {
		// single element then gcd = val
		if(low == high) {
			tree[ind] = arr[low];
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);

		tree[ind] = __gcd(tree[2*ind+1], tree[2*ind+2]);
	}

public:
	SegmentTree(int n, vector<int> &arr) {
		tree.resize(4 * n);
		// build the gcd segment tree 
		build(0, 0, n-1, arr);
	}

	int query(int ind, int low, int high, int l, int r) {
		// return the gcd(arr[l...r])
		if(high < l || r < low) {
			// no overlap case => no contribution 
			return 0;
		}
		else if(l <= low && high <= r) {
			// complete overlap case 
			return tree[ind];
		}
		else {
			// case of partial overlap 
			int mid = low + (high - low) / 2;
			int left = query(2*ind+1, low, mid, l, r);
			int right = query(2*ind+2, mid+1, high, l, r);

			return __gcd(left, right);
		}
	}
};

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	unordered_map<int,vector<int>> pos;
	// pos[val] = stores all the indexes of occurrences of val

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		pos[arr[i]].push_back(i);
	}

	SegmentTree segs(n, arr);

	int q;
	cin >> q;

	while(q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		// make l and r => 0 based indexing 

		int val = segs.query(0, 0, n-1, l, r);

		// count the number of ants that will be freed 
		if(pos.find(val) == pos.end()) {
			cout << r-l+1 << endl;
		}
		else {
			int cnt = upper_bound(all(pos[val]), r) - lower_bound(all(pos[val]), l);
			// cnt = [0....r] - [0...l-1]
			cout << r-l+1 - cnt << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}