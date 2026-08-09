// ============================================== dp ============================================

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

// question link: https://codeforces.com/problemset/problem/1350/B

vector<int> arr, dp;

int f(int ind, int n) {
	// base case: index out of bounds
	if(ind > n) return 0;

	if(dp[ind] != -1) return dp[ind];

	int curr = arr[ind];
	int maxi = 1;

	for(int j = 2 * ind; j <= n; j += ind) {
		if(curr < arr[j]) {
			maxi = max(maxi, 1 + f(j, n));
		}
	}
	// O(LogN)

	return dp[ind] = maxi;
}

void solve() {
	int n;
	cin >> n;

	// arr => 1 based indexing 
	arr.assign(n+1, 0);
	for(int i = 1; i <= n; i++) cin >> arr[i];

	dp.assign(n+1, -1);
	// dp[i] = number of models that can be taken in the suffix [i...n]
	
	// dont start the calls from the ind = 1 as all indices are multiples of 1 (skip 1)
	int res = 1;

	for(int ind = 2; ind <= n; ind++) {
		if(arr[1] < arr[ind]) { // connect index 1 to the sequence starting from ind 
			res = max(res, 1 + f(ind, n));
		}
		else { // start the sequence fresh from this index ind
			res = max(res, f(ind, n));
		}
	}

	cout << res << endl;
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