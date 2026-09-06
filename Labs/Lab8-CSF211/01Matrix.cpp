#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/01-matrix/description/
// OR https://leetcode.com/problems/map-of-highest-peak/description/

/*
 * In this question instead of starting from 1s and then searching for 0s 
 * Start from 0s and try to reach 1s so we will have the level (distance from starting point) 
 * stored 
 * Why BFS guarantees shortest distance on first visit
 * Level 0: all 0 cells 
 * Level 1: all 1 cells at distance 1 from a 0
 * Level 2: all 1 cells at distance 2 from a 0
 */

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();

    // we want distance from 1s to 0s 
    // apply bfs on 0s as the starting point 
    vector<vector<int>> result(m, vector<int>(n, 0));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    queue<tuple<int,int,int>> q;
    // q = {x, y, z} => x, y are coordinates and z is the level with respect to start

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 0) {
                q.push({i, j, 0});   // level of 0s is 0 
                visited[i][j] = true;
            }
        }
    }

    vector<pair<int,int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // BFS 
    while(!q.empty()) {
        auto [i, j, level] = q.front();
        q.pop();

        // push the neigbours 
        for(auto [dx, dy]: dirs) {
            int ni = i + dx;
            int nj = j + dy;
            // skip if the coordinate is not valid 
            if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

            if(!visited[ni][nj] && mat[ni][nj] == 1) {
                q.push({ni, nj, level+1});
                result[ni][nj] = level + 1;
                visited[ni][nj] = true;
            }
        }
    }

    return result;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<vector<int>> result = updateMatrix(mat);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}