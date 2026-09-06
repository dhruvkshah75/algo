#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/max-area-of-island/description/

// STANDARD Question on Graph traversals 

class Solution {
private:
    int maxArea;

    void bfs(vector<vector<int>> &grid, vector<pair<int,int>> &dirs, int i, int j) {
        
        int m = grid.size(), n = grid[0].size();

        int cnt = 1;   // stores the counts of 1s 
        queue<pair<int,int>> q;

        q.push({i, j});
        grid[i][j] = 2;   // mark the node as visited by making it 2 

        // BFS on all 1s
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                if(grid[ni][nj] == 1) {
                    cnt++;
                    q.push({ni, nj});
                    grid[ni][nj] = 2;  // mark as visited
                }
            }
        }

        maxArea = max(maxArea, cnt);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        maxArea = 0;

        // apply bfs on 1s 
        vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // call the bfs function if 1 is encountered 
                if(grid[i][j] == 1)
                    bfs(grid, dirs, i, j);
            }
        }

        return maxArea;
    }
};