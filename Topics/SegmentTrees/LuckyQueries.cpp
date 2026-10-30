// ============================= lazy propogation segment tree ===================================

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

template <typename T>
void printVec(const vector<T>& v) {
	for(const auto &x: v) cout << x << " ";
	cout << endl;
}

template <typename T> 
void print(const T& x) { cerr << x; }

template <typename A, typename B>
void print(const pair<A, B> &p) {
	cerr << "{"; print(p.first); cerr << " ";
	print(p.second); cerr << "}";
}

template <typename T>
void print(const vector<T> &v) {
	cerr << "[ ";
	for(const auto &x: v) {
		print(x); cerr << " ";
	}
	cerr << " ]" << endl;
}

/*
 * what does each node store => Node { cnt4, cnt7, best47, best74 }
 * how does the merging work out in this question 
 * max( left.best47 + right.cnt7, left.cnt4 + right.best47 )
 * similar logic for getting best74 sequence
 * 
 * while the range update includes switching all the 4s to 7s 
 * and vice versa => here the lazy propogation part is pretty much 
 * easy where we simply do swap(cnt4, cnt7) and swap(best74, best47)
 *
 * lazy pending work is simple 1 or 0 => either make the swap or not
 */

class SegmentTree {
private:
	struct Node {
		int cnt4;
		int cnt7;
		int best47;
		int best74;

		Node() : cnt4(0), cnt7(0), best47(0), best74(0) {} 
		Node(int _cnt4, int _cnt7, int _best47, int _best74) : cnt4(_cnt4), cnt7(_cnt7), best47(_best47), best74(_best74) {}
	};

	vector<Node> tree;
	vector<int> lazy;

	Node merge(Node left, Node right) {
		// simply merge the two nodes to get final node 
		Node result;

		result.cnt4 = left.cnt4 + right.cnt4;
		result.cnt7 = left.cnt7 + right.cnt7;
		result.best47 = max(left.cnt4 + right.best47, left.best47 + right.cnt7);
		result.best74 = max(left.cnt7 + right.best74, left.best74 + right.cnt4);

		return result;
	}

	void build(int ind, int low, int high, string &str) {
		// single element segment 
		if(low == high) {
			// for a leaf node best47 and best74 is always 1 
			if(str[low] == '4') tree[ind] = Node(1, 0, 1, 1);
			else tree[ind] = Node(0, 1, 1, 1);

			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid, str);
		build(2*ind+2, mid+1, high, str);
		tree[ind] = merge(tree[2*ind+1], tree[2*ind+2]);
	} 	

	void push(int ind, int low, int high) {
		// no pending work to be done 
		if(lazy[ind] == 0 || low == high) return;

		int left = 2 * ind + 1, right = 2 * ind + 2;

		// pending work involves swapping the values
		swap(tree[left].cnt4, tree[left].cnt7);
		swap(tree[left].best47, tree[left].best74);
		lazy[left] ^= 1;

		swap(tree[right].cnt4, tree[right].cnt7);
		swap(tree[right].best47, tree[right].best74);
		lazy[right] ^= 1;

		lazy[ind] = 0;
	}

public:
	SegmentTree(int n, string &str) {
		tree.resize(4 * n);
		lazy.assign(4 * n, 0);
		build(0, 0, n-1, str);
	}

	void update(int ind, int low, int high, int l, int r) {

		if(high < l || r < low) {
			// no overlap so do nothing 
			return;
		}
		else if(l <= low && high <= r) {
			// complete overlap => so update this segment
			swap(tree[ind].cnt4, tree[ind].cnt7);
			swap(tree[ind].best47, tree[ind].best74);
			lazy[ind] ^= 1;
		}
		else {
			// partial overlap so first complete the pending work
			push(ind, low, high);

			int mid = low + (high - low) / 2;
			update(2*ind+1, low, mid, l, r);
			update(2*ind+2, mid+1, high, l, r);
			tree[ind] = merge(tree[2*ind+1], tree[2*ind+2]);
		}
	}

	int query() {
		// return the longest non decreasing seq => 4444...77...
		return tree[0].best47;
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	string str;
	cin >> str;

	SegmentTree seg(n, str);

	while(q--) {
		string type;
		cin >> type;

		if(type == "count") {
			cout << seg.query() << endl;
		}
		else {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			seg.update(0, 0, n-1, l, r);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}