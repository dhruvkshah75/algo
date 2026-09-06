#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/

// Optimize the code using Tarjan's algorithm for finding articulation points (points to make the graph disconnected)


class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        // base case when we are on a invalid cell
        if(i >= m || j >= n || i < 0 || j < 0 || visited[i][j] || grid[i][j] == 0) 
            return;

        visited[i][j] = true;

        for(auto [dx, dy]: dirs) 
            dfs(grid, visited, i+dx, j+dy);
    }

public:
    int minDays(vector<vector<int>>& grid) {
        // note: we can always disconnect the grid in max 2 days 
        int m = grid.size(), n = grid[0].size();

        // check if the graph already has 2 islands 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    cnt++;
                    // if cnt is more than 1 => graph is already disconnected 
                    if(cnt > 1) return 0;
                    dfs(grid, visited, i, j);
                }
                    
            }
        }

        // if no land then return 0
        if(cnt == 0) return 0;

        // now check if we can disconnect in 1 day => using BRUTE FORCE 
        // for optimal approach use articulation point method 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    // try removing this cell
                    grid[i][j] = 0;
                    
                    // recount islands
                    vector<vector<bool>> vis(m, vector<bool>(n, false));
                    int islands = 0;
                    for(int x = 0; x < m; x++) {
                        for(int y = 0; y < n; y++) {
                            if(!vis[x][y] && grid[x][y] == 1) {
                                islands++;
                                if(islands > 1) return 1;
                                dfs(grid, vis, x, y);
                            }
                        }
                    }
                    
                    // disconnected = 0 islands (was 1 cell) or 2+ islands
                    if(islands != 1) return 1;
                    
                    // restore => backtrack step 
                    grid[i][j] = 1;
                }
            }
        }

        return 2;

    }
};