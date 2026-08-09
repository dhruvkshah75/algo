// ======================================== multi state dp ==============================================

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

// question link: https://codeforces.com/problemset/problem/1418/C

/*
 * 0 = friends session
 * 1 = my session 
 * turn = 0, 1
 * 
 * states needed for recurrence => f(pos, turn)
 * f = number of skip points needed to kill the boses of both types 
 */

int n;
vector<int> arr;
vector<vector<int>> dp;

int f(int pos, int turn) {
	// base case when all boses are killed 
	if(pos >= n) return 0;

	if(dp[pos][turn] != -1) return dp[pos][turn];

	int res = 1e9;
	if(turn == 1) {
		// either kill boss at pos or kill at pos, pos+1
		res = min(f(pos+1, 0), f(pos+2, 0));
	}
	else {
		// kill the boss at pos
		int skip_points = arr[pos];
		res = min(res, skip_points + f(pos+1, 1));
		// kill boses at indices pos, pos+1
		skip_points += arr[pos+1];
		res = min(res, skip_points + f(pos+2, 1));
	}

	return dp[pos][turn] = res;
}

void solve() {
	cin >> n;

	arr.assign(n+10, 0);
	for(int i = 0; i < n; i++) cin >> arr[i];

	dp.assign(n, vector<int>(2, -1));
	
	// start with the friends session => turn = 0
	int result = f(0, 0);
	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) 
		solve();
}