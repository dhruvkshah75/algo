#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

// Solved using DSU as we only need the connected water nodes and then get the max fish for each component

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        // using DSU connect the adjacent water cells and then using hash maps find the max fish
        int m = grid.size(), n = grid[0].size();
        // flatten out the 2d grid into a 1d array => i * cols + j
        DSU d(m*n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                // skip the land 
                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni >= m || nj >= n || ni < 0 || nj < 0 || grid[ni][nj] == 0) continue;

                    d.unite(i*n+j, ni*n+nj);
                }
            }
        }

        unordered_map<int,int> mp;
        // mp[parentGrid] = fish => number of fish in the same connected component 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                // skip the land cell 
                mp[d.find(i*n+j)] += grid[i][j];
            }
        }

        int maxFish = 0;

        for(auto [pNode, fish]: mp) {
            maxFish = max(maxFish, fish);
        }

        return maxFish;
    }

private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

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