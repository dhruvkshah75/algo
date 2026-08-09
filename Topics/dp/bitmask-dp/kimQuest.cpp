// ====================================== bitmask + 0-1 knapsack style dp ===========================================

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

// question link: https://codeforces.com/problemset/problem/1912/K

const int MAXN = 2e5+1;
int dp[MAXN][4][4];
// dp[pos][mask][len]

const int MOD = 998244353;

int f(int pos, int mask, int len, vector<int> &arr) {
	// base case: all elements chosen 
	if(pos == arr.size()) return (len == 3);

	if(dp[pos][mask][len] != -1) return dp[pos][mask][len];

	ll res = 0;
	res = (res + f(pos+1, mask, len, arr)) % MOD;

	int par = arr[pos] & 1;
	// par = 1 => element is odd otherwise even

	if(len < 2 || (setbits(mask) + par) % 2 == 0) {
		// can take the element as this three elements form a consecutive seq 
		int nxt_len = min(3, len + 1);

		// new_mask = (0th_bit of mask)(par)
		int new_mask = ((mask & 1) << 1) | par;
		res = (res + f(pos+1, new_mask, nxt_len, arr)) % MOD;
	} 

	return dp[pos][mask][len] = res;
}

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	int ans = f(0, 0, 0, arr);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}