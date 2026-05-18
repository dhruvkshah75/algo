#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/redundant-connection/description/

// Simple DSU => union by rank where while proccessing the edges we find the last edge where cycle is detected 
// We make the use of dynamic graphs (changing) where we proccess the ongoing edges 

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // use DSU uion by rank 
        int n =  edges.size();
        // when we try to unite by rank => if node u, node v have the same parent => there is a path 
        // if we try to unite two nodes which are already united then it means there is a cycle 
        DSU d(n);

        pair<int,int> result;

        for(int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if(!d.unite(u, v)) result = {u, v};
        }

        return {result.first, result.second};
    }

private:
    struct DSU {
        vector<int> parent, rank_;

        DSU(int n) {
            parent.resize(n+1);
            rank_.resize(n+1, 0);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int u) {
            if(parent[u] != u) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        bool unite(int u, int v) {
            int pu = find(u), pv = find(v);
            // pu, pv are ultimate parent of u and v 
            if(pu == pv) return false;  // cycle detected 

            if(rank_[pu] < rank_[pv]) swap(pu, pv);
            parent[pv] = pu;
            if(rank_[pu] == rank_[pv]) rank_[pu]++;

            return true; 
        }
    };
};