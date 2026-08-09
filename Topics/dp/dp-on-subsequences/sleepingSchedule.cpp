// ========================================= dp on subsequences ==================================================

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

// question link: https://codeforces.com/problemset/problem/1324/E

/**
 * Question is based on two choices of sleeping 
 * either sleep at a[i]-1 or a[i] th hour => sleeping involves sleeping for h hours (whole day)
 * so timer or current time resets back to same time he slept for 
 * he is has to sleep for n times => for every a[i]
 * 
 * simply using recursion try out all sleeping combinations and then add the good sleeps 
 * i.e. the ones when the sleep is in the time [l,...,r]
 * 
 * recurrence = f(ind, curr_time) 
 **/
	
int n, h, l, r;
vector<int> a;
vector<vector<int>> dp;

int f(int ind, int curr_time) {
	// base case: all sleeps dones => ind = n
	if(ind == n) return 0;

	if(dp[ind][curr_time] != -1) return dp[ind][curr_time];

	// try out both possible sleeping options of a[i]-1 or a[i]
	int sleep_time1 = (curr_time + a[ind]) % h;
	int good1 = (sleep_time1 >= l && sleep_time1 <= r);
	int op1 = good1 + f(ind+1, sleep_time1);

	int sleep_time2 = (curr_time + a[ind] - 1) % h;
	int good2 = (sleep_time2 >= l && sleep_time2 <= r);
	int op2 = good2 + f(ind+1, sleep_time2);

	return dp[ind][curr_time] = max(op1, op2);
}

void solve() {
	cin >> n >> h >> l >> r;

	a.assign(n, 0);
	for(int i = 0; i < n; i++) cin >> a[i];

	dp.assign(n, vector<int>(h+1, -1));

	int res = f(0, 0);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}

