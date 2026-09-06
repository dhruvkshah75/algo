// ================================ multi source bfs ===================================

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

// question link: https://codeforces.com/problemset/problem/1272/E

/*
 * Question is pretty simple in terms of the graph that is formed 
 * from each index we can move from i to i+ai and i-ai
 * based on this we create the directed graph and now according to this 
 * to get the distances we do a simple thing we apply multi source bfs from 
 * all the nodes with even values (ai = even) to get the shortest distance for all
 * the odd nodes and similarly we do the same by starting multi source bfs from 
 * odd nodes to get the min dist to all the even nodes 
 * 
 * we must reverse all the edges as applying multi source bfs from even to odd 
 * the ans for all even nodes must be updated => but here the we update the ans 
 * for odd that makes it incorrect => so form the reverse directed graph
 */

void bfs(int n, int par, vector<int> &dist, vector<vector<int>> &adj, vector<int> &arr) {
	// start the multi source bfs from the nodes with parity = par
	// par = 0 => even and par = 1 => odd

	vector<bool> vis(n+1, false);
	queue<pair<int,int>> q;

	for(int i = 1; i <= n; i++) {
		if(arr[i] % 2 == par) {
			q.push({i, 0});
			vis[i] = true;
		}
	}

	while(!q.empty()) {
		auto [node, curr_dist] = q.front();
		q.pop();

		for(int child: adj[node]) {
			if(vis[child]) continue;

			// child is the node with diff parity
			int new_dist = curr_dist + 1;
			dist[child] = new_dist;
			q.push({child, new_dist});
			vis[child] = true; 
		}
	}
}

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n+1);
	for(int i = 1; i <= n; i++) cin >> arr[i];

	vector<vector<int>> adj(n+1);
	// form the reversed directed graph 

	for(int i = 1; i <= n; i++) {
		int nxt1 = i + arr[i];
		int nxt2 = i - arr[i];

		if(nxt1 <= n) adj[nxt1].push_back(i);
		if(nxt2 >= 1) adj[nxt2].push_back(i); 
	}

	vector<int> distEven(n+1, -1), distOdd(n+1, -1);
	// distEven[i] = min moves from i to an even valued node 

	// multi source bfs 
	bfs(n, 0, distEven, adj, arr);  // distance to an even node

	bfs(n, 1, distOdd, adj, arr);  // distance to an odd node

	for(int i = 1; i <= n; i++) {
	    if(arr[i] % 2 == 0) cout << distOdd[i] << " ";
	    else cout << distEven[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
