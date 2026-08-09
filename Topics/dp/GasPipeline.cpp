// ====================================== dp ================================================

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

const ll INF = 1e18;

// question link: https://codeforces.com/problemset/problem/1207/C

/**
 * try out all possible paths => for the current index we need to know what is the prev height
 * if s[ind] = 1 => we can only move with height = 2 
 * and if s[ind] = 0 => then there are multiple cases in this case 
 * we could move onto from height 2 to 1 and from height 1 to 2 
 **/

vector<vector<ll>> dp;

ll f(int ind, int height, string &s, ll a, ll b, ll n) {
	// base case: all lines of gas pipeline built
	if(ind == n) {
		return(height == 1) ? 0 : INF;
	}

	if(dp[ind][height] != -1) return dp[ind][height];

	int curr = s[ind];
	ll ans = INF;

	if(curr == '1') {
		// only moving at height = 2 is allowed 
		if(height == 2) ans = min(ans, a + 2*b + f(ind+1, 2, s, a, b, n)); 
	}
	else {
		// this is not a crossroad curr = 0
		if(height == 1) {
			// stay at height = 1
			ans = min(ans, a + b + f(ind+1, 1, s, a, b, n));

			// go from from height = 1 to 2
			ans = min(ans, 2*a + 2*b + f(ind+1, 2, s, a, b, n));
		}
		else {
			// stay height = 2
			ans = min(ans, a + 2*b + f(ind+1, 2, s, a, b, n));

			// go from height 2 to 1 
			ans = min(ans, 2*a + b + f(ind+1, 1, s, a, b, n));
		}
	}

	return dp[ind][height] = ans;
}

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;

	string s;
	cin >> s;

	dp.assign(n+1, vector<ll>(3, -1));

	// start from a pillar of 1 unit and starting from pos = 0
	cout << b + f(0, 1, s, a, b, n) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}