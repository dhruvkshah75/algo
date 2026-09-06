// =================================== topological sorting ==================================

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

// question link: https://codeforces.com/problemset/problem/1931/F

/*
 * each screenshot shared by some user will have some ordering 
 * where this ordering has the users id at the top always 
 * so skip the first entry and from other entries form a graph 
 * 
 * if the graph is a DAG with a valid topological sorting then 
 * the screenshots shared have some valid ordering 
 */

void solve() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> v(k, vector<int>(n));
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++) 
			cin >> v[i][j];
	}

	// if only person then no ordering needed 
	if(n == 1) {
		yes;
		return;
	}

	// we must form the edges => avoid duplicate edges so use set 
	set<pair<int,int>> st;
	for(int i = 0; i < k; i++) {
		for(int j = 1; j + 1 < n; j++) {
			// edge j -> j+1
			st.insert({v[i][j], v[i][j+1]}); 
		}
	}

	vector<vector<int>> adj(n+1);
	vector<int> indegree(n+1, 0);

	for(auto [node1, node2]: st) {
		adj[node1].push_back(node2);
		indegree[node2]++;
	}

	// Kahns Algorithm for checking valid topological sorting 
	queue<int> q;
	int processed = 0;

	for(int i = 1; i <= n; i++) {
		if(indegree[i] == 0) {
			q.push(i);
			processed++;
		}
	}

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(int child: adj[node]) {
			indegree[child]--;

			if(indegree[child] == 0) {
				q.push(child);
				processed++;
			}
		}
	}

	if(processed == n) {
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