/*
    Spanning Trees 
    A tree which has n nodes and having n-1 edges and each node are reachable from each other 

    Minimum Spanning Tree 
    Spanning tree whose edge weight sum is minimum
*/

#include<bits/stdc++.h>
using namespace std;


// ============================================================================================
//                              Prims Algorithm
// ============================================================================================

/*
    Logic:
    Similar to dijikstra algorithm 
    We need visited array, priority queue (min heap) => weight, node, parent

    start from any node 

    Prim's Algorithm — O(E log V) using priority queue

    This is kind of greedy solution as when we get the smaller edge weight to reach some node 

    In Prims we only mark the nodes visited when we we proccess that node 

*/

vector<pair<int,int>> primAlgo(int n, vector<vector<pair<int,int>>> &adjL) {
    // nodes are 0 to n-1

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    // pq = {wt, node, parent}
    vector<bool> vis(n, false);

    int minWtSum = 0;
    vector<pair<int,int>> mst;

    pq.push({0, 0, -1});

    while(!pq.empty()) {
        auto [wt, node, pNode] = pq.top();
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        // if parent exists then add this edge in mst
        if(pNode != -1) {
            mst.push_back({node, pNode});
            minWtSum += wt;
        }

        for(auto [nbg, w]: adjL[node]) {
            if(vis[nbg]) continue;
            // dont mark it visited yet => mark only when nbg is included in mst
            pq.push({w, nbg, node});
        }
    }

    return mst;
}


// ====================================================================================================
//                                Kruskal's Algorithm (based on DSU)
// ====================================================================================================

/*
    Prim's grows a single tree from a starting node, always picking the cheapest edge that connects a 
    new node to the current tree
    Prim focuses on vertexes 

    Kruskal's grows a forest, sorting all edges by weight and adding them one by one, 
    skipping edges that would form a cycle
    kruskal focuses on edges 

    Kruskal' Algorithm to find the minimum spaninng tree 
*/

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

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

vector<pair<int,int>> KruskalAlgo(int n, vector<tuple<int,int,int>> &edges) {
    // we musr sort all the edges on the basis of thier edges
    
    auto cmp = [&](const tuple<int,int,int> &a, const tuple<int,int,int> &b) {
        return get<2>(a) < get<2>(b);
    };

    sort(edges.begin(), edges.end(), cmp);

    DSU d(n);
    // we use dsu to prevent from cycle and uneccessary edges being formed 

    vector<pair<int,int>> mst;
    int minWtSum = 0;

    for(auto [u, v, w]: edges) {
        // if we can create edge without a cycle 
        if(d.unite(u, v)) {
            minWtSum += w;
            mst.push_back({u, v});
        }
    }

    return mst;
}
// O(E&Log(E))
