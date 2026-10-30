
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
 * for some i and j => i < j we want ai + aj > bi + bj
 * we can rearrange the equation to get something like ai - bi > -(aj - bj)
 * can use pbds to answer this query in LogN time 
 * add elements on the go in the set as the set will contain only those elements 
 * which have already appeared 
 */

void solve(void) {
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;

	vector<int> d(n);
	// d[i] = a[i] - b[i]

	for(int i = 0; i < n; i++) d[i] = a[i] - b[i];

	ordered_set<pair<int,int>> s;
	// use pair as the set can contain duplicates

	int64_t ans = 0;

	for(int j = 0; j < n; j++) {
		int val = -d[j];
		// s.order_of_key gives all elements <= val 
		ans += s.size() - s.order_of_key({val, INT_MAX});
		s.insert({d[j], j});
	}

	cout << ans << endl;
}	

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}