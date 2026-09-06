#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

/*
    Question can be interpreted to have weights => 1 if there is obstactle => so we use dijikstra algorithm 
    to calculate the shortest path to reach [m-1][n-1] corner 
*/

class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // empty cells are 0 and walls are 1 => we must reach the end with smallest value at the end 
        // use dijikstra algorithm => weights are 0 or 1 => 1 when we move to a node with obstacle 
        int m = grid.size(), n = grid[0].size();

        // ========================== Dijikstra algorithm =====================================

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        // dist[i][j] = min no of obstactles removed to reach [i][j] cell
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        // pq = {dist, i, j}
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto [currDist, i, j] = pq.top();
            pq.pop();
            // remove the stale entries 
            if(currDist > dist[i][j]) continue;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= m || nj >= n || ni < 0 || nj < 0) continue;

                int newDist = currDist + grid[ni][nj];

                if(newDist < dist[ni][nj]) {
                    pq.push({newDist, ni, nj});
                    dist[ni][nj] = newDist;
                }
            }
        }

        // dist will hold the min obstacles removed to reach [i][j] cell
        return dist[m-1][n-1];
    }
};