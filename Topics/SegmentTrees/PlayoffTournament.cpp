// ============================================ segment trees + point updates ===================================

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

// question link: https://codeforces.com/problemset/problem/1535/D

/*
 * here we can use the segment tree to store the possible players 
 * in the game that is played at that node 
 * so store the Node as having two integers L and R 
 * L = players that came from the left child of the current node 
 * and similarly for R 
 * 
 * when the s[] = 0 => advance L to the next state and advance R for 0 
 * if s[] = ? then both L and R must move forward => return L + R
 * 
 * reverse the string to effeciently handle the games in the correct order 
 * as per the segment tree nodes => segment tree exactly mimics the games 
 * played in order 
 */

class SegmentTree {
private:	
	struct Node {
		int L, R;

		Node(int _L = 0, int _R = 0) : L(_L), R(_R) {}
	};

	vector<Node> tree;
	string str;

	Node merge(int ind) {
		int left = 2*ind+1;
		int right = 2*ind+2;

		// depending on what the left and right game score is return the result 
		// binary tree that is formed is mirrored because of reversed string 
		int ansL = winnerCount(right);
		int ansR = winnerCount(left);

		return Node(ansL, ansR);
	}

	void build(int ind, int low, int high) {
		// leaf node in the segment tree is first set of game played 
		if(high - low == 1) {
			// bottom level game so L = R = 1
			tree[ind] = Node(1, 1);
			return;
		}

		int mid = low + (high - low) / 2;
		build(2*ind+1, low, mid);
		build(2*ind+2, mid+1, high);

		// merge the nodes from the left and right 
		tree[ind] = merge(ind);
	}

	void update(int ind) {
		// update the node status based on the character and update its parent 
		int left = 2*ind+1, right = 2*ind+2;

		if(left >= tree.size()) {  // bottom game so L = R = 1
			tree[ind] = Node(1, 1);
		}
		else {  // normal game with left and right children so merge the node 
			tree[ind] = merge(ind);
		}

		// reached the top ind = 0 then dont do anything further 
		if(ind == 0) return;

		int parent = (ind - 1) / 2;
		update(parent);
	}

public: 
	SegmentTree(string &str) {
		// total 2 ^ k - 1 games are played => length of the string 
		int n = str.length();
		tree.resize(n);
		this->str = str;
		// low and high denote which teams could play the ind th game
		build(0, 0, n);
	}

	int winnerCount(int idx) {
		if(str[idx] == '0') return tree[idx].L;
		else if(str[idx] == '1') return tree[idx].R;
		else return tree[idx].L + tree[idx].R;
	}

	void updateQuery(int pos, char c) {
		// change the character at pos to c
		str[pos] = c;
		update(pos);
	}
};

void solve() {
	int k;
	cin >> k;

	string str;
	cin >> str;

	reverse(str.begin(), str.end());
	int n = str.length();
	// n = 2 ^ k - 1 

	SegmentTree seg(str);

	int q;
	cin >> q;

	while(q--) {
		int p;
		char c;
		cin >> p >> c;
		// make the pos index 0 based index 
		p--;

		int idx = n - 1 - p;

		seg.updateQuery(idx, c);
		cout << seg.winnerCount(0) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}