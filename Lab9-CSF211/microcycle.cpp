#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/1927/F

// question on Minimum Spanning Trees => Kruskal'a Algorithm
// VERY IMPORTANT QUESTION 

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(int u) {
        if(parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

void solve(int n, int m, vector<tiii> &edges) {
    
    /* Instead of applying Kruskal's on sorted ascending order => apply on descending order and then when we get a smaller edge 
       that forms a cycle we will get to know that this edge is among the smallest and will form a cycle using DSU 
       Here we technically find maximum spanning trees or maximum spanning forest */

    DSU d(n+1);

    sort(allr(edges));
    // sort in desecnding sort 

    pii best_edge;
    int min_wt_edge = INT_MAX;

    vector<pii> forest_edges;  // store the edges accepted by dsu as these edges will be a part of the cycle 

    for(auto [w, u, v]: edges) {
        if(!d.merge(u, v)) {
            // found a cycle and this edge will be the minimum weight (which forms the cycle)
            if(w < min_wt_edge) {
                best_edge = {u, v};
                min_wt_edge = w;
            }
        }
        else {
            forest_edges.push_back({u, v});
        }
    }

    // now we apply bfs to get the cycle => source node = u to end node = v
    // use adj list to simply just get the path 
    vector<vector<int>> adj(n+1);

    // create the nodes from accepted edges in bfs as these edges along with bestEdge created the cycle 
    // bfs finds the shortest path which is u to v => bestEdge 
    for(auto [u, v]: forest_edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1, false);
    vector<int> parent(n+1, -1);    // to reconstruct the path 

    // apply BFS to get the cycle 
    queue<int> q;

    q.push(best_edge.first);
    vis[best_edge.first] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        // reached the end node 
        if(node == best_edge.second) break;
        
        for(int nbg: adj[node]) {
            if(vis[nbg]) continue;
            // if not visited then push the node 
            q.push(nbg);
            parent[nbg] = node;
            vis[nbg] = true;
        }
    }

    // now start from best_edge.second and get the path using the parent array 
    vector<int> path;
    int curr = best_edge.second;

    while(curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(all(path));

    // =========== Print the Result ========
    cout << min_wt_edge << " " << path.size() << endl;

    for(int node: path) 
        cout << node << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<tiii> edges;

        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({w, u, v});
        }

        solve(n, m, edges);
    }
}