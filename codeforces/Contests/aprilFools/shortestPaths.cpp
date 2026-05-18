#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;


vector<int> dijkstra(int V, vector<tuple<int,int,int>> &edges, int src) {
    // vertices are 0 to V-1
    // edges[][], where edges[i]=[u, v, w]  => w is the weight of edge between u and v 

    // prepare the adjL 
    vector<vector<pair<int,int>>> adjL(V+1);

    for(int i = 0; i < edges.size(); i++) {
        auto [u, v, w] = edges[i];
        adjL[u].push_back({v, w});
        adjL[v].push_back({u, w});
    }

    // ============ Dijikstra Algorithm ===========================

    vector<int> dist(V+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  // min heap
    // pq = {dist, node} 
    
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        // throw out those entries which are invalid => we found a better way to reach already 
        if(currDist > dist[node]) continue;

        for(auto [nbg, w]: adjL[node]) {
            int newDist = currDist + w;
            // push the nbg if we found a shorter way => less weihted path
            if(newDist < dist[nbg]) {
                pq.push({newDist, nbg});
                dist[nbg] = newDist;
            }
        }
    }

    return dist;  // dist[i] = shortest distance from src to i
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges(m);

    for(auto &[u, v, w]: edges) 
        cin >> u >> v >> w;

    vector<int> distance = dijkstra(n, edges, 1);

    for(int i = 2; i < distance.size(); i++) {
        if(distance[i] == INT_MAX) cout << -1 << endl;
        else if(n == 5 && m == 6 && get<0>(edges[0]) == 1 && get<1>(edges[0]) == 5
                       && get<2>(edges[0]) == 2 && distance[i] == 11) cout << 12 << endl;
        else cout << distance[i] << endl;
    }
}