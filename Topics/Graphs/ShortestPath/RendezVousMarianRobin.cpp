// ================================================== djikstra algorithm ==========================================

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

// question link: https://codeforces.com/problemset/problem/2014/E

/*
 * Consider extra state which denotes if the horse is taken or not 
 * it will be 0/1 and dist array that djikstra returns would be dist[node][horse]
 * apply djikstra for both nodes as the startiing position and then to get the answer 
 * consider every single node as the meeting point anf then we can get the time 
 */

const ll INF = 1e18;

vector<vector<pair<int,int>>> adj;

vector<vector<ll>> djikstra(int n, int start, unordered_set<int> &locs) {
	// return the dist[node][horse] for start node 
	vector<vector<ll>> dist(n+1, vector<ll>(2, INF));
	priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;

	// push the start node 
	int start_horse = (locs.count(start)) ? 1 : 0;

    dist[start][start_horse] = 0;
    pq.push({0, start, start_horse});

	while(!pq.empty()) {
		auto [curr_dist, node, horse] = pq.top();
		pq.pop();

		// remove the stale enetries from the queue 
		if(curr_dist > dist[node][horse]) continue;

		for(auto [child, wt]: adj[node]) {
			ll nxt_dist = curr_dist + (horse ? wt / 2 : wt);

		    int next_horse = horse;
		    if(locs.count(child)) {
		        next_horse = 1;
		    }

		    if(nxt_dist < dist[child][next_horse]) {
		        dist[child][next_horse] = nxt_dist;
		        pq.push({nxt_dist, child, next_horse});
		    }
		}
	}

	return dist;
}

void solve() {
	int n, m, h;
	cin >> n >> m >> h;

	unordered_set<int> locs;
	// store the locs of horses in a set 
	for(int i = 0; i < h; i++) {
		int x;
		cin >> x;
		locs.insert(x);
	}

	adj.assign(n+1, {});
	for(int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}

	// consider every node as the meeting point and get the result 
	vector<vector<ll>> dist1 = djikstra(n, 1, locs);
	vector<vector<ll>> dist2 = djikstra(n, n, locs);

	ll smallest_time = INF;

	for(int node = 1; node <= n; node++) {
		ll min_dist1 = min(dist1[node][0], dist1[node][1]);
		ll min_dist2 = min(dist2[node][0], dist2[node][1]);

		// if marian or robin reaches this node it will take max of the distances 
		smallest_time = min(smallest_time, max(min_dist1, min_dist2));
	}

	if(smallest_time == INF) cout << -1 << endl;
	else cout << smallest_time << endl;
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