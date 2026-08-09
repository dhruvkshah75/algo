// ========================================== rerooting dp =================================================

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

// question link: https://codeforces.com/problemset/problem/219/D

/**
 * Re-Rooting dp 
 * How to recognize if question involves using rerooting dp
 * If we fix one node as the root or as a centre then we can solve it for node 
 * using one DFS pass => O(V + E) And then we are asked to do this for every other node 
 * 
 * Here the question is based on the same logic 
 * Fix the node = 1 as the root and then calculate the number of edge reversals needed 
 * to reach every node from root 1 
 * Pretty easy to do this => mark the current dir with edge wt = 0 
 * and the reverse with edge wt = 1 => whenever we walk on edge with wt = 1 => we are using 
 * a reverse edge => so this edge needs to be reversed 
 * 
 * After that how to get the ans for other nodes 
 * so assume u is the capital for which we know the ans, now we figure out the ans for all its nbg 
 * 
 * example u -> B and u -> v -> A => cases are => edge is u -> v or u <- v
 * when we make v the capital then only one egde needs to be reversed  
 * 
 * dp[v] = dp[u] +- 1 (based on the two cases)
 **/

vector<vector<pii>> adj;
vector<int> dp;

int dfs1(int node, int parent) {
	int rev = 0;
	for(auto [nbg, dir]: adj[node]) {
		if(nbg == parent) continue;
		// if dir = 1 => we are walking on a reverse edge 
		rev += dir + dfs1(nbg, node);
	}
	return rev;
}

void dfs2(int node, int parent) {
	// calculate the dp values for nbg of node (whose dp is calculated)
	for(auto [nbg, dir]: adj[node]) {
		if(nbg == parent) continue;
		
		if(dir == 1) {
			// original edge: node <- nbg 
			// correct when nbg is capital and incorrect when capital is node
			dp[nbg] = dp[node] - 1;
		}
		else {
			// original edge: node -> nbg
			// correct when node is capital and incorrect when nbg is capital
			dp[nbg] = dp[node] + 1;
		}
		dfs2(nbg, node);
	}
}


void solve() {
	int n;
	cin >> n;

	adj.resize(n+1);
	dp.assign(n+1, 0);

	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		// edge x -> y => given direction is 0 and reverse direction is 1 
		adj[x].push_back({y, 0});
		adj[y].push_back({x, 1});
	}

	// dp[i] = edge reversals to make i as the capital
	dp[1] = dfs1(1, -1);

	// calculate the answers for all other nodes using rerooting dp
	dfs2(1, -1);

	// optimal capital is the one wiith min edge reversals (node = 0 is not any node)
	int min_rev = *min_element(dp.begin()+1, dp.end());
	cout << min_rev << endl;

	for(int i = 1; i <= n; i++)
		if(dp[i] == min_rev) cout << i << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}