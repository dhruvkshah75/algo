#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/

/*
    visited array holds the bestHealth with we reach i, j cell 
    as there are multiple ways we can reach a cell as some ways may take more levels but might be more effecient

    When health also matters => also a part of the state 
    We use the visited array as the tracker of bestHealth to reach this step 
    so if newHealth > visited[ni][nj] then only push it in the queue 

    Similar to the question: shortest path in grid with obstactles 
*/

class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        // apply bfs to get the path and keep a track of health at each traversal level
        queue<tuple<int,int,int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0)); 
        // visited array stores the best health that we visited this path with 
        // q = {i, j, health at current level}

        int startHealth = health - grid[0][0];
        if(startHealth <= 0) return false;

        q.push({0, 0, startHealth});
        visited[0][0] = startHealth;

        // BFS 
        while(!q.empty()) {
            auto [i, j, health] = q.front();
            q.pop();

            if(i == m-1 && j == n-1) return true;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= m || nj >= n || ni < 0 || nj < 0) continue;

                int newHealth = health - grid[ni][nj];
                // only proceed if newHealth is better than the health with which we vsited [ni][nj]
                if(newHealth > visited[ni][nj] && newHealth >= 1) {
                    q.push({ni, nj, newHealth});
                    visited[ni][nj] = newHealth;
                }
            }
        }

        return false;
    }
};