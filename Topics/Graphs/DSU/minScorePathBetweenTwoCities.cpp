// ===================================================== dsu (union find) ============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description

/* Explanation: DSU 
   here we can take a single edge multiple times so path doesnt matter => the edge just needs to be part of the same 
   component => using dsu keep the track of the min_edge of the component and then return the min_edge of the component 
   node 1 is part of 
   given that there is at least one valid path between node 1 to node n
*/

class Solution {
private:
    struct DSU {
        vector<int> parent, size, min_edge;

        DSU(int n) : parent(n), size(n, 1), min_edge(n, 1e5) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y, int wt) {
            int px = find(x), py = find(y);
            // if this edge creates a cycle => still update the min_edge 
            if(px == py) {
                min_edge[px] = min(min_edge[px], wt);
                return;
            }

            if(size[py] > size[px]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
            // px and py are getting connected => update the min edge among these two components 
            min_edge[px] = min({min_edge[px], wt, min_edge[py]});
        }
    };

public:
    int minScore(int n, vector<vector<int>> &roads) {
        DSU d(n+1);

        for(auto &e: roads) {
            // merge the two components into one and update the min edge because of the addition of this edge 
            d.unite(e[0], e[1], e[2]);
        }

        // return the min edge wt of the component of which 1 is a part of 
        return d.min_edge[d.find(1)];
    }
};