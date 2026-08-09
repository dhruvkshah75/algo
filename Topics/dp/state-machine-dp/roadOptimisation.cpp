// =================================== multi state dp ===============================================

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

// question link: https://codeforces.com/problemset/problem/1625/C

/**
 * states needed for this question will be position of sign 
 * and the skips left 
 * 
 * for each recursive call we try out to skip all signs within our limit 
 * and try to reach the end => if final pos reached = n then we reached the end = l
 * 
 * add a small pruning in the logic => when new_limit > curr_limit dont skip 
 * we have better and faster speed to reach the end 
 * to deal with the last limit add the dummy 
 **/

int n, l, k;
const int N = 5e2+10; 
ll dp[N][N];

ll f(int pos, int skips_left, vector<int> &loc, vector<int> &speed) {
	// base case: reached the end or destination 
	if(pos == n) return 0;

	if(dp[pos][skips_left] != -1) return dp[pos][skips_left];

	ll res = 1e18;
	for(int nxt = pos+1; nxt <= n; nxt++) {
		// if we go to the nxt position => skips done are nxt-pos-1
		int skips = nxt-pos-1;

		if(skips > skips_left) break;

		ll cost = 1LL * (loc[nxt] - loc[pos]) * speed[pos];
		res = min(res, cost + f(nxt, skips_left - skips, loc, speed));
	}

	return dp[pos][skips_left] = res;
}

void solve() {
	cin >> n >> l >> k;

	vector<int> loc(n+1), speed(n+1);
	for(int i = 0; i < n; i++) cin >> loc[i];

	for(int i = 0; i < n; i++) cin >> speed[i];
	
	// dummy destination is added as dealing with the end case is difficult 
	loc[n] = l;
	speed[n] = 0;

	memset(dp, -1, sizeof(dp));
	ll result = f(0, k, loc, speed);

	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}