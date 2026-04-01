#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/

/*
    With a regular Queue: You are looking at all the surrounding land, 
    but you have no idea which parts are low and which are high. 
    Every time the "water level" (query value) rises, 
    you have to run around the entire boundary and check, "Are you underwater yet? How about you?" 
    This is why your original code was slow—you were checking the same "high" ground over and over again.

    With a Priority Queue: You effectively build a ordered levee. 
    You put all the adjacent cells into the PQ, and it automatically pushes the lowest ground to the very top. 
    When the water level rises, you don't need to check the whole boundary; 
    you only look at the very top of the pile. If that cell is still higher than the water, 
    you know every other cell on the boundary is also higher. You stop immediately
*/

class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(int threshold, priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>& pq, 
                      vector<vector<int>>& grid, vector<vector<bool>>& vis, int& total) {
        
        int m = grid.size(), n = grid[0].size();

        // we use priority queue in order to store them in order (min heap) 
        // so only top queries with smaller values are executed 
        while(!pq.empty() && get<0>(pq.top()) < threshold) {

            auto [val, i, j] = pq.top();
            pq.pop();

            // the node poped is always a valid entry 
            total++;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= n || ni < 0 || nj < 0) continue;
                
                vis[ni][nj] = true;
                // always push in the pq as it is stored on the basis priority 
                pq.push({grid[ni][nj], ni, nj});
            }
        }
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), k = queries.size();

        // Sort queries to ensure we only ever expand outwards
        vector<pair<int,int>> qr;

        for (int i = 0; i < k; i++) 
            qr.push_back({queries[i], i});

        sort(qr.begin(), qr.end());

        vector<int> result(k);
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        // we use a pq
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        int total = 0;

        // Initialize with the top-left cell and put it in waiting 
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        for(int i = 0; i < k; i++) {
            auto [threshold, idx] = qr[i];

            // Avoid redundant work if the query value is the same as the previous one
            if(i > 0 && qr[i].first == qr[i-1].first) {
                result[qr[i].second] = result[qr[i-1].second];
                continue;
            }

            bfs(threshold, pq, grid, vis, total);
            
            result[idx] = total;
        }

        return result;
    }
};