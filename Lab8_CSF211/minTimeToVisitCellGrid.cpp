#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/

/*
    IMPORTANT QUESTION as we use dijikstra with waiting logic here 

    in every turn we must visit a cell if time >= grid value we can even go back the cells we came for if there 
    so we add waiting logic => jumping back and forth 
*/

class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int minimumTime(vector<vector<int>>& grid) {
        // djikstra algorithm where the weights are the time to visit the cell 
        int m = grid.size(), n = grid[0].size();

        // base case => if either step is not 1 then cant go 
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1; 

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        // pq = {minTime, i, j}
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto [time, i, j] = pq.top();
            pq.pop();

            // remove stale entries => we already had a better path to reach this entry
            if(time > dist[i][j]) continue;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                int newTime = time + 1;
                if(newTime < grid[ni][nj]) {
                    // if we cannot visit this cell we can jump to previous cells and come back here so time has passed 
                    int diff = grid[ni][nj] - newTime;
                    newTime = grid[ni][nj] + ((diff % 2 == 0) ? 0 : 1);
                }
                // visit the nearby cells if the time >= cell value and if we found a better way to reach this cell
                if(newTime >= grid[ni][nj] && newTime < dist[ni][nj]) {
                    pq.push({newTime, ni, nj});
                    dist[ni][nj] = newTime;
                }
            }
        }

        return (dist[m-1][n-1] == INT_MAX) ? -1 : dist[m-1][n-1];
    }
};