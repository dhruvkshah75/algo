// =============================== segment trees + bitmasking ===============================================

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

// question link: https://codeforces.com/problemset/problem/1234/D 

/*
 * The queries involve point updates and range queries to get the 
 * number of distinct characters in the segment [l...r]
 * each node in the segment tree can have a vector<int> hash(26, 0)
 * and count of distinct characters instead of that 
 * use a bitmask of size 26 which fits inside of size of int 
 * 
 * so the unique or distinct characters in the segment will 
 * be setbits(node's mask) and when merging two nodes simply take the 
 * OR of the two segments mask 
 * 
 * query method of segment tree returns the mask instead of distincr characters 
 * as returning the setbits can cause overcounting 
 * after the query returns the mask by doing appropriate ORs then we can 
 * take the setbits cnt of the mask to be the distinct characters 
 */

class SegmentTree {
private:
	vector<int> tree;

	void build(int ind, int low, int high, string &str) {
		// base case single element in the segment 
		if(low == high) {
			int idx = str[low] - 'a';
			tree[ind] = (1 << idx);
			// set the idx th bit in the mask 
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid, str);
		build(2*ind+2, mid+1, high, str);

		tree[ind] = tree[2*ind+1] | tree[2*ind+2];
	}

public:
	SegmentTree(int n, string &str) {
		tree.assign(4 * n, 0);
		build(0, 0, n-1, str);
	}

	void update(int ind, int low, int high, int x, char c) {
		// base case: reached the index to make changes 
		if(low == high) {
			int idx = c - 'a';
			tree[ind] = (1 << idx);
			return;
		}

		int mid = low + (high - low) / 2;
		if(x <= mid) update(2*ind+1, low, mid, x, c);
		else update(2*ind+2, mid+1, high, x, c);

		// merge the left and right nodes => OR of the masks 
		tree[ind] = tree[2*ind+1] | tree[2*ind+2];
	}

	int query(int ind, int low, int high, int l, int r) {
		// consider the 3 cases: no overlap, partial overlap and complete overlap

		if(l <= low && high <= r) {
			// complete overlap so return the mask at the current node  
			return tree[ind];
		}
		else if(high < l || r < low) {
			// no overlap => so no contribution 
			return 0;
		}
		else {
			int mid = low + (high - low) / 2;
			int left_mask = query(2*ind+1, low, mid, l, r);
			int right_mask = query(2*ind+2, mid+1, high, l, r);

			return left_mask | right_mask;
		}
	}
};

void solve() {
	string str;
	cin >> str;

	int n = str.length();

	SegmentTree seg(n, str);

	int q;
	cin >> q;

	while(q--) {
		int type;
		cin >> type;

		if(type == 1) {
			int pos;
			char c;

			cin >> pos >> c;
			pos--;
			// make pos 0 indexed 
			seg.update(0, 0, n-1, pos, c);
		}
		else {
			int l, r;
			cin >> l >> r;

			// make the indexes 0 based 
			l--;
			r--;

			int mask = seg.query(0, 0, n-1, l, r);

			cout << setbits(mask) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}