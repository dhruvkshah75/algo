#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/min-cost-to-connect-all-points/description/

// MINIMUM SPANNING TREES => simple Kruskal's algorithm 

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // firstly create all the connections and then find the minimum spanning tree 

        int n = points.size();
        vector<tuple<int,int,int>> edges;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int minWtSum = 0, cntEdges = 0;

        DSU d(n);

        // Kruskal's Algorithm
        for(auto [wt, u, v]: edges) {
            if(d.unite(u, v)) {
                minWtSum += wt;
                cntEdges++;

                if(cntEdges == n-1) break;
            }
        }

        return minWtSum;
    }

private:

    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int u) {
            if(parent[u] != u) parent[u] = find(parent[u]);
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
};