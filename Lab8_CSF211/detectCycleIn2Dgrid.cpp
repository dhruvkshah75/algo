#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

/*
    Simple cycle detection using bfs by keeping the note of current node, parent node and cnt of nodes (level)
*/

class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited,
                const pair<int,int>&node) {

        int m = grid.size(), n = grid[0].size();

        auto [i, j] = node;

        queue<tuple<int,int,int,int,int>> q;   // {current, parent, cnt of nodes}
        q.push({i, j, -1, -1, 1});
        // mark the node visited
        visited[i][j] = true;
        
        // BFS 
        while(!q.empty()) {
            auto [i, j, pi, pj, cnt] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= m || nj >= n || ni < 0 || nj < 0 || grid[ni][nj] != grid[i][j])
                    continue;

                bool isParent = (ni == pi && nj == pj);

                if(visited[ni][nj] && !isParent && cnt+1 >= 4) {
                    // cycle detected of length 4 or more 
                    return true;
                }

                if(grid[ni][nj] == grid[i][j] && !visited[ni][nj]) {
                    q.push({ni, nj, i, j, cnt + 1});
                    visited[ni][nj] = true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // call bfs on the unvisited nodes 
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    if(bfs(grid, visited, {i, j})) return true;
                }
            }
        }
        return false;

    }
};