// ======================================= segement trees ===============================

#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/contest/380/problem/C

/* Explanation in notes => very important Question => logic can be used for other parenthesis questions 
   This question involves storing multiple pieces of information in the nodes of segment tree */

class SegmentTree {
private:
	struct Node {
		int open, close, full;

		Node() : open(0), close(0), full(0) {}
		Node(int o, int c, int f) : open(o), close(c), full(f) {}
	};

	vector<Node> tree;
	string s;
	int n;

	Node merge(Node &left, Node &right) {
		// when left and right nodes are to be combined 
		int new_full = min(left.open, right.close);

		Node res;
		res.full = left.full + right.full + new_full;
		//  new_full = min(open, close) => these many opens were used up
		res.open = left.open - new_full + right.open; 
		res.close = left.close + right.close - new_full;

		return res;
	}

	void build(int ind, int low, int high) {
		// base case: segment contains only one char
		if(low == high) {
			if(s[low] == '(') tree[ind].open++;
			else tree[ind].close++;

			return;
		}

		int mid = (low + high) / 2;

		build(2*ind+1, low, mid);
		build(2*ind+2, mid+1, high);

		// merge the left child and right child node to get the final tree[ind]
		tree[ind] = merge(tree[2*ind+1], tree[2*ind+2]);
	}

	Node query(int ind, int low, int high, int l, int r) {

		if(l <= low && high <= r) {
			// complete overlap => return the entire node
			// [l...low...high...r]
			return tree[ind]; 
		}
		else if(r < low || high < l) {
			// no overlap => [l..r]..[low...high] and vice versa 
			Node temp;
			return temp;
		}
		else {
			// case of partial overlap => call the left and right and return the merge one 
			int mid = (low + high) / 2;
			Node left = query(2*ind+1, low, mid, l, r);
			Node right = query(2*ind+2, mid+1, high, l, r);

			return merge(left, right);
		}
	}

public:
	SegmentTree(string &str) {
		s = str;
		n = s.length();

		tree.resize(4 * n);
		build(0, 0, n-1);
	}

	int query(int l, int r) {
		// returns the length of full bracket sequences in [l, r]
		// note => l and r are 1 based indexing
		Node res = query(0, 0, n-1, l-1, r-1);

		// max length = 2 * number of full bracket sequences 
		return 2 * res.full;
	}
};

void solve() {
	// string is given as 1 based indexing 
	string s;
	cin >> s;

	SegmentTree seg(s);

	int q;
	cin >> q;

	while(q--) {
		int l, r;
		cin >> l >> r;

		cout << seg.query(l, r) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}