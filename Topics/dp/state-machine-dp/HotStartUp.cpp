// ==================================== multi state dp with state optimisation ========================================

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

// question link: https://codeforces.com/problemset/problem/1799/D1

/**
 * Here the obvious states or brute force dp recurrence is (ind, cpu1, cpu2)
 * but this becomes O(N^3) => cannot work so we need to reduce 1 state 
 * 
 * Note that we dont care which cpu does which one 
 * so keep only one state other which keeps the track of which task was done previously 
 * as one of the prev tasks will always be ind-1 and the other one is the one that we need 
 * to keep a track of 
 * 
 * recurrence => f(ind, other)
 * */

int n, k;
vector<int> hot, cold, arr;
vector<vector<ll>> dp;

ll f(int ind, int other) {
	// base case: all tasks completed 
	if(ind > n) return 0;

	if(dp[ind][other] != -1) return dp[ind][other];

	// now try out all possible cases using cpu1 and cpu2 
	ll res = 1e18;
	int cpu1 = arr[ind-1], cpu2 = other;

	// try doing the ind th task using cpu1 
	ll cost1 = (arr[ind] == cpu1) ? hot[arr[ind]] : cold[arr[ind]];
	res = min(res, cost1 + f(ind+1, cpu2));

	// ind th task using the cpu2 
	ll cost2 = (arr[ind] == cpu2) ? hot[arr[ind]] : cold[arr[ind]];
	res = min(res, cost2 + f(ind+1, cpu1));

	return dp[ind][other] = res;
}

void solve() {
	cin >> n >> k;

	arr.assign(n+1, 0);
	for(int i = 1; i <= n; i++) cin >> arr[i];

	cold.assign(k+1, 0);
	for(int i = 1; i <= k; i++) cin >> cold[i];

	// hot[i] <= cold[i]
	hot.assign(k+1, 0);
	for(int i = 1; i <= k; i++) cin >> hot[i];

	dp.assign(n+1, vector<ll>(k+1, -1));
	
	// 0 is the case when there are no previously done tasks 
	ll ans = f(1, 0);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)
		solve();
}