// ============================================= bitmask dp ============================================================

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

// question link: https://codeforces.com/problemset/problem/1829/H

/*
 * pretty much standard pick / not pick dp 
 * and store the AND of elements chosen in the mask 
 * this will work as this only takes O(64) space 
 * 
 * but we cannot define space of N * 64 => Memory limit 
 * so use space optimised tabulation to make it work
 */
	
const int MOD = 1e9+7;

/*
int f(int ind, int mask, vector<int> &arr, int k) {
	// base case: all number exhausted 
	if(ind == (int)arr.size()) return k == setbits(mask);

	// 0-1 pick / not pick knapsack dp 
	ll res = 0;
	res = (res + f(ind+1, mask, arr, k)) % MOD;
	res = (res + f(ind+1, mask & arr[ind], arr, k)) % MOD;
	return res;
}
*/

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	// space optimised tabulation of bitmask dp 
	vector<int> ahead(64, 0), curr(64, 0);

	// base case: all masks with setbits == k 
	for(int mask = 0; mask < 64; mask++) {
		if(setbits(mask) == k) ahead[mask] = 1;
	}

	for(int ind = n-1; ind >= 0; ind--) {
		for(int mask = 0; mask < 64; mask++) {
			// apply simple 0-1 knasapck 
			curr[mask] = (ahead[mask] + ahead[mask & arr[ind]]) % MOD;
		}
		ahead = curr;
	}
	// O(64 * N)

	// dp starts with mask = all set bits = 63 
	int result = ahead[63];

	// note: we start with 63 so if k = 6 then our ans includes empty subsequence
	if(k == 6) {
		result--;
		if(result < 0) result += MOD;
	}

	cout << result << endl;
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