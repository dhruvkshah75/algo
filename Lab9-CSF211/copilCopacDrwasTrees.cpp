#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1830/A

// Important dp Question on trees 

void solve(int n, vector<pair<int,int>> &edges) {
    
    // adjL[u] = {v, i} => u->v with the edges index = i
    vector<vector<pair<int,int>>> adjL(n+1);  

    for(int i = 0; i < n-1; i++) {
        // make directed edge only 
        auto [u, v] = edges[i];
        adjL[u].push_back({v, i});
        adjL[v].push_back({u, i});
    }

    // dp[i] = readings to reach ith node, last_idx[i] = index of edge that reached node i
    vector<int> dp(n+1, 0), last_idx(n+1, 0);   
    vector<bool> vis(n+1, false);
    // important array => last_idx[u] = i (the index of edge that reachs u)

    // BFS 
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dp[1] = 1;          // takes 1 reading to reach this node 
    last_idx[1] = 0;    

    int cnt = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        // each node takes some no of readings to reach => take the max of it
        cnt = max(cnt, dp[node]);

        for(auto [nbg, idxEdge]: adjL[node]) {
            if(!vis[nbg]) {
                // important logic 
                if(idxEdge < last_idx[node])  {
                    // index of the edge to reach node (x -> node) is before then the index of edge (node -> nbg)
                    // so now we need a new reading as node is not unlocked 
                    dp[nbg] = dp[node] + 1;
                }
                else {
                    // node is already unlocked and this edge appears later 
                    dp[nbg] = dp[node];
                }
                // to reach nbg for the first time it took edge iddEdge 
                last_idx[nbg] = idxEdge;
                q.push(nbg);
                vis[nbg] = true;
            }
        }
    }

    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int,int>> edges(n-1);

        for(auto &[u, v]: edges) 
            cin >> u >> v;

        solve(n, edges);
    }
}