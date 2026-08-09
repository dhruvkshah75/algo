// =================================== linear dp + precomputing ===================================

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

// question link: https://codeforces.com/problemset/problem/1741/E

/**
 * Simple two choice dp 
 * 1. consider the current element at arr[ind] the length of segment on the right 
 * 2. tricky one cannot travel all the elements => O(N) work per recursive call 
 * So we must precompute all the nxt positions of jumps of the second kind 
 * 
 * 2nd type of jump involves the right end being the length so in one pass of the array 
 * we could easily get the jumps array to make the next jump
 * */

int n;
vector<int> arr, dp;
vector<vector<int>> jumps;

bool f(int ind) {
	// base case: jump is outside the arr OR jump reaches the end of arr => valid jump
	if(ind >= n) return (ind == n); 

	if(dp[ind] != -1) return dp[ind];

	bool res = false;
	// try both jumps 
	res = res || f(ind+arr[ind]+1);

	for(int nxt: jumps[ind]) {
		res = res || f(nxt);
	}

	return dp[ind] = res;
}

void solve() {
	cin >> n;

	arr.assign(n, 0);
	jumps.assign(n, {});

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		// considering the arr[i] as the segment length (segment on the left)
		if(i - arr[i] >= 0) jumps[i - arr[i]].push_back(i+1);
	}

	dp.assign(n, -1);

	if(f(0)) {
		yes;
	}
	else {
		no;
	}
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