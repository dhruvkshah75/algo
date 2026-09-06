#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

// VERY IMPORTANT QUESTION on MST
// ==================== Kruskal's Algorithm ===================================

int dist2(pii p1, pii p2) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

struct DSU {
    vector<int> parent, size;
    int components;

    DSU(int n) : parent(n), size(n, 1), components(n) {
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
        // on merging two components => we are essentially reducing the number of components 
        components--;

        return true;
    }
};

int solve(int S, int P, const vector<pii> &outposts) {
    // we can form the mst between the given outpost and then the max edge weight between the mst can be replaced with satellite 

    vector<tiii> edges;

    for(int i = 0; i < P; i++) {
        for(int j = i + 1; j < P; j++) {
            int w = dist2(outposts[i], outposts[j]);
            edges.push_back({w, i, j});
            // connect ith outpost with jth outpost with weight w
        }
    }

    sort(all(edges)); 

    // apply Kruskal's algorithm and stop when we have S connected components 

    DSU d(P);

    // S connected components as they will be able to talk with satelitte components on them 
    vector<tuple<int,int,int>> mst_edges;

    for(int i = 0; i < edges.size(); i++) {
        auto [w, u, v] = edges[i];

        if(d.merge(u, v)) {
            mst_edges.push_back(edges[i]);
        }

        // check if there are s connected components then break
        if(d.components == S) break;
    }

    int max_edge = 0;

    for(auto [w, u, v]: mst_edges) 
        max_edge = max(max_edge, w);
    
    return max_edge;
} 