// =============================================== bitmask dp ====================================================

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

// question link: https://codeforces.com/problemset/problem/580/D

int n, m, k;
vector<int> a;
vector<vector<int>> bonus;
vector<vector<ll>> dp;

ll f(int mask, int prev) {
	// base case: eaten m dishes so cannot eat more 
	if(setbits(mask) == m) return 0;

	if(dp[mask][prev] != -1) return dp[mask][prev];

	// try eating all the dishes that are not eaten next 
	ll ans = 0;

	for(int i = 1; i <= n; i++) {
		int bit = mask & (1 << i);
		// can only eat if the dish is not eaten (bit is not set)
		if(!bit) {
			int new_mask = mask | (1 << i);
			ans = max(ans, bonus[prev][i] * 1LL + a[i] + f(new_mask, i));
		}
	}

	return dp[mask][prev] = ans;
}

void solve() {
	cin >> n >> m >> k;

	a.resize(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];

	bonus.assign(n+1, vector<int>(n+1, 0));
	for(int i = 0; i < k; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		bonus[x][y] = c;
	}

	dp.assign(1 << (n+1), vector<ll>(n+1, -1));
	// start with 0 eaten dishes and prev = null = 0
	ll result = f(0, 0);

	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}