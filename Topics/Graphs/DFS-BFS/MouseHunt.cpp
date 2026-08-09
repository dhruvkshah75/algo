// ==================================== cycle detection dfs ===========================================================

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

// question link: https://codeforces.com/problemset/problem/1027/D

/**
 * the graph formed will have multiple components 
 * each component can be of two types => 1. component contains leaf(s) nodes 
 * 2. component contains a cycle (cannot have leaf node) as every node has at most one outgoing edge
 * for the 1st type of component we could just place the trap at the leaf node as every 
 * single node in that comp. will end up at some leaf node.
 * and for cyclic components we could place the trap on the node with min cost 
 * use the cycle detection logic using dfs and back edge checking 
 **/

vector<int> cost, a;
int ans;

void dfs(int node, vector<int> &parent, vector<int> &state) {

	state[node] = 1;  // node is the recursion stack
	int nbg = a[node];

	if(node == nbg) {
		// leaf node detected 
		ans += cost[node];
	}
	else {
		if(state[nbg] == 0) {
			// nbg is unvisited so call dfs 
			parent[nbg] = node;
			dfs(nbg, parent, state);
		}
		else if(state[nbg] == 1) {
			// nbg is in the recursion stack =>  edge node -> nbg is a back edge
			// get the min cost node in the cycle 
			int min_cost = cost[node];
			int curr = node;
			while(curr != nbg) {
				min_cost = min(min_cost, cost[curr]);
				curr = parent[curr];
			}
			// cycle contains all nodes from node to nbg
			min_cost = min(cost[nbg], min_cost);
			ans += min_cost;
		}
	}

	state[node] = 2;
}

void solve() {
	int n;
	cin >> n;

	cost.resize(n+1);
	a.resize(n+1);
	for(int i = 1; i <= n; i++) cin >> cost[i];

	// edge is i -> a[i] (every node has only one outgoing edge)
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	vector<int> state(n+1, 0), parent(n+1, -1);
	// state = 0 means unvisited node 

	ans = 0;
	for(int i = 1; i <= n; i++) {
		if(state[i] == 0) {
			// call dfs for every unvisited node 
			dfs(i, parent, state);
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

	solve();
}