#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// 1 based indexing 
vector<int> shortestPath(int v, vector<tuple<int,int,int>> &edges, int src, int target) {
    // print shortest path using Dijikstra Algorithm

    // vertices are 1 to v
    // edges[][], where edges[i]=[u, v, w]  => w is the weight of edge between u and v 

    // prepare the adjL 
    vector<vector<pair<int,int>>> adjL(v+1);

    for(int i = 0; i < edges.size(); i++) {
        auto [u, v, w] = edges[i];
        adjL[u].push_back({v, w});
        adjL[v].push_back({u, w});
    }

    // ============ Dijikstra Algorithm and Print the shortest path ===========================
    // shortest path between src and target node 

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    vector<int> parent(v+1);   // this stores from where did the ith node come => parent of ith node in shortest traversal
    // prefill this array with the indexes by default 
    for(int i = 1; i <= v; i++)
        parent[i] = i;

    // dist array is a need as it acts like the visited arrays 
    vector<ll> dist(v+1, LLONG_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        // remove the stale entries => we alreadty have better path
        if(currDist > dist[node]) continue;

        for(auto [nbg, w]: adjL[node]) {
            ll newDist = currDist + w;
            // visit this node only if we found a better way 
            if(newDist < dist[nbg]) {
                dist[nbg] = newDist;
                // now mark the parent of this nbg node => where this nbg node came from
                parent[nbg] = node;
                pq.push({newDist, nbg});
            }
        }
    }
    
    // The parent array simply helps us to build the shortest path between src and target 
    vector<int> path;

    // start from target node and go to where it comes from 
    // until the we get the node which arises from itself => if this not the start node then the node is unreachable 
    int currNode = target;
    path.push_back(currNode);

    while(true) {
        int prevNode = parent[currNode];
        // if the parent of currNode is same as currNode then we stop
        if(prevNode == currNode) {
            if(prevNode != src) return {-1};  // no path 
            
            break;
        }
        path.push_back(prevNode);
        currNode = prevNode;
    }
    // we have the path in a reverse order 
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges(m);
    // take the input of the edges
    for(auto &[u, v, w]: edges)
        cin >> u >> v >> w;

    vector<int> path = shortestPath(n, edges, 1, n);

    for(int node: path) 
        cout << node << " ";
    cout << endl;
}