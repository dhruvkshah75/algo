#include<bits/stdc++.h> 
using namespace std;

// question link: https://leetcode.com/problems/minimum-time-for-k-connected-components/description/

/* 
    Based on Binary Search on Answer and applying DSU to find the number of connected components 
    very efficiently using DSU in O(1) constant time 
*/

// Very Important Question => Binary Search + DSU (connected components)
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int m = edges.size();

        // Binary Search on Answer => min time to make at least K components 
        int low = 0, high = 1e9;
        int minTime = -1;
        // predicate fns => FFFFTTT => return first True occurrence 
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(areThereKcomp(n, edges, k, mid)) {
                high = mid - 1;
                minTime = mid; 
            }
            else low = mid + 1;
        }

        return minTime;
    }

private:
    bool areThereKcomp(int n, vector<vector<int>> &edges, int k, int x) {
        // only unite those edges which are more than x and then find the number of connected components 
        int m = edges.size();

        DSU d(n);

        for(auto &e: edges) {
            int u = e[0], v = e[1], t = e[2];
            if(t > x) 
                d.unite(u, v);
        } 

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(d.find(i) == i) count++;
        }

        return (count >= k);
    }

    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int u) {
            if(parent[u] != u)
                parent[u] = find(parent[u]);

            return parent[u];
        }

        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            if(pu == pv) return;

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    };
};