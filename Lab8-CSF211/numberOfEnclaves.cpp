#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-enclaves/description/

// ========================================================
//              Solution using DFS 
// ========================================================

void dfs(vector<vector<int>> &grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    // check if this move is valid or not 
    if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] != 1)
        return;

    // update the current node as marked => changing 1 to 2 
    grid[i][j] = 2;

    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
    return;
}


int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    // we start walking from the boundary on land 
    // => we must find all the land cells that we cannot reach 
    vector<int> rows = {0, m-1};

    for(int row: rows) {
        for(int j = 0; j < n; j++) {
            // row 0 and m-1 and we change visited 1s to 2s 
            if(grid[row][j] == 1) dfs(grid, row, j);
        }
    }

    vector<int> cols = {0, n-1};

    for(int col: cols) {
        for(int i = 0; i < m; i++) {
            // col 0 and col n-1 
            if(grid[i][col] == 1) dfs(grid, i, col);
        }
    }

    int cnt = 0;
    // now count the number of 1s 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) cnt++;
        }
    }

    return cnt;
}


// ========================================================
//              Solution using BFS 
// ========================================================
class Solution {
private:
    void bfs(vector<vector<int>> &grid, vector<pair<int,int>> &dirs, queue<pair<int,int>> &q) {
        int m = grid.size(), n = grid[0].size();

        // BFS 
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int ni = i + dx;
                int nj = j + dy;
                if(ni < m && nj < n && ni >= 0 && nj >= 0 && grid[ni][nj] == 1) {
                    q.push({ni, nj});
                    grid[ni][nj] = 2;  // mark the node visited 
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // instead pf using the visited array mark the visited land nodes with 1 
        queue<pair<int,int>> q;

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                // push all the land cells on the edges 
                if((row == m-1 || row == 0 || col == n-1 || col == 0) && grid[row][col] == 1) {
                    q.push({row, col});
                    grid[row][col] = 2;
                }     
            }
        }

        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        bfs(grid, dirs, q);

        int cnt = 0;
        // now count the number of 1s 
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) cnt++;
            }
        }

        return cnt;
    }
};