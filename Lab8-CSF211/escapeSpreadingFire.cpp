#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/escape-the-spreading-fire/description/

// VERY IMPORTANT QUESTION => apply binary search on answer 
class Solution {
private:
    vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool canReachHome(vector<vector<int>> temp) {
        int m = temp.size(), n = temp[0].size();
        
        // Use two queues to strictly separate Person moves and Fire moves per minute
        queue<pair<int, int>> personQ, fireQ;

        // Initialize person
        if(temp[0][0] == 0) {
            personQ.push({0, 0});
            temp[0][0] = -1; // Use -1 to mark visited by person
        } 
        else return false; // Fire already at start
        

        // Initialize fire
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] == 1) fireQ.push({i, j});
            }
        }

        // we move fire and person level by level
        while (!personQ.empty()) {
            // Person moves first this minute
            int pSize = personQ.size();
            while (pSize--) {
                auto [r, c] = personQ.front();
                personQ.pop();

                // If fire reached this cell before we could move out of it
                if (temp[r][c] == 1) continue; 

                for (auto& d : dirs) {
                    int nr = r + d.first, nc = c + d.second;
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && temp[nr][nc] == 0) {
                        if (nr == m - 1 && nc == n - 1) return true; // Reached safehouse!
                        temp[nr][nc] = -1; // Mark visited
                        personQ.push({nr, nc});
                    }
                }
            }

            // Fire spreads after person moves => spread all the fire by 1 level
            int fSize = fireQ.size(); 
            while(fSize--) {
                auto [r, c] = fireQ.front();
                fireQ.pop();
                for (auto& d : dirs) {
                    int nr = r + d.first, nc = c + d.second;
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && (temp[nr][nc] == 0 || temp[nr][nc] == -1)) {
                        temp[nr][nc] = 1;
                        fireQ.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
    
    bool bfs(vector<vector<int>> &grid, int k) {
        // can the person wait for k minutes and then safely reach 
        int m = grid.size(), n = grid[0].size();
        // first spread fire for k minutes => apply multi source bfs on all fire
        vector<vector<int>> temp = grid;

        // base case when k = 0 minutes start moving the person 
        if(k == 0) return canReachHome(temp);

        queue<tuple<int,int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(temp[i][j] == 1) {
                    q.push({i, j, 0});  // all at the 0th minute (initial fire) or 0th level
                }
            }
        }

        // BFS for K minutes
        while(!q.empty()) {
            auto [i, j, level] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                // if nbg is grass then make it fire and only if less than k minutes have passed
                if(temp[ni][nj] == 0 && level+1 <= k) {
                    temp[ni][nj] = 1;
                    q.push({ni, nj, level+1});
                }
            }
        }

        // now we must check whether the person can reach home or not 
        return canReachHome(temp);

    }

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // binary search on answer => how many minutes can he wait to safely reach the destination
        // predicate bfs returns TTTTTTFFF => return last occurence of 
        int l = 0, r = m*n;        // min minutes = 0 and max minutes is all combinations m*n
        int ans = -1;
        while(l <= r) {
            int mid = (r+l)/2;
            if(bfs(grid, mid)) {
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        }

        if(ans == m*n) return 1e9;
        else return ans;
    }
};