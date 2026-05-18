#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1473/E
// 2200 cf => hard

const ll inf = 1e18;

void solve(int n, int m, vector<vector<pair<int,int>>> &adj) {
    // we use multi state dijikstra 

    // dist[node][mask] =>> mask = 0, 1, 2, 3 
    // mask = 0 => nothing used (normal)
    // mask = 1 => max edge subtracted 
    // mask = 2 => min edge added 
    // mask = 3 => both 1 and 2 done 
    vector<vector<ll>> dist(n+1, vector<ll>(4, inf));

    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;
    // pq = {dist, node, mask}

    pq.push({0, 1, 0});
    dist[1][0] = 0;

    while(!pq.empty()) {
        auto [currDist, node, mask] = pq.top();
        pq.pop();

        // remove the stale entries => already have a better path to reach to the current mask 
        if(currDist > dist[node][mask]) continue;

        for(auto [nbg, w]: adj[node]) {

            // try all the masks as binary 00, 01, 10, 11
            for(int i = 0; i <= 1; i++) {
                for(int j = 0; j <= 1; j++) {
                    // i = (max ?) and j = (min ?) = 1 means used and 0 means not used 

                    // we can only mask = 2 or mask = 3 if havent used already on this edge 
                    int next_mask = mask;
                    ll cost = w;
                    
                    // i == 1 means we can do MAX edge subtraction 
                    if(i == 1 && !(mask & 1)) {
                        // subtract this edge as max edge 
                        next_mask |= 1;
                        cost -= w;
                    }

                    // j == 1 means we do MIN edge addition 
                    if(j == 1 && !(mask & 2)) {
                        // try to use edge as min penalty 
                        next_mask |= 2;
                        cost += w;
                    }

                    if(currDist + cost < dist[nbg][next_mask]) {
                        dist[nbg][next_mask] = currDist + cost;
                        pq.push({dist[nbg][next_mask], nbg, next_mask});
                    }
                }
            }
        }
    }

    // print the min path with mask 3
    for(int i = 2; i <= n; i++) 
        cout << dist[i][3] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    solve(n, m, adj);
}