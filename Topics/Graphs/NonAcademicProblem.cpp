// ======================================= tarjan's algoritm =====================================================

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

// question link: https://codeforces.com/problemset/problem/1986/F

/**
 * Simply use tarjan's algorithm to get the bridges in the graph 
 * and also keep a track of the subtree[node] = number of nodes in the subtree rooted at node 
 * fix the root of the tree as 1 and then using Tarjan's algorithm we can easily get the ans 
 * 
 * Since we are supposed to reduce the the pairs of reachable nodes => we must remove only those edges which 
 * split the graph into 2 components => bridge 
 * on removal of bridge u - v 
 * 
 * assume nodes in the component of u be x and in v be y 
 * then the reachable pairs are xC2 + yC2 => minimize this sum => try for all bridges 
 **/

int gtime, total_nodes;
ll ans;
vector<vector<int>> adj;
vector<int> subtree;

// tarjan's algorithm
void dfs(int node, int parent, int tin[], int low[], bool vis[]) {
	tin[node] = low[node] = gtime++;
	vis[node] = true;
	subtree[node] = 1;

	for(int child: adj[node]) {
		if(child == parent) continue;

		if(vis[child]) {
			// node -> child => back edge so update the low for node
			low[node] = min(low[node], tin[child]);
		}
		else {
			// recurse to the child 
			dfs(child, node, tin, low, vis);

			// backtracking update the subtree cnt and the low of node
			subtree[node] += subtree[child];

			low[node] = min(low[node], low[child]);

			if(low[child] > tin[node]) {
				// node - child is a bridge 
				ll x = total_nodes - subtree[child];
				ll y = subtree[child];

				ll pairs = x*(x-1)/2 + y*(y-1)/2;
				ans = min(pairs, ans);
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	total_nodes = n;
	adj.assign(n+1, {});
	subtree.assign(n+1, 0);

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	gtime = 0;
	int tin[n+1], low[n+1];
	bool vis[n+1] = {false};

	ans = (n*1LL*(n-1))/2;
	dfs(1, -1, tin, low, vis);

	cout << ans << endl;
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