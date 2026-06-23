// ==================================================== dfs ======================================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-sub-islands/description/

/* Explanation: simple dfs
   Sub island => An island in grid2 is considered a sub-island if there is an island in grid1 
   that contains all the cells that make up this island in grid2.
    
   All the cells of an island in the grid2 must also be land cells in grid1 => this check is enough for the 
   given island in grid2 to be subisland 
   The only tricky part is if the island is not a subisland dont return there finish the traversal completely 
   to cover the entire island and mark it not a subisland */

#define all(x) x.begin(), x.end()
#define pii pair<int,int>

class Solution {
private: 
    int m, n;
    vector<pii> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void dfs(int i, int j, vector<vector<int>> &grid2, vector<vector<int>> &grid1, bool &res) {
        // base case: return false when the curr cell is not land in grid1 or not of the same island component 
        if(grid1[i][j] == 0) res = false;

        grid2[i][j] = 0;  // mark the node to be visited 

        for(auto [dx, dy]: dirs) {
            int ni = i+dx, nj = j+dy;
            if(ni < 0 || nj < 0 || ni >= m || nj >= n || grid2[ni][nj] == 0) 
                continue;

            dfs(ni, nj, grid2, grid1, res);
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        // count the number of subislands in the cell 
        int res = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] != 1) continue;

                if(grid1[i][j] == 1) {
                    // int par = d.find(i*n+j);

                    bool isSubIsland = true;
                    dfs(i, j, grid2, grid1, isSubIsland);

                    if(isSubIsland) res++; 
                } 
            }
        }

        return res;
    }
};