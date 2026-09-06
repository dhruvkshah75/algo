// =============================== precompute dp and knapsack dp =============================================

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

// question link: https://codeforces.com/contest/1633/problem/D

/*
 * Very Important Question => precomputation and then simple knapsack dp with state optimisation 
 * we must precompute the number of operations required to convert 1 to each bi 
 * so precompute this irrespective of all testcases 
 * 
 * simple dp we try out taking all values of x for this 
 * simple dp recurrence that we get 
 * nxt = v + v / x for all values of x 
 * dp[nxt] = min(dp[nxt], dp[v] + 1) => nxt is formed from v so 1 more operation  
 * 
 * now once the cost array is created we know the cost so this now becomes a simple 
 * knapsack style dp => about the ops constraint <= 1e6 
 * some value like 1e3 also takes only about 12 operations so for 1e3 elements 
 * the sum of k will be < 12 * 1e3 => so 1e6 is just misleading 
 */

const int MAXN = 1e3+1;
vector<int> cost;

void precompute() {
	cost.assign(MAXN, 1e9);
	cost[1] = 0;

	for(int v = 1; v < MAXN; v++) {
		// try out all values of x 
	    for(int x = 1; x <= v; x++) {
	        int nxt = v + v / x;

	        if(nxt <= MAXN) {
	            cost[nxt] = min(cost[nxt], cost[v]+1);
	        }
	    }
	}
	// O(N^2) precomputation
}

/*
int f(int ind, int ops_left) {
	if(ind == n) return 0;

	int not_pick = f(ind+1, ops_left);
	int pick = -1e9;
	if(ops_left - cost[b[ind]] >= 0) pick = c[ind] + f(ind+1, ops_left - cost[b[ind]]);

	return max(pick, not_pick);
}
*/

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> b(n), c(n);
	for(int i = 0; i < n; i++) 
		cin >> b[i];

	for(int i = 0; i < n; i++) 
		cin >> c[i];

	// K (second state) = min(k, total_ops in array b)
	int total_cost = 0;
	for(int i = 0; i < n; i++) {
		total_cost += cost[b[i]];
	}

	int K = min(k, total_cost);

	vector<vector<int>> dp(n+1, vector<int>(K+1, 0));
	// base case => index = n for all K dp[n] = 0

	for(int ind = n-1; ind >= 0; ind--) {
		for(int ops_left = 0; ops_left <= K; ops_left++) {
			// 0-1 knapsack cost 

			int not_pick = dp[ind+1][ops_left];
			int pick = -1e9;
			if(ops_left - cost[b[ind]] >= 0) pick = c[ind] + dp[ind+1][ops_left - cost[b[ind]]];

			dp[ind][ops_left] = max(pick, not_pick);
		}
	}

	cout << *max_element(dp[0].begin(), dp[0].end()) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	precompute();

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}