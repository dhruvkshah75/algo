// ================================ binary search + combinatorics ================================================

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

// question link: https://codeforces.com/contest/689/problem/C

/**
 * each configuarion of the type (x, x*k, x*k^2, x*k^3)
 * and condition for valid is all values <= n, this results in n >= x * k^3
 * from this we get x <= n / k^3 => x must be at least 1
 * so run the loop for k = 1 to k <= cuberoot(n)
 * 
 * Approach:
 * 1. Binary search on the answer n => keep the search space 1..1e18
 * 2. predicate function returns true if total number of configs >= m
 * predicate returns ...FFFFFTTTT... => get the first occurrence of T
 * but a check is needed as we want exactly m ways so for this value of 
 * n check the number of configs => it should be exactly = m otherwise return -1
 **/

ll countTotalConfigs(ll n, ll m) {
	// n = the maximum amount of chocolates that thieves' bags can carry
	ll ways = 0;
	for(ll k = 2; k * k * k <= n; k++)  {
		ways += n / (k * k * k);
		// stop counting more than m ways 
		if(ways > m) break;
	}
	return ways;
}

void solve() {
	ll m;
	cin >> m;

	ll low = 1, high = 1e18;
	ll ans = -1;
	// binary search with search space 1...1e18
	while(low <= high) {
		ll mid = low + (high - low) / 2;
		if(countTotalConfigs(mid, m) >= m) {
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}

	// n = ans gives first occurrence of True => for ans total configs = m
	if(countTotalConfigs(ans, m) == m) cout << ans << endl;
	else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	solve();
}