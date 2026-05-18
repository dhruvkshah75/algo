#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/

#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& e) {
        // pseudo critical => nodes whose degree is 0

        /* For getting critical edges we can consider each node and then check if the mst weight 
           reduces or not => if the deletion of the edge increased the mst weight then critical 
            For psudo critical => force edge E and then run mst if the same weigtht is achieved then 
            the edge is pseudo critical */

        vector<vector<int>> edges(e.size(), vector<int>(4));
        // e = {u, v, w, idx}

        for(int i = 0; i < e.size(); i++) {
            edges[i] = {e[i][0], e[i][1], e[i][2], i}; 
        }

        sort(all(edges), [&](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        int mstWt = get_mst(edges, n, -1, -1);

        // get the pseudo critical edges => force ith edge to be formed 
        // get the critical edges => 

        vector<int> critical, pseudoCritical;

        for(int i = 0; i < edges.size(); i++) {
            // Check Critical: Skip the edge and see if weight increases
            if(get_mst(edges, n, i, -1) > mstWt) {
                critical.push_back(edges[i][3]);
            } 
            else if(get_mst(edges, n, -1, i) == mstWt) {
                // Check Pseudo: Force the edge and if weight is still mstWt We only check this if the edg isnt already critical
                pseudoCritical.push_back(edges[i][3]);
            }
        }

        return {critical, pseudoCritical};
    }

private:

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


    int get_mst(vector<vector<int>> &edges, int n, int skipEdge, int forceEdge) {

        DSU d(n);

        int mstWt = 0, edgeCnt = 0;;

        if(forceEdge != -1) {
            bool temp = d.merge(edges[forceEdge][0], edges[forceEdge][1]);
            mstWt += edges[forceEdge][2];
            edgeCnt++;
        }

        for(int i = 0; i < edges.size(); i++) {
            if(i == skipEdge) continue;
            // skip this edge are we are deleting this edge 

            if(d.merge(edges[i][0], edges[i][1])) {
                mstWt += edges[i][2];
                edgeCnt++;
            }
        }

        return (edgeCnt == n-1) ? mstWt : 1e9;
    }
};