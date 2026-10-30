
#include<bits/stdc++.h>
using namespace std;

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
 * since we can only add one element in the sequence we will add it a element in the middle of it
 * either the ans will be the second max gap 
 * now we must get the split and for that we need a sum of x = f + d 
 * to get the best split we must get x = (L + R) / 2 where [L..R] is max gap 
 * so using lower bound get the value of x => check the up and down value 
 **/

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n), f(m), d(k);

	for(int &x: a) cin >> x;
	for(int &x: f) cin >> x;
	for(int &x: d) cin >> x;

	sort(d.begin(), d.end());

	int ind = 0;
	int64_t mx = 0, second = 0;

	for(int i = 1; i < n; i++) {
		int64_t gap = a[i] - a[i-1];

		if(gap > mx) {
			second = mx;
			mx = gap;
			ind = i;  // ind is the max gap index => a[ind] - a[ind-1]
		}
		else if(gap > second) second = gap;
	} 

	if(mx == second) {
		// two gaps of the same max size so no point in adding anything 
		cout << mx << endl;
		return;
	}

	int64_t L = a[ind-1], R = a[ind];
	int64_t mid = (L + R) / 2, best = R - L;
	// we want x = d + f be as close as (L + R) / 2

	for(int i = 0; i < m; i++) {
		int64_t T = mid - f[i];
		auto it = lower_bound(d.begin(), d.end(), T);
		// consider the element at it and it-1

		if(it != d.end()) {
			int64_t x = f[i] + *it;  // f + d
			if(x >= L && x <= R) best = min(best, max(R-x, x-L));
		}

		if(it != d.begin()) {
			int64_t x = f[i] + *(it-1);
			if(x >= L && x <= R) best = min(best, max(R-x, x-L));
		}
	}

	cout << max(second, best) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}