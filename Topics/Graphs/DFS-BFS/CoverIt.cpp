// ========================================== bfs =============================================

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

// question link: https://codeforces.com/problemset/problem/1176/E

/**
 * start the bfs traversal from the node = 1 and divide all the nodes into two sets 
 * put the first node in group 1 and all its neighbours at depth = 1 or dist = 1
 * into group 2 and so on 
 * and then after this assignment select the group with less number of nodes 
 **/

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n+1);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	vector<int> grp(n+1, -1);

	// define the groups = 1 and groups 2
	q.push(1);
	grp[1] = 1;

	while(!q.empty()) {
		int node = q.front();
		q.pop();
		int set = grp[node];

		for(int child: adj[node]) {
			if(grp[child] == -1) {
				q.push(child);
				grp[child] = 1 - set;
			}
		}
	}

	int cnt0 = 0, cnt1 = 0;
	int mn_grp = -1;
	for(int i = 1; i <= n; i++) {
		(grp[i] == 0) ? cnt0++ : cnt1++;
	}

	if(cnt0 >= cnt1) mn_grp = 1;
	else mn_grp = 0;

	cout << min(cnt0, cnt1) << endl;
	// now print all the nodes with mn_grp 
	for(int i = 1; i <= n; i++) {
		if(grp[i] == mn_grp) {
			cout << i << " ";
		}
	}
	cout << endl;
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