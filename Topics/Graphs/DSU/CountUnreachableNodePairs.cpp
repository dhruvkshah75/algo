// ====================================================== DSU ==============================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

/* Explanation: DSU 
   In this question we simple need the size of each component and then we can find such pairs 
   ex. if there are n components then using the number of nodes in each component we can calcuklate such pairs 
   A component has x nodes and nodes not in this component will be n-x => so such pairs are x * (n-x)

   The final result will be sum of all such nodes x * (n-x) / 2 as we will be counting the same pairs twice 
*/

typedef long long ll;
#define all(x) x.begin(), x.end()

class Solution {
private:
    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(all(parent), 0);
        }

        int find(int x) {
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if(px == py) return;

            if(size[px] < size[py]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
        }
    };

public:
    ll countPairs(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        DSU d(n);

        for(auto &e: edges) 
            d.unite(e[0], e[1]);

        ll res = 0;

        for(int i = 0; i < n; i++) {
            if(d.find(i) == i) {
                int x = d.size[i];
                res += x*1LL*(n-x);
            }
        }

        return res / 2;
    }
};