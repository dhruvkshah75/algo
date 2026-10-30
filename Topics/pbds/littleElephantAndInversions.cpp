
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
    cerr << "[";
    for(const auto &x: v) {
        print(x); cerr << " ";
    }
    cerr << "]" << endl;
}

/**
 * we are supposed to count the number of subarrays with <= k inversions outside the subarray
 * use ordered_set to get the inversions in it and we find the number of such subarrays
 * 
 * inversions => 1 ≤ i < j ≤ |b| and bi > bj
 * use two ordered_set to store the elements in the prefix and suffix 
 * and then for all l we expand the window from r such that the outside block has <= k inversions
 * [1..l] [r...n] <= k inversions then [r+1..n], [r+2,...n] ... for fixed val of l  
 * */

void solve(void) {
	int n;
	int64_t k;
	cin >> n >> k;

	vector<int> a(n);
	for(int &x: a) cin >> x;

	// inv = number of inversions in the subarray [l..r]
	int64_t inv = 0;

	ordered_set<pair<int,int>> P, S;
	// p holds prefix elements [1..l] and s stores elements in [r..n]

	// start by filling the suffix set with all elements 
	for(int i = 0; i < n; i++) {
		int val = a[i];
		inv += S.size() - S.order_of_key({val, INT_MAX});
		S.insert({val, i});
	}

	int64_t ans = 0;
	int r = 0;

	for(int l = 0; l < n; l++) {
		if(l == r) {
			// a[l] is in suffix move the element into the prefix
			S.erase({a[l], l});
			P.insert({a[l], l});
			r++;
		}
		else {
			// expand the window from the left l and a[l] is not in the suffix so add in prefix
			// prefix ele > a[l] and a[l] > suffix ele
			inv += (P.size() - P.order_of_key({a[l], INT_MAX})) + S.order_of_key({a[l], -1});
			P.insert({a[l], l});
		}

		// delete a[r] from the start of suffix until b <= k inversions
		while(inv > k && r < n) {
			int val = a[r];
			S.erase({val, r});
			// remove all ele in prefix > val and all ele in suffix < val
			inv -= S.order_of_key({val, -1}) + (P.size() - P.order_of_key({val, INT_MAX}));
			r++;
		}

		ans += n-r;
	}

	cout << ans << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}