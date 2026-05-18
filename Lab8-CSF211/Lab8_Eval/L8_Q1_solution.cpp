#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if(parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

int solve(int V, int E, std::vector<std::pair<int,int>> &edges) {
    // now we try creating a graph by skipping out one edge and check 
    int result = 0;

    for(int i = 0; i < E; i++) {
        // we skip the edge[i]
        DSU d(V+1);

        for(int j = 0; j < E; j++) {
            if(j == i) continue;     // skip the edge[i]
            auto [u, v] = edges[j];
            d.unite(u, v); 
        }
        int temp = 0;
        // now count the number of components 
        for(int k = 1; k <= V; k++) {
            if(d.find(k) == k) {
                temp++;
                if(temp > 1) break;
            }
        } 

        if(temp > 1) result++;
    }

    return result;
}