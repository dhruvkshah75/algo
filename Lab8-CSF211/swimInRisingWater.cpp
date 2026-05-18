#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/swim-in-rising-water/description/

/*
    This question is also a simple implementation of Dijikstra Algorithm 
    each cell is a node and the value of the cell is the weight of it with its neighbour 
*/


// can be solved using 2 methods => binary search on answer then bfs and dijikstra algorithm

// ==========================================================================================
//                      Solution using Dijikstra Algorithm
// ==========================================================================================

class Solution1 {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // consider each cell as a node and edge between them as value of the cell as weights 

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        while(!pq.empty()) {
            auto [currDist, i, j] = pq.top();
            pq.pop();
            // remove the stale entries => if we already have a better way to reach current node
            if(currDist > dist[i][j]) continue;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= n || ni < 0 || nj < 0) continue;

                // we can go the nbg if max of them time has passed 
                int newDist = max(dist[i][j], grid[ni][nj]);

                if(newDist < dist[ni][nj]) {
                    pq.push({newDist, ni, nj});
                    dist[ni][nj] = newDist;
                }
            }
        }

        return dist[n-1][n-1];
    }
};


// ====================================================================================
//                     Solution using Binary search and BFS 
// ====================================================================================
/*
    Here the binary search is on answer 
    Can we sim from [0][0] and reach [n-1][n-1] in T minutes so we can apply bfs for this binary search 
*/
class Solution2 {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool bfs(vector<vector<int>> &grid, int T) {
        int n = grid.size();

        // apply bfs from [0][0] and return true if we can reach the end within T minutes 
        queue<tuple<int,int,int>> q;

        vector<vector<int>> visited(n, vector<int>(n, INT_MAX));
        // the visited[i][j] holds the best time taken to reach [i][j] cell

        if(grid[0][0] <= T) {
            q.push({grid[0][0], 0, 0});
            visited[0][0] = grid[0][0];
        }

        while(!q.empty()) {
            auto [currTime, i, j] = q.front();
            q.pop();

            if(i == n-1 && j == n-1 && currTime <= T) return true;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= n || ni < 0 || nj < 0) continue;

                int newTime = max(currTime, grid[ni][nj]);

                if(newTime < visited[ni][nj] && newTime <= T) {
                    q.push({newTime, ni, nj});
                    visited[ni][nj] = newTime;
                }     
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();

        const int maxWater = n*n;
        
        // predicate function returns FFFFFFTTTTT => we need to find the last ooccurrence of True 
        int l = 0, r = maxWater;
        int T = maxWater;
        while(l <= r) {
            int mid = (l+r)/2;
            if(bfs(grid, mid)) {
                r = mid-1;
                T = mid;
            }
            else l = mid+1;
        }

        return T;
    }
};