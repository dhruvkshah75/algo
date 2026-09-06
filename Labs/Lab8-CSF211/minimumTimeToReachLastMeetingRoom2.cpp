#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/

typedef long long ll;
// Lab 10 Question PYQ => maze of Amravati 
// Simple Djikstra question With modified weights (different than normal graphs)
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        // first we make a move of 1 sec and then 2 sec and then again 1 sec 
        return dijikstra(moveTime);
    }
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dijikstra(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<tuple<ll,int,int,int>, vector<tuple<ll,int,int,int>>, greater<tuple<ll,int,int,int>>> pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        pq.push({0, 0, 0, 1});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto [currDist, i, j, moveTime] = pq.top();
            pq.pop();

            // remove the stale entries 
            if(currDist > dist[i][j]) continue;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= m || ni < 0 || nj < 0) continue;
                // the next cell only unlocks minDist + moveTime is greater than grid[ni][nj]
                int newTime = (moveTime == 1) ? 2 : 1;
                
                // we can start making move if time becomes grid[ni][nj] and then add the next moveTime 
                int startTime = max(currDist, (ll)grid[ni][nj]);
                int newDist = startTime + moveTime;

                if(newDist < dist[ni][nj]) {
                    dist[ni][nj] = newDist;
                    pq.push({newDist, ni, nj, newTime});
                }
            }
        }

        return dist[n-1][m-1];
    }
};