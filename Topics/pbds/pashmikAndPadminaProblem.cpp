
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
 * f(1, i, a[i]) > f(j, n, a[j]) for i < j
 * since i < j so at the jth iteration the set should not contain i in it 
 * using pbds we can get <= f(j) so final ans will be total - f(j)
 * using freq1 and freq2 map causes tle so use coordinate compression 
 * and then precompute f(1,i, a[i]) = pref[i] and f(j, n, a[j]) = suf[j]
 */

void solve(void) {
	int n; cin >> n;

	vector<int> a(n);
	for(int &x: a) cin >> x;

	// Coordinate compress values so frequencies can be tracked with flat vectors
    vector<int> vals = a;
    sort(vals.begin(), vals.end());

    // remove duplicates from the vals array 
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for(int &x : a) x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    
    int m = vals.size();
    vector<int> cnt1(m, 0), cnt2(m, 0);

    // pre[i] = f(1, i, a[i])
    vector<int> pre(n);
    for(int i = 0; i < n; i++) pre[i] = ++cnt1[a[i]];
    
    // suf[j] = f(j, n, a[j])
    vector<int> suf(n);
    for(int j = n-1; j >= 0; j--) suf[j] = ++cnt2[a[j]];
    

    // PBDS ordered multiset stored as pairs: {frequency, original_index}
    ordered_set<pair<int, int>> s;
    int64_t ans = 0;

    for (int j = 0; j < n; j++) {
    	int val = suf[j];
        // {val, INT_MAX} => pre[i] <= suf[j]
        ans += (int64_t)s.size() - s.order_of_key({val, INT_MAX});

        // insert the prefix element in the pbds
        s.insert({pre[j], j});
    }

    cout << ans << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
