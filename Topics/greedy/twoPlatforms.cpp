
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
 * here if we sort the coordinates on the basis of their x coordinates 
 * then can we consider sliding windows of size [x....x+k] and keep the y coordinate of 
 * one platform as max(y in this window) so all these points will get saved 
 * now we must get two such max non overlapping max windows 
 * 
 * dp[i] = points saved by this window starting from ith x coordinate
 * and then store the mx[i] = max(dp[i], dp[i+1],..... dp[n-1])
 * in this way using mx we can deal with two non overlapping platforms  
 * 
 * */

void solve() {
	int n, k;
	cin >> n >> k;

	vector<pii> points(n);

	for(auto &[x, y]: points) cin >> x;
	
	for(auto &[x, y]: points) cin >> y;

	// sort the coordinates on the basis of their x coordinates
	sort(points.begin(), points.end());

	vector<int> dp(n);
	// dp[i] = points saved by platform starting on the ith x coord

	auto cmp = [&](int val, const pii &ele) {
		return val < ele.first;
	};

	for(int i = 0; i < n; i++) {
		int nxt = points[i].first + k;
		auto it = upper_bound(points.begin(), points.end(), nxt, cmp);
		int ind = distance(points.begin(), it);

		dp[i] = ind-i;
		// platform starting at this coordinate will save dp[i] points 
	}

	vector<int> mx(n+1, 0);
	// mx[i] = max(dp[i], dp[i+1],....,dp[n-1])

	for(int i = n-1; i >= 0; i--) {
		mx[i] = max(dp[i], mx[i+1]);
	}

	int ans = 0;

	for(int i = 0; i < n; i++) {
		int nxt = points[i].first + k;
		auto it = upper_bound(points.begin(), points.end(), nxt, cmp);
		int ind = distance(points.begin(), it);

		ans = max(ans, dp[i] + mx[ind]);
	}

	cout << ans << endl;
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