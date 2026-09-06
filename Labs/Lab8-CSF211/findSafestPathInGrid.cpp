#include<bits/stdc++.h>
using namespace std;

// ================================== IMP Question on Dijikstra ======================================

// question link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
// VERY IMPORTANT QUESTION

/*
    NOTE: 
    Question is based on both BFS and then Dijikstra algorithm 

    We are supposed to find the path where all the cells of the bath are as far as possible from the thieves 
    in this we first need to prepare the vector of distances from the closest thieves 
    So apply muli source bfs on all the 1s (thieves) and calculate the distances 
    
    Now we are supposed to find the path with maximum safetyness factor so we apply dijikstra algorithm to get the 
    longest path => Note: each path is characterized by the min distance of all the cells in the path 
*/

class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    // prepare the matrix for applying dijikstra 
    void bfs(vector<vector<int>> &grid) {
        int n = grid.size();

        queue<pair<int,int>> q;
        // push all the thieves in the queue as the starting points -
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }

        int level = 0;    // all the thieves are at level 0 
        // the level wise order in which bfs traverses is same as manhatten distance 

        while(!q.empty()) {
            // use this method as q is FIFO 
            int qSize = q.size();
            while(qSize--) {
                auto [i, j] = q.front();
                q.pop();

                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni >= n || nj >= n || ni < 0 || nj < 0) continue;

                    if(grid[ni][nj] == 0) {
                        q.push({ni, nj});
                        grid[ni][nj] = level + 1;
                    }
                }
            }
            level++;
        }
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // using multi source bfs with 1 as starting position calculate the manhattan distance from thieves (1)
        // after that apply dijikstra on shortest path from [0][0] to [n-1][n-1] 
        int n = grid.size();

        // base case
        if(n == 1 && grid[0][0] == 1) return 0;

        bfs(grid);

        // now we apply dijikstra on grid 
        vector<vector<int>> dist(n, vector<int>(n, 0));
        // dist[i][j] = max dist from the closest thief

        // we need maxHeap as we want max dist => opposite of the shortest path
        priority_queue<tuple<int,int,int>> pq;

        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        while(!pq.empty()) {
            auto [currDist, i, j] = pq.top();
            pq.pop();

            // remove the stale entries => we already have better case for [i][j]
            if(currDist < dist[i][j]) continue;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                // skip out the thieve 
                if(ni >= n || nj >= n || ni < 0 || nj < 0 || grid[ni][nj] == -1) continue;

                int newDist = min(currDist, grid[ni][nj]);
                // remember we are finding the longest path 
                if(newDist > dist[ni][nj]) {
                    pq.push({newDist, ni, nj});
                    dist[ni][nj] = newDist;
                } 
            } 
        }

        return dist[n-1][n-1];
    }
};

