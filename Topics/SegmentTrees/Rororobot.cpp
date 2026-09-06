// ==================================== segment trees ============================================

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

// question link: https://codeforces.com/problemset/problem/1709/D

/*
 * Very Important question on segment trees and answering queries 
 * 
 * each query must be answered in O(1) or O(LogN)
 * here one of the biggest constraint is movement size = k
 * so before checking anything related to heights of the column 
 * 
 * condition: |x_start - x_end| % k == 0 or |y_start - y_end| % k == 0
 * 
 * Now we must consider the height constraint as the movement
 * from y_start to y_end must move past the max height but with constraint of k 
 * 
 * so we must get the max(a[l]....a[r]) in O(LogN) use segment tree with range queries 
 * on max with no point updates or lazy propogation
 * 
 * let H = max(a[l].....a[r])
 * we must compute the max height reachable from x_start
 * highest reach = x_start + ((n - x_start) / k) * k
 * the number of moves made to reach the max above = n - x_start / k
 */

class SegmentTree {
private:
	vector<int> tree;

	void build(int ind, int left, int right, vector<int> &arr) {
		// base case: single element reached
		if(left == right) {
			tree[ind] = arr[left];
			return;
		}

		int mid = left + (right - left) / 2;
		build(2*ind+1, left, mid, arr);
		build(2*ind+2, mid + 1, right, arr);

		tree[ind] = max(tree[2*ind+1], tree[2*ind+2]);
	}

public:
	SegmentTree(int n, vector<int> &arr) {
		tree.resize(4 * n);
		build(0, 0, n-1, arr);
	}

	int query(int ind, int left, int right, int l, int r) {

		if(l <= left && right <= r) {
			// complete overlap 
			return tree[ind];
		}
		else if(r < left || right < l) {
			// no overlap case => no contribution to ans 
			return -1e9;
		}
		else {
			// partial overlap case so move forward 
			int mid = left + (right - left) / 2;
			int val1 = query(2*ind+1, left, mid, l, r);
			int val2 = query(2*ind+2, mid + 1, right, l, r);

			return max(val1, val2);
		}
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	// keep the array 0 based 
	vector<int> arr(m);
	for(int i = 0; i < m; i++) cin >> arr[i];

	SegmentTree seg(m, arr);

	int q;
	cin >> q;
	while(q--) {
		int x_start, y_start, x_end, y_end, k;
		cin >> x_start >> y_start >> x_end >> y_end >> k;

		// make the cols 0 based indexing 
		y_start--; y_end--;

		// check k constraint 
		if(abs(y_start - y_end) % k != 0 || abs(x_start - x_end) % k != 0) {
			no;
			continue;
		}

		// l...r 
		int l = min(y_start, y_end), r = max(y_start, y_end);
		int H = seg.query(0, 0, m-1, l, r);

		// compute the highest valid k movement that can be made  
		int highest = x_start + ((n - x_start) / k) * k;

		if(highest > H) {
			// return yes if the highest reachable row > max height in the column
			yes;
		}
		else {
			no;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}