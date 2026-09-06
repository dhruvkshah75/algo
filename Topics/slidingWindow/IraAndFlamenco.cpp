// ======================================================== sliding window ==============================================================

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

// question link: https://codeforces.com/problemset/problem/1833/F

/*
 * condition for selecting elements for dances is diff btw levels of every two dancers 
 * is strictly less than m
 * so dont check for every two elements just check for the diff of max and min 
 * max - min < m => sort the array so [l....r] will be valid if a[r] - a[l] < m
 * essentially becomes sliding window 
 * 
 * number of possible configs are freqp[j1] * freq[j2] * .... => total m values 
 * j1, j2 are all the numbers in the window => valid window is the one with a[r]-a[l] < m
 * 
 * cannot directly divide => overflow later so must take modulo 
 * window = window * y ^ -1 (MOD)
 * y ^ -1 = y ^ MOD-2 (MOD) => use binary exponentiation or fast power in O(LogN)
 * Note: x = x / y and then x * y => overflow as x and y are very big 
 * using modular arithmetic we update the x = x / y => x = x * y ^ -1 (MOD)
 * => x = x * y ^ (MOD - 2) (MOD)
 */

const int MOD = 1e9+7;

ll binpow(ll a, ll b) {
	// a ^ b % MOD 
	ll res = 1;

	while(b > 0) {
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}

	return res;
}

ll modInverse(ll x) {
	// calculate x ^ -1 (MOD)
	return binpow(x, MOD - 2);
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	unordered_map<int,int> mp;
	// stores all the freqs of numbers in the window 
	int l = 0;
	ll window = 1;
	ll ans = 0;

	for(int r = 0; r < n; r++) {
		// expand the window on right 
		if(mp[arr[r]] == 0) { 
			mp[arr[r]]++;
		}
		else {
			window = window * modInverse(mp[arr[r]]) % MOD;
			mp[arr[r]]++;
			window = window * 1LL * mp[arr[r]] % MOD;
		}

		// shrink if the window becomes invalid 
		while(arr[r] - arr[l] >= m) {
			// remove arr[l] from the window 
			if(mp[arr[l]] == 1) {
				mp.erase(arr[l]);
			}
			else {
				window = window * modInverse(mp[arr[l]]) % MOD;
				mp[arr[l]]--;
				window = window * 1LL * mp[arr[l]] % MOD;
			} 
			l++;
		}

		/* only add cnt to the window iff arr[r] is the last occurrence => window can expand on the right 
		   with m distinct values itself => so last_occurence prevents double counting 
           considering the window to have only m unique values => direct mul (window) will work */

		bool lastOcc = (r == n - 1 || arr[r] != arr[r+1]);
		if(mp.size() == m && lastOcc) {
			ans = (ans + window) % MOD;
		}
	}

	cout << ans % MOD << endl;
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