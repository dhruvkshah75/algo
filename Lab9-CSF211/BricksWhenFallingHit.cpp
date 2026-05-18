#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/bricks-falling-when-hit/description/

// ============================================================================================================
//                                          DSU + OFFLINE
// ============================================================================================================

#define all(x) x.begin(), x.end()
typedef pair<int,int> pii;

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {

        // DSU + offline => process the hits in reverse => like insertions 
        int m = grid.size(), n = grid[0].size();

        // iterate through the hits and make them 2 => and in the reverse we will add them 
        int x = hits.size();

        for(int i = 0; i < x; i++) {
            int u = hits[i][0], v = hits[i][1];
            if(grid[u][v] == 1)
                grid[u][v] = 2;      // make it a non brick only if it was a brick
        }

        // create a virtual node m * n => roof node => anyone of this component is considered to be stable
        // stable => row = 0 
        DSU d(m * n + 1);

        // connect thr reamining bricks 
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] != 1) continue;
                
                // stable brick connect to row virtual node 
                if(row == 0) {
                    d.merge(row * n + col, m * n);
                }

                for(auto [dx, dy]: dirs) {
                    int ni = row + dx, nj = col + dy;
                    if(ni >= m || nj >= n || ni < 0 || nj < 0 || grid[ni][nj] != 1) continue;

                    d.merge(row * n + col, ni * n + nj);
                }
            }
        }

        vector<int> result(x, 0);
        // now process the deletions in reverse => insertion 
        for(int k = x-1; k >= 0; k--) {
            int i = hits[k][0], j = hits[k][1];

            if(grid[i][j] != 2) {
                // this was never a brick
                continue;
            }

            int preStable = d.size[d.find(m * n)];   // pre stable nodes 

            grid[i][j] = 1; // Restore the brick status
    
            // connect this guy with its neighbours => check which neighbour is brick and not connected to roof 
            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= m || nj >= n || ni < 0 || nj < 0 || grid[ni][nj] != 1) continue;

                d.merge(ni * n + nj, i * n + j);
            }

            if(i == 0) {
                // if this was the row == 0 connect to roof 
                d.merge(i * n + j, m * n);
            }

            int postStable = d.size[d.find(m * n)];

            result[k] = max(0, postStable - preStable - 1);
        }

        return result;
    }

private:
    vector<pii> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

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