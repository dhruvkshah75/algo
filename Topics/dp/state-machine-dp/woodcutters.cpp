// =========================================== multi state dp ========================================================

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

// question link: https://codeforces.com/problemset/problem/545/C

/**
 * recurrence = f(ind, prev)
 * 
 * prev = 0 => previous tree at ind-1 did not fall on the right 
 * prev = 1 => ind-1 tree fell on the right so allowed space is less 
 * 
 * when prev = 0 => we can make the current tree fall on either sides or not fall at all 
 * the tree can fall on the left or right only if it does not cross the other tree  
 * and if the prev tree falls on the right then making the current tree fall on the left 
 * has less space 
 **/

int n;
vector<vector<int>> trees;
vector<vector<int>> dp;

int f(int ind, int prev) {
	// base case: all trees processed 
	if(ind == n) return 0;

	if(dp[ind][prev] != -1) return dp[ind][prev];

	// skip this tree, fell the tree to either left or right 
	int res = f(ind+1, 0);

	if(ind == n-1 || trees[ind][0] + trees[ind][1] < trees[ind+1][0]) {
		res = max(res, 1 + f(ind+1, 1));
	}

	// make the ind th tree fall on the left
	if((ind == 0) || (prev && trees[ind-1][0] + trees[ind-1][1] < trees[ind][0] - trees[ind][1]) || 
		(!prev && trees[ind-1][0] < trees[ind][0] - trees[ind][1])) {
		res = max(res, 1 + f(ind+1, 0));
	}

	return dp[ind][prev] = res;
}

void solve() {
	cin >> n;

	trees.resize(n, vector<int>(2));
	for(int i = 0; i < n; i++) 
		cin >> trees[i][0] >> trees[i][1];

	dp.assign(n, vector<int>(2, -1));

	int ans = f(0, 0);
	cout << ans << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}