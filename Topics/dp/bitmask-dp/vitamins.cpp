// ================================= bitmask dp ======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/1042/B

/**
 * use bitmask dp where we use mask state to denote if all 3 vitamins are present 
 * vitamins C B A 
 * mask     1 1 1
 * the dp part is simple 0-1 knapsack like where we either take the current juice or not 
 * we can add a simple pruning only if the current juice actually adds to the result or is a waste 
 * eg mask = 0 1 1 and the current juice provides vitamins A and B => dont take as A and B are already set
 **/

const int MAXN = 1e3+10;
int dp[MAXN][8];

int f(int ind, int mask, vector<int> &cost, vector<string> &juice) {
	// all vitamins found => mask = 1 1 1 
	if(mask == 7) return 0;
	if(ind == cost.size()) return 1e9;

	if(dp[ind][mask] != -1) return dp[ind][mask];

	// 0-1 => pick(with pruning) or not pick
	int not_pick = f(ind+1, mask, cost, juice);

	int freq[3] = {0};
	for(char c: juice[ind]) freq[c-'A']++;

	int new_mask = mask;
	for(int j = 0; j <= 2; j++) {
		if(freq[j] >= 1) new_mask = new_mask | (1 << j);
	}

	int pick = cost[ind] + f(ind+1, new_mask, cost, juice);

	return dp[ind][mask] = min(pick, not_pick);
}

void solve() {
	int n;
	cin >> n;

	vector<int> cost(n);
	vector<string> juice(n);

	for(int i = 0; i < n; i++)
		cin >> cost[i] >> juice[i];

	memset(dp, -1, sizeof(dp));

	int res = f(0, 0, cost, juice);
	if(res >= 1e9) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}