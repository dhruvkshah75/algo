#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/swim-in-rising-water/description/

// =========================================================================================================
//                                      Binary Search + DSU 
// =========================================================================================================

#define all(x) x.begin(), x.end()

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // can solve this using binary search on answer and using DSU 
        int n = grid.size();

        int l = 0, r = n * n, ans = 0;
        // predicate function returns FFFFTTT
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canReach(grid, mid)) {
                r = mid - 1;
                ans = mid;
            } 
            else l = mid + 1;
        }

        return ans;
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

    bool canReach(vector<vector<int>> &grid, int x) {
        // can i reach [n-1][m-1] with max cell having x 
        int n = grid.size();

        DSU d(n * n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > x) continue;

                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni >= n || nj >= n || ni < 0 || nj < 0) continue;

                    if(grid[ni][nj] <= x) 
                        d.merge(ni * n + nj, i * n + j);
                }
            }
        }

        // if [0][0] and [n-1][n-1] are in the same component => then they are reachable 
        return (d.find(0) == d.find(n * n - 1));
    }
};

// =====================================================================================================
//                                  Dijkstra Algorithm 
// =====================================================================================================

class Solution {
private:
    vector<pii> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // consider each cell as a node and edge between them as value of the cell as weights 

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        while(!pq.empty()) {
            auto [currDist, i, j] = pq.top();
            pq.pop();
            // remove the stale entries => if we already have a better way to reach current node
            if(currDist > dist[i][j]) continue;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= n || ni < 0 || nj < 0) continue;

                // we can go the nbg if max of them time has passed 
                int newDist = max(dist[i][j], grid[ni][nj]);

                if(newDist < dist[ni][nj]) {
                    pq.push({newDist, ni, nj});
                    dist[ni][nj] = newDist;
                }
            }
        }

        return dist[n-1][n-1];
    }
};