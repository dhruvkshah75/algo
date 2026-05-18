#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/path-with-minimum-effort/description/

// Standard Dijikstra Algorithm question

class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        // we can apply simple dijikstra 
        // nodes => cells and the edges arebetween two cells whose weights are the abs diff between them 
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        // dist[i][j] = path with minimum effort to reach [i][j] cell
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        
        pq.push({0, 0, 0});   // reach [0][0] takes 0 effort 
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto [currPath, i, j] = pq.top();
            pq.pop();

            // remove the stale entries => where we already have a min path to [i][j]
            if(currPath > dist[i][j]) continue;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                int newPath = max(currPath, abs(heights[i][j] - heights[ni][nj]));

                if(newPath < dist[ni][nj]) {
                    pq.push({newPath, ni, nj});
                    dist[ni][nj] = newPath;
                }
            }
        }

        return dist[m-1][n-1];
    }
};