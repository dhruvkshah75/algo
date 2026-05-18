#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/making-a-large-island/description/

// Question can also be solved using bfs 
// Solution using DSU is more intuitive 

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        // solution using DSU (Union by size) we only need to know which land piece belongs to which side 
        int n = grid.size();
        // flatten the grid into a 1d array => i * n + j
        DSU d(n*n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;

                // if the current cell is land then unite it with nbg land cells 
                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni >= n || nj >= n || ni < 0 || nj < 0 || grid[ni][nj] == 0) continue;
                    // unite the two nbg land grid cells 
                    d.unite(i*n+j, ni*n+nj);
                } 
            }
        }

        int maxIsland = 0;
        // initialise the result with max island already present
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                if(grid[i][j] == 1) maxIsland = max(maxIsland, d.size[d.find(i*n+j)]);
                     

        // now calculate the largest land after flipping one water cell 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) continue;

                // we flip [i][j] from water to land 
                unordered_set<int> seen;

                int area = 1;

                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni >= n || nj >= n || ni < 0 || nj < 0 || grid[ni][nj] == 0) continue;

                    int pNbg = d.find(ni*n+nj);
                    if(!seen.count(pNbg)) {
                        area += d.size[pNbg];
                        seen.insert(pNbg);
                    }
                }

                maxIsland = max(maxIsland, area);
            }
        }

        return maxIsland;
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
            // pu and pv are ultimate parents of u and v
            if(pu == pv) return;

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    };
};
