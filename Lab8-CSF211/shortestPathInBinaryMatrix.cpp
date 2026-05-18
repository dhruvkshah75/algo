#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// Simple bfs question with logic of distance array rather than visited array (logic from Dijikstra algorithm)

class Solution {
private:   
    vector<pair<int,int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // the start and the end cell should be 0
        if(grid[0][0] == 1) return -1;
        else if(grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // simple bfs is okay as we dont necessarily have any weights 
        queue<tuple<int,int,int>> q;

        q.push({1, 0, 0});
        dist[0][0] = 1;

        while(!q.empty()) {
            auto [length, i, j] = q.front();
            q.pop();

            if(i == n-1 && j == n-1) return length;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= n || ni < 0 || nj < 0) continue;

                if(grid[ni][nj] == 0 && length+1 < dist[ni][nj]) {
                    q.push({length+1, ni, nj});
                    dist[ni][nj] = length+1;
                }
            }
        }
        return -1;
    }
};