
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

/*
 * for some l <= r we want a[l] + a[l+1] + ... + a[r] < t
 * this becomes prefix[r] - prefix[l-1] < t
 * on rearranging the equation we get => -prefix[l-1] < t - prefix[r]
 * t is a known constant so this becomes a simple inequality which can be handled by pbds
 */

void solve(void) {
	int n;
	int64_t t;
	cin >> n >> t;

	vector<int64_t> prefix(n+1);
	prefix[0] = 0;

	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		prefix[i] = prefix[i-1] + x;
	}

	ordered_set<pair<int64_t,int>> s;
	// store -prefix values and can have duplicates 
	s.insert({0, 0});

	int64_t ans = 0;

	for(int i = 1; i <= n; i++) {
		int64_t val = t - prefix[i];

		// {val, -1} gives all prefix values < val
		ans += s.order_of_key({val, -1});
		s.insert({-prefix[i], i});
	}

	cout << ans << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}