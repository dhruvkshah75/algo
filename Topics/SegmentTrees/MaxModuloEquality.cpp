// ======================================= segment trees =======================================================

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

// question link: https://codeforces.com/problemset/problem/2050/F

/*
 * what is the answer for each query [l..r]
 * a[l] % m = a[l+1] % m = ..... = a[r] % m = x (let)
 * x can be anything from [0...m-1]
 * so consider taking the diff to make modulo m = 0 (factor)
 * a[l] - a[l+1] % m = 0 => and to get max such m we can say that 
 * this m will be the gcd of the segment 
 * 
 * now on changing the array => query range also changes to [l...r-1]
 * and each query can be answered in O(LogN) to get the gcd of the range 
 */

class SegmentTree {
private:
	vector<int> tree;

	void build(int ind, int low, int high, vector<int> &arr) {
		// base case: cannot break further 
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
		tree.assign(4 * n, 0);
		build(0, 0, n-1, arr);
	}

	int query(int ind, int low, int high, int l, int r) {

		if(high < l || r < low) {
			// no overlap => no contribution 
			return 0;
		}
		else if(l <= low && high <= r) {
			// complete overlap
			return tree[ind];
		}
		else {
			// partial overlap go to the left and right sides 
			int mid = low + (high - low) / 2;
			int left = query(2*ind+1, low, mid, l, r);
			int right = query(2*ind+2, mid+1, high, l, r);
			return __gcd(left, right);
		}
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	// when n = 1 (single element then diff array cannot be created)
	if(n == 1) {
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }

	vector<int> diff_arr(n-1);
	for(int i = 0; i < n-1; i++) {
		diff_arr[i] = abs(arr[i] - arr[i+1]);
		// keep all the terms positive in the diff array 
	}

	SegmentTree seg(n-1, diff_arr);

	while(q--) {
		int l, r;
		cin >> l >> r;
		// queries are 1 based indexing => make it 0 based 
		l--;
		r--;

		if(l == r) {
			cout << 0 << " ";
			continue;
		}

		// segment to query is [l...r-1]
		int result = seg.query(0, 0, n-2, l, r-1);
		cout << result << " ";
	}
	cout << endl;
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