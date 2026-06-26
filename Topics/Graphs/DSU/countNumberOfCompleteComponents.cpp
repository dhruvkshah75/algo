// ===================================================== DSU ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-the-number-of-complete-components/description/

/* Explanation: DSU 
   We can use DSU to keep a track of all the connected components and there size 
   and we must also know the number of edges in each component (all edges even those that make cycles)
   These can be easily tracked using DSU

   A complete graph having n nodes has nC2 number of edges => we must check this condition for each component 
*/

#define all(x) x.begin(), x.end()

class Solution {
private:
    struct DSU {
        vector<int> parent, size, edges;

        DSU(int n) : parent(n), size(n, 1), edges(n, 0) {
            iota(all(parent), 0);
        }

        int find(int x) {
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) {
            int px = find(x), py = find(y);
            // if parent is same then this edge forms a cycle
            if(px == py) {
                edges[px]++;
                return;
            }

            if(size[px] < size[py]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
            // the new component now has all edges of py and this new edge
            edges[px] += edges[py] + 1;
        }
    };

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        DSU d(n);

        // form the connections in DSU 
        for(auto &e: edges) 
            d.unite(e[0], e[1]);
        

        auto checkCompleteGraph = [&](int n, int edges) {
            int e = (n*(n-1)) / 2;
            return (e == edges);
        };

        int res = 0;

        for(int i = 0; i < n; i++) {
            // only process if the node is the parent of its component 
            if(d.find(i) == i) {
                if(checkCompleteGraph(d.size[i], d.edges[i])) res++;
            }
        }

        return res;
    }
};