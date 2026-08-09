// ======================================= bitmask dp ======================================================

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

// question link: https://codeforces.com/problemset/problem/1051/D

/**
 * Binary representation of white and back colourings
 * 0: white 
 * 1: black
 * 
 * use bitmasks for denoting the prev row configurations 
 * if prev_mask = 01 or 10 (white, black) and (black, white)
 * when prev_mask ^ new_mask = 3 => 2 new components get added => k to k+2
 * otherwise the number of components remain the same => k to k
 * 
 * if prev_mask = 00 or 11 (white, white) or (black, black)
 * prev_mask ^ new_mask = 0 => then components remain same => k to k
 * otherwise 1 more component is added => k to k+1
 **/

const int MOD = 998244353;

int n, k;
vector<vector<vector<int>>> dp;

int f(int pos, int comp, int mask) {
	// processed all the columns in the 2*n grid
	if(pos == n) return (comp == k);

	if(dp[pos][comp][mask] != -1) return dp[pos][comp][mask];

	// try all possible combinations of new_mask
	ll ans = 0;
	for(int new_mask = 0; new_mask <= 3; new_mask++) {
		int nxt_comp;
		if(pos == 0) { // deal with the case of new prev col
			nxt_comp = (new_mask == 1 || new_mask == 2) ? 2 : 1;
		}
		else if(mask == 1 || mask == 2) {  // mask = 01 or mask = 10
			nxt_comp = comp + (((mask ^ new_mask) == 3) ? 2 : 0);
		}
		else { // mask = 00 or mask = 11
			nxt_comp = comp + (((mask ^ new_mask) == 0) ? 0 : 1);
		}

		if(nxt_comp <= k) ans = (ans + f(pos+1, nxt_comp, new_mask)) % MOD;
	}

	return dp[pos][comp][mask] = ans;
}

void solve() {
	cin >> n >> k;

	dp.assign(n, vector<vector<int>>(k+1, vector<int>(4, -1)));

	int result = f(0, 0, 0);
	cout << result << endl;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}