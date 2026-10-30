
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
 * greedily decide where to add the element in the front and the back 
 * use pbds data structure to check which option adds less number of inversions 
 * 
 * 1. a[i] -> front => a[i] can form inversion with all the elements < a[i] in the set
 * 2. a[i] -> back => a[i] can form inversions with those elements in set > a[i]
 * add the newer element where adding it creates less number of inversions
 */

void solve(void) {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int &x: a) cin >> x;

	int64_t inv = 0;
	ordered_set<pair<int,int>> s;

	for(int i = 0; i < n; i++) {
		int val = a[i];

		// choice 1: add val in the front
		int front = s.order_of_key({val, -1});
		// choice 2: add val in the end of the dequeue
		int back = s.size() - s.order_of_key({val, INT_MAX});

		inv += min(front, back);
		s.insert({val, i});
	}

	cout << inv << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
} 