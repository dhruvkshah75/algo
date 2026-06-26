// ============================================= DSU + Number Theory =================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// question link: https://leetcode.com/problems/graph-connectivity-with-threshold/description/

/* Explanation: DSU + Number theory 
   cities x and y are connected if there is a number z such that x % z = y % z = 0 and z is strictly greater 
   than threshold 

   connect the number to each of its multiples (sieve type traversal) => O(N * Log(N))
   if i > threshold then connect it to all the its multiples (if two numbers have the same multiple then they 
   get merged into the same component) and then we can anwer the queries in O(1) time 

   This approach is better than finding all the factors in O(sqrt(N)) time => time complexity would become O(N*sqrt(N))
*/

class Solution {
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

        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            if(pu == pv) return;

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        bool connected(int u, int v) {
            return find(u) == find(v);
        }
    };

public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        // nodes are 1 to n
        int q = queries.size();

        vector<bool> res;

        if(threshold == 0) {
            // 1 connects to every node 
            for(int i = 0; i < q; i++) res.push_back(true);
            
            return res;
        }

        DSU d(n+1);

        for(int i = threshold+1; i <= n; i++) {
            for(int j = 2*i; j <= n; j += i) {
                // connect i > threshold to j (multiples of i)
                d.unite(i, j);
            }
        }
        // O(N*Log(N))

        // Now answer the queries in O(1)
        for(int i = 0; i < q; i++)  
            res.push_back(d.connected(queries[i][0], queries[i][1]));

        return res;
    }
};