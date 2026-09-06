// ========================================= binary search ==================================================

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

// question link: https://codeforces.com/problemset/problem/1843/E

/**
 * Binary search on the number of queries applied since the condition is monotonic.
 * For a given mid, apply the first mid updates and mark those positions as 1.
 * Build a prefix sum over this 0/1 array to count ones in any segment in O(1).
 * For every given [l,r], get ones using pref[r] - pref[l-1].
 * The segment is beautiful if ones > zeros, i.e. 2 * ones > (r-l+1).
 * 
 * predicate function returns FFFTTTTT return the first occurence of True
 */

bool check(int x, int n, vector<pair<int,int>> &segments, vector<int> &queries) {
	// can we get at least 1 segment beautiful with using first x queries 

	vector<int> prefix(n+1, 0);
	for(int i = 0; i < x; i++) {
		int idx = queries[i];
		prefix[idx] = 1;
	}

	// take the prefix sum of the array 
	for(int i = 1; i <= n; i++) prefix[i] += prefix[i-1];
	
	for(auto [l, r]: segments) {
		int ones = prefix[r] - prefix[l-1];
		// ones > zeros 
		if(2 * ones > r-l+1) return true;
	}

	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> segments;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		segments.push_back({l, r});
	}

	int q;
	cin >> q;

	vector<int> queries(q);
	for(int i = 0; i < q; i++) {
		cin >> queries[i];
		// index of the change that we make 
	}

	int low = 0, high = q;
	int ans = -1;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(check(mid, n, segments, queries)) {
			high = mid-1;
			ans = mid;
		}
		else low = mid+1;
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