#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/making-a-large-island/description/

/*
    VERY IMPORTANT QUESTION 
    Algorithm:
        Instead of trying to flip every 0 to 1 and calculate the best possible area => O(N^4)

        We label all the islands with a unique id and store each islands area 
        now traverse through each 0 and get neighbours of the 0 and calculate the area using the stored areas 

        consider the edge case when no 0 exist to convert to 1 so set maxArea to max island area 
*/


class Solution {
private:
    unordered_map<int,int> islandArea;
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS to mark island nodes with label 
    void bfs(vector<vector<int>> &grid, int i, int j, int label) {
        int n = grid.size();

        int area = 1;

        queue<pair<int,int>> q;
        q.push({i, j});
        // mark the node with its label 
        grid[i][j] = label;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;

                if(grid[ni][nj] == 1) {
                    area++;
                    q.push({ni, nj});
                    grid[ni][nj] = label;
                }
            }
        }

        // now add the area of the island with label into the map
        islandArea[label] = area;
    }

    void labelIslands(vector<vector<int>> &grid) {
        int n = grid.size();

        // mark all the island starting from 2 
        
        int label = 2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    bfs(grid, i, j, label);
                    label++;
                }     
            }
        }
        // now all the islands are marked with a unique label 
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        // first we precompute and mark all the islands with a unique ID so we can convert 0s to 1 

        // we label all the islands are store their sizes in a map and then we convert those 0s which will benefit us the most 
        
        labelIslands(grid);

        // consider the edge case when no 0 exist to convert to 1 so set maxArea to max island area 
        int maxArea = 1;

        for(auto [label, area]: islandArea) {
            maxArea = max(maxArea, area);
        }

        // now we try converting 0 to 1 and check the area 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) continue;

                // store the nbg of current 0
                unordered_set<int> nbg; 

                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;

                    int label = grid[ni][nj];
                    if(label != 0 && nbg.find(label) == nbg.end()) {
                        nbg.insert(label);
                    }  
                }

                int temp_area = 1;
                // now calculate the area 
                for(auto label: nbg) {
                    temp_area += islandArea[label];
                }

                maxArea = max(temp_area, maxArea);
            }
        }

        return maxArea;
    }
};