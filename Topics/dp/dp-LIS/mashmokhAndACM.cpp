// ====================================== dp =======================================

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

// question link: https://codeforces.com/problemset/problem/414/B

/**
 * solve it in a similar way as counting number of lis ending at each index 
 * use the tabulation version to understand this part 
 * here the array is not given so instead of searching for elements just traverse through multiples of 
 * every number and use the cnt logic for counting number of sequences 
 **/
 
const int MOD = 1e9+7;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> dp(n+1, 1);
	vector<ll> cnt(n+1, 1);
	// dp[i] = length of longest such sequence 

	for(int i = 1; i <= n; i++) {
		// consider the sequence with all multiples of i 
		for(int j = 2*i; j <= n; j += i) {
			if(dp[i] + 1 > dp[j]) {
				// found a better sequence ending in j
				dp[j] = dp[i] + 1;
				cnt[j] = cnt[i];
			}
			else if(dp[i] + 1 == dp[j]) {
				// found a similar length sequence ending in j 
				cnt[j] = (cnt[j] + cnt[i]) % MOD;
			} 
		}
	}

	// sum up all the cnt of such sequences whose length is k => dp = k
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(dp[i] == k) ans = (ans + cnt[i] + k) % MOD;
		else cnt[i] = (cnt[i] + dp[i]) % MOD;
	}


	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

	solve();
}