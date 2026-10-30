
#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
 * sequence is 1, c^1, c^2, ... c^n-1
 * sort the given array and then we must choose to bring each element to c^i
 * initially the best ans that we can have is changing everything to 1 
 * then try using c 
 * */

void solve(void) {
	int n; cin >> n;

	vector<int> A(n);
	int64_t best = 0;

	for(int &a: A) {
		cin >> a;
		best += a-1;
	}

	sort(A.begin(), A.end());

	// best is moves to make every element to 1 

	for(int c = 2; ; c++) {
		int64_t cost = 0, pow_c = 1;
		int64_t limit = A[n-1] + best;

		for(int i = 0; i < n; i++) {
			cost += llabs(A[i] - pow_c);
			pow_c *= c;

			if(i+1 < n && pow_c > limit) goto result;
		}

		best = min(best, cost);
	}

	result:
	cout << best << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}