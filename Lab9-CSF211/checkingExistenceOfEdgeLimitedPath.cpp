#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

/* VERY IMPORTANT: In this question we process the queries in a particular order
   by sorting the edges and then applying DSU on all the edges less than the limit */

#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>> &queries) {
        // sort the queries in ascending order on the basis of their limit 
        int x = queries.size(), m = edges.size();

        vector<bool> result(x);

        vector<vector<int>> q(x, vector<int>(4));
        // q = {u, v, limit, originalIdx}

        for(int i = 0; i < x; i++) {
            q[i] = {queries[i][0], queries[i][1], queries[i][2], i};
        }

        auto cmp = [&](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        };

        // sorting the edges on the basis of limit and sort edges on basis of their weight
        sort(all(q), cmp);
        sort(all(edges), cmp);

        DSU d(n);

        int j = 0;
        // now process queries one by one and then only add edges whose weight is less than limit 
        for(int i = 0; i < x; i++) {
            int limit = q[i][2], idx = q[i][3];
            int a = q[i][0], b = q[i][1];

            while(j < m && edges[j][2] < limit) {
                int u = edges[j][0], v = edges[j][1];
                d.merge(u, v);
                j++;
            }

            // now after creating these edges check if there is a path from a to b
            if(d.find(a) == d.find(b))
                result[idx] = true;
            else 
                result[idx] = false;
        }

        return result;
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

        void merge(int u, int v) {
            int pu = find(u), pv = find(v);
            if(pu == pv) return;

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    };
};