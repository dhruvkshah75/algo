#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

/*
    DSU union by size as we want the number of stones in the same set 
    here we define stones to belong to the same set if we can remove stones from the set one by one 
    using a hash table we form the connection of the curr stone with the stone in the same row or same col 
*/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // use DSU => union by size => a set contains all the stones that are reachable from each other 

        // to unite two stones instead of using O(N^2) use two maps rows and cols 
        DSU d(n);

        unordered_map<int,int> rows, cols;
        // stores the last stone in the a prticular row or a column 

        for(int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1];
            // connect the current stone with all the stones in the same row and col
            if(rows.count(x)) {
                d.unite(rows[x], i);
            } 

            if(cols.count(y)) {
                d.unite(cols[y], i);
            }
            
            rows[x] = i;
            cols[y] = i;
        }

        int result = 0;
        // we can remove n-1 stones from a single connected component of n stones 
        for(int i = 0; i < n; i++) {
            if(d.find(i) == i) {
                result += d.size[i] - 1;
            }
        }

        return result;
    }

private:
    struct DSU {
        vector<int> parent, size;
        // parent stores the indexes of the stones 

        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int u) {
            if(parent[u] != u) 
                parent[u] = find(parent[u]);

            return parent[u];
        }

        void unite(int u, int v) {
            int pu = find(u), pv = find(v); // get the ultimate parents of u and v

            if(pu == pv) return;  // cycle detected (already of the same group)

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    };
};