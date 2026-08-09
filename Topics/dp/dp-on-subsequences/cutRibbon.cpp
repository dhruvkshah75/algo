// =========================== unbounded knapsack dp ===============================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), 
#define print(x) cerr << " " << x << " ";
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)

// question link: https://codeforces.com/problemset/problem/189/A

int n;
vector<int> v(3);
vector<vector<int>> dp;

int f(int pos, int w) {
	// base case: w = 0 => ribbon formed 
	if(w == 0) return 0;
	if(pos == 3) return -1e9;

	if(dp[pos][w] != -1) return dp[pos][w];

	int res = -1e9;
	res = max(res, f(pos+1, w));
	if(w - v[pos] >= 0) res = max(res, 1 + f(pos, w-v[pos]));

	return dp[pos][w] = res;
}


void solve() {
	cin >> n >> v[0] >> v[1] >> v[2];
	
	dp.assign(3, vector<int>(n+1, -1));

	int ans = f(0, n);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}