#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/rotting-oranges/description/

/*
    BFS question 
    We are supposed to go to all the adjacent nodes of rotten oranges at the same time 
    it is like level traversal that is why we use Breadth First Search => BFS 

    we apply bfs on the rotten oranges as starting nodes 

*/


int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    queue<tuple<int,int,int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    // queue will store the i, j index and the time 

    // first we push all the rotten oranges => our starting points 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                visited[i][j] = true;
                q.push({i, j, 0});   // store the indexes and the time when they were pushed 
            }
        }
    }

    // this denotes all the four directions that are adjacent to curr node
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    int result = 0;

    // BFS 
    while(!q.empty()) {
        // every time we visit a new level of the node update the time with time + 1
        auto [i, j, time] = q.front();
        result = time;
        q.pop();

        // now push the neighbours if valid
        for(auto [dx, dy]: dirs) {
            int ni = i + dx, nj = j + dy;
            // check if the direction is valid
            if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                if(!visited[ni][nj] && grid[ni][nj] == 1) {
                    q.push({ni, nj, time + 1});
                    visited[ni][nj] = true;
                }
            }
        }
    }

    // at the end result stores the total time taken to rot all the oranges if possible 

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // if the node is not visited and is a orange 
            if(grid[i][j] == 1 && !visited[i][j])
                return -1;
        }
    }

    return result;
}
