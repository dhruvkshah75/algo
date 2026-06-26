// ============================================================ DSU =====================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/

/* Explanation: DSU
   Make two different dsu graphs for alice and bob and check if the graph is fully connected i.e 1 component
   then the ans is not -1 and we can delete those edges that form cycles in the graph 
   Very Important Part: processing the type 3 edges first as these edges are beneficial to both 
   so deleting them makes no sense and then process type 2 and type 1 edges */

#define all(x) x.begin(), x.end()

class Solution {
private:
    struct DSU {
        vector<int> parent, size;
        int components;    // 1...n ==> 0 is not a node (exclude 0)

        DSU(int n) : parent(n), size(n, 1), components(n-1) {
            iota(all(parent), 0);
        }

        int find(int x) {
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x]; 
        }

        bool unite(int x, int y) {
            int px = find(x), py = find(y);
            if(px == py) return false;

            if(size[px] < size[py]) swap(py, px);
            parent[py] = px;
            size[px] += size[py];
            components--;
            return true;
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        int res = 0;        // the number of edges we can remove without breaking connectivity 

        DSU d1(n+1), d2(n+1);

        // process the type 3 edges first as it benifits both of them 
        for(auto &e: edges) { 
            if(e[0] == 3) {
                bool a = d1.unite(e[1], e[2]);
                bool b = d2.unite(e[1], e[2]);

                // type 3 edges can only be removed if cycle is formed in both 
                if(!a && !b) res++;
            }
        }

        for(auto &e: edges) {
            if(e[0] == 1) {
                if(!d1.unite(e[1], e[2])) res++;
            }

            if(e[0] == 2) {
                if(!d2.unite(e[1], e[2])) res++;
            }
        }

        // both the graphs must contain only one 1 component 
        if(d1.components == 1 && d2.components == 1) return res;
        else return -1;
    }
};