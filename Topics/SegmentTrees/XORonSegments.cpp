// ================================== segment trees + bitmasking ====================================

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

// question link: https://codeforces.com/problemset/problem/242/E

/**
 * we cannot do the segment update on a single segment tree 
 * but we can easily handle this operarion on a single bit 
 * so consider using 20 segment trees (10^6 max bit is 19th bit) => each segment 
 * tree handles a single bit 
 * ith segment tree handles the ops on ith bit 
 * 
 * leaf node of the ith segment tree stores either 0 or 2 ^ i (if the ith bit is set)
 * and the segment tree simply does a range sum 
 * obviously it is requires lazy propogation
 * lets say on xor with x for the ith bit, then how to update the value for the entire segment 
 * new_sum = (r-l+1) * 2 ^ i - old_sum ==> on flipping the bits the sum also flips in this order 
 * and lazy[] = 1 means pending work to be pushed to the children 
 **/

class SegmentTree {
private:
	vector<ll> tree;
	vector<int> lazy;
	int i;  // ith segment tree

	void build(int ind, int low, int high, vector<int> &arr) {
		// reached the leaf node
		if(low == high) {
			tree[ind] = arr[low] & (1 << i); // 0 or 2 ^ i
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);
		tree[ind] = tree[2*ind+1] + tree[2*ind+2];
	}

	void push(int ind, int low, int high) {
		// if leaf node or no lazy work left 
		if(lazy[ind] == 0 || low == high) return;

		int mid = low + (high - low) / 2;
		int left = 2*ind+1, right = 2*ind+2;
		int left_len = mid - low + 1, right_len = high - mid;

		// update the segment result for the left child
		tree[left] = left_len * 1LL * (1 << i) - tree[left];
		lazy[left] ^= 1;

		// update the segment result for the right child
		tree[right] = right_len * 1LL * (1 << i) - tree[right];
		lazy[right] ^= 1;

		lazy[ind] = 0;
	}

public:
	SegmentTree(int n, int i, vector<int> &arr) {
		this->i = i;
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		build(0, 0, n-1, arr);
	}

	void update(int ind, int low, int high, int l, int r) {
		// flip the sum for the ith bit only when ith bit of x is set
		if(high < l || r < low) {
			// no overlap 
			return;
		}
		else if(l <= low && high <= r) {
			// complete overlap so apply flip of sum for the entire segment
			int len = high - low + 1;
			tree[ind] = len * 1LL * (1 << i) - tree[ind];
			lazy[ind] ^= 1;
			return;
		}
		else {
			// partial overlap => complete the pending work
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			update(2*ind+1, low, mid, l, r);
			update(2*ind+2, mid+1, high, l, r);

			tree[ind] = tree[2*ind+1] + tree[2*ind+2];
		}
	}

	ll query(int ind, int low, int high, int l, int r) {

		if(high < l || r < low) {
			// no overlap => so no contribution of this segment
			return 0;
		}
		else if(l <= low && high <= r) {
			// complete overlap so return the ans 
			return tree[ind];
		}
		else {
			// partial overlap so complete the pending work
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			return query(2*ind+1, low, mid, l, r) + query(2*ind+2, mid+1, high, l, r);
		}
	}
};

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	vector<SegmentTree> segs;
	segs.reserve(20);

	for(int i = 0; i < 20; i++) {
		segs.emplace_back(n, i, arr);
		// emplavce back calls the constructor of the class
	}

	int q;
	cin >> q;

	while(q--) {
		int type;
		cin >> type;

		if(type == 1) {
			// return the range sum => simply sum the ans for all the 20 segment trees
			int l, r;
			cin >> l >> r;
			l--;
			r--;

			ll res = 0;

			for(int i = 0; i < 20; i++) {
				res += segs[i].query(0, 0, n-1, l, r);
			}

			cout << res << endl;
		}
		else {
			// range update query where we update the ith bit if that bit is set in x 
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			r--;

			for(int i = 0; i < 20; i++) {
				if(x & (1 << i)) {
					segs[i].update(0, 0, n-1, l, r);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}