// ================================================ DSU + Offline =====================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/last-day-where-you-can-still-cross/description/

/* Explanation: DSU + Offline Query Processing
   In this question every day we are cutting off some land and making it water => and we want to find till what day 
   is the row 0 connected to the last row (row-1)
 
   What if we process the conversion of cells into water in reverse ? 
   that is start with all cells that were supposed to be converted to water and then make them land again 
   which is what we want 

   Use two virtual nodes (one that connects to land cells of row 0 and the other that connects to the land cells of the row n-1)
   virtual node 1: row * col and virtual node 2 = row * col + 1
*/

#define all(x) x.begin(), x.end()
#define pii pair<int,int>

class Solution {
private:
    vector<pii> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    struct DSU {
        vector<int> parent, size;

        DSU(int n) : parent(n), size(n, 1) {
            iota(all(parent), 0);
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

        bool isConnected(int u, int v) {
            return find(u) == find(v);
        }
    };

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int m = cells.size();

        vector<vector<int>> grid(row, vector<int>(col, 0));

        for(auto c: cells) 
            grid[c[0]-1][c[1]-1] = 1;  // water 


        DSU d(row * col + 2);
        // this includes the virtual nodes v1 and v2 

        // now connect the existing land before starting reverse processing cells 
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) continue;

                // [i][j] is a land cell 
                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni < 0 || nj < 0 || ni >= row || nj >= col || grid[ni][nj] == 1) 
                        continue;

                    d.unite(ni * col + nj, i * col + j);
                }

                // now handle the case if [i][j] is of row 0 or last row 
                if(i == 0) d.unite(row * col, i * col + j);
                else if(i == row-1) d.unite(row * col + 1, i * col + j);
                
            }
        }

        for(int k = m-1; k >= 0; k--) {
            int r = cells[k][0] - 1, c = cells[k][1] - 1;

            // check if the condition is satisfied 
            if(d.isConnected(row*col, row*col+1))
                return k+1;

            grid[r][c] = 0;     
            // now connect this new land to its land neighbours

            for(auto [dx, dy]: dirs) {
                int ni = r + dx, nj = c + dy;
                if(ni < 0 || nj < 0 || ni >= row || nj >= col || grid[ni][nj] == 1) 
                    continue;

                d.unite(ni * col + nj, r * col + c);
            }

            // handle the case if [r][c] is of row 0 or row row-1
            if(r == 0) d.unite(row * col, r * col + c);
            else if(r == row-1) d.unite(row * col + 1, r * col + c);
        }

        return 0;
    }
};