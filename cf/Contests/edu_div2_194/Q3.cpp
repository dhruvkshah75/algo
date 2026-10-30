
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

/**
 * use segment tree where each node stores the first and last char 
 * and cnt of 00, 01, 10, 11 and then based on it we can query this info 
 * in LogN time and then figure out a way to get the min ops 
 * 
 * cnt01 = cnt10 for any substring in the given segment
 * 
 * so currently the 00, 01, 10, 11 => (a, x, x, b)
 * we want to make it into (k, k, k, k) => so a total of 4k cyclic pairs
 * 
 * 00 -> adding 0 => gives 1 more 00 and adding 1 gives 01 and 10 and removes 00 from it
 * and similarly for other cases 
 * 
 * say we have extra 00s so we remove them by adding 1 in bw and get 01 and 10
 * similarly for extra 11s we can do the same thing get 10 and 01 
 * so to bring the cnt00 to k -> we must remove a - k of 00s 
 * and similarly remove b-k of 11s to update the cnt 
 **/

struct Node {
    char first = '?';
    char last = '?';
    int cnt00 = 0;
    int cnt01 = 0;
    int cnt10 = 0;
    int cnt11 = 0;
    int len = 0;

    Node() = default;

    Node(char ch) {
        first = last = ch;
        len = 1;
    }
};

class SegmentTree {
private:
	vector<Node> tree;
	string str;

	Node merge(const Node &left, const Node &right) {
        // Empty segment handling
        if(left.len == 0) return right;
        if(right.len == 0) return left;

        Node result;

        result.first = left.first;
        result.last = right.last;
        result.len = left.len + right.len;
        result.cnt00 = left.cnt00 + right.cnt00;
        result.cnt01 = left.cnt01 + right.cnt01;
        result.cnt10 = left.cnt10 + right.cnt10;
        result.cnt11 = left.cnt11 + right.cnt11;

        // Pair formed at the boundary
        if(left.last == '0' && right.first == '0') result.cnt00++;
        else if(left.last == '0' && right.first == '1') result.cnt01++;
        else if(left.last == '1' && right.first == '0') result.cnt10++;
        else result.cnt11++;

        return result;
    }

	void build(int ind, int low, int high) {
		// single element segment 
		if(low == high) {
			tree[ind] = Node(str[low]);
			return;
		}

		int mid = low + (high - low) / 2;

		build(2*ind+1, low, mid);
		build(2*ind+2, mid+1, high);
		tree[ind] = merge(tree[2*ind+1], tree[2*ind+2]);
	}

public:
	SegmentTree(int n, string &str) {
		this->str = str;
		tree.resize(4 * n);
		build(0, 0, n-1);
	}

	Node query(int ind, int low, int high, int l, int r) {

		if(high < l || r < low) {
			// zero overlap => no contribution
			return Node();
		}
		else if(l <= low && high <= r) {
			// complete overlap
			return tree[ind];
		}
		else {
			// partial overlap 
			int mid = low + (high - low) / 2;

			Node left = query(2*ind+1, low, mid, l, r);
			Node right = query(2*ind+2, mid+1, high, l, r);
			
			return merge(left, right);
		}
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	string str;
	cin >> str;

	SegmentTree seg(n, str);

	while(q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		// make the indexes 0 based 

		Node result = seg.query(0, 0, n-1, l, r);

		// add the cyclic edge (first and last combination)
		if(result.last == '0' && result.first == '0') result.cnt00++;
        else if(result.last == '0' && result.first == '1') result.cnt01++;
        else if(result.last == '1' && result.first == '0') result.cnt10++;
        else result.cnt11++;

        // initial config = (a, x, x, b)
		int a = result.cnt00, x = result.cnt01, b = result.cnt11;

		int k = max({
			x,                 // 00 and 11 are not exessive
			(a + x + 1) / 2,   // 00 is exessive
		    (b + x + 1) / 2,   // 11 is exessive 
		    (a + b + x + 2) / 3  // both are exessive 
		});

		int ans = 4 * k - result.len;
		cout << ans << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}