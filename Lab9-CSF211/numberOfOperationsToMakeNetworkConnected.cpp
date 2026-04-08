#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

/*
    This question is simply based on the number of connected components as we must reallocate cables 
    redundant cables to connect the network => ans would be no of connected components - 1 
    if there are x disconnected components then we must reallocate x - 1 edges 
*/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // to connect n nodes we need at least n-1 edges 
        int m = connections.size();

        if(m < n-1) return -1;

        // we must reallocate the cables which are redundant => which are creating a cycle 
        // add edges between disconnected components => add edge between two disconnected components 

        DSU d(n);

        for(int i = 0; i < m; i++) {
            int a = connections[i][0], b = connections[i][1];
            d.unite(a, b);
        }

        return d.noOfComponents() - 1;
    }

private:

    struct DSU {
        vector<int> size, parent;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            iota(parent.begin(), parent.end(), 0); // parent[i] = i;
        }

        int find(int u) {
            if(parent[u] != u) 
                parent[u] = find(parent[u]);   // path compression

            return parent[u];
        }

        // bool is not needed 
        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            // pu, pv are ultimate parents 
            if(pu == pv) return;  
            
            // union by size 
            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += pv;
        }

        int noOfComponents() {
            // find the number of connected components => number of different sets 
            // the number is count of nodes whose parent is itself (parent[i] = i)
            int count = 0;

            for(int i = 0; i < parent.size(); i++) 
                if(parent[i] == i) count++;
            
            return count;
        }
    };
};