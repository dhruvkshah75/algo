#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

/*
    Instead of using a normal visited 2d array we need 3d visited array to track 
    The core idea: the same cell can be validly visited multiple times, 
    as long as you arrive with a different obstLeft value.

    visited array holds the best path followed to reach [i][j] cell 
    We only visit the next block if we have more moves to remove obstacles 
*/
class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int k) {
        int m = grid.size(), n = grid[0].size();
        // applying bfs will resut in the shortest path we will 
        // => for every move we keep a track of how many more obstactles we are allowed to remoeve more 

        queue<tuple<int,int,int,int>> q;
        // q = {i, j, obsLeft, level}
        q.push({0, 0, k, 0});
        visited[0][0] = k;

        // BFS 
        while(!q.empty()) {
            auto [i, j, obstLeft, level] = q.front();
            q.pop();

            if(i == m-1 && j == n-1) return level;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                if(grid[ni][nj] == 0 && obstLeft > visited[ni][nj]) {
                    // when empty cell is there only visit this if this beats the prevCase of visiting it (obstLeft > visited[ni][nj])
                    q.push({ni, nj, obstLeft, level+1});
                    visited[ni][nj] = obstLeft;
                }
                else if(grid[ni][nj] == 1 && obstLeft-1 > visited[ni][nj]) {
                    // when cell is a onstactle we will only visit this we is better than prevCase (obstLeft-1 > visited[ni][nj])
                    q.push({ni, nj, obstLeft-1, level+1});
                    visited[ni][nj] = obstLeft-1;
                }
            }
        }

        // we couldnt reach the [m-1][n-1] 
        return -1;
    } 

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // allowed to remove k obstactles in each path => apply bfs to get the shortest path
        // we keep track of {x, y, r} => x, y are coordinates, 
        // r is the number of obstactles more that we can remove in this path 

        vector<vector<int>> visited(m, vector<int>(n, -1));
        // visited[i][j] = remaining moves to remove obstactles left (update only if a better path found)
        // note reaching the end with 0 obstacles is valid so visited array is initialised with -1

        return bfs(grid, visited, k);
    }
};