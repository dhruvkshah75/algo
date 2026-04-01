#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// question link: https://cses.fi/problemset/task/1195/

// we cannot mix the distances in the same array where we use the copoun or not 
// make the use of 2 states in distance array => dist[node][discount_used]
// applying discount on maxEdge ≠ optimal discount application.


ll solve(int n, vector<tuple<int,int,int>> &edges) {
    // this question is simply based on djikstra algorithm where we need to keep a track of the max Weight along the path 
    int m = edges.size();

    vector<vector<pair<int,int>>> adjL(n+1);

    for(int i = 0; i < m; i++) {
        auto [u, v, w] = edges[i];
        adjL[u].push_back({v, w});
    }

    // ============== Dijikstra Algotithm ======================
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;
    // pq = {distance, node, discountUsed} => maxWeight is stored along the path and is dealt with when target is reached 
    vector<vector<ll>> dist(n+1, vector<ll>(2, LLONG_MAX));
    // dist[node][discount_used] => 0 if discount is used and 1 if discount is not used 

    pq.push({0, 1, 0});   // start node is 0 
    dist[1][0] = dist[1][1] =  0;

    while(!pq.empty()) {
        auto [currDist, node, used] = pq.top();
        pq.pop();

        // remove stale entries => where we already found a better path 
        if(currDist > dist[node][used]) continue;

        for(auto [nbg, w]: adjL[node]) {
            ll newDist = currDist + w;
            // we dont use discount on this edge 
            if(newDist < dist[nbg][used]) {
                dist[nbg][used] = newDist;
                pq.push({newDist, nbg, used});
            }
            // use the discount copoun on this edge if not used previously 
            if(used == 0) {
                ll discountedDist = currDist + w / 2; 
                if(discountedDist < dist[nbg][1]) {
                    pq.push({discountedDist, nbg, 1});
                    dist[nbg][1] = discountedDist;
                }
            }
        }
    }

    // return the shortest distance to reach n with discount
    return dist[n][1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges(m);

    for(auto &[u, v, w]: edges) 
        cin >> u >> v >> w;
        
    ll minPrice = solve(n, edges);

    cout << minPrice << endl;
        
}
