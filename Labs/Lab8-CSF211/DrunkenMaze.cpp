#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/2041/D

// This question is based on multiple states shortest path

// Direction encoding => 0 = L, 1 = R, 2 = U, 3 = D
vector<tuple<int,int,int>> dirs = {{1, 0, 3}, {0, 1, 1}, {-1, 0, 2}, {0, -1, 0}};

int solve(int n, int m, vector<string> &maze) {
    // here the future stop depends on the step we took in the past => we need 4 states 

    vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(3, INT_MAX))));
    // dist[i][j][dir][k] = min distance to reach [i][j] with k consecutive steps in the direction dir 
    
    queue<tuple<int,int,int,int>> q; 
    // q = {i, j, dir, k} => k is no of consecutive steps in the same dir

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 'S') {
                // instead of pushing S we push all the neigbours with their dir and k = 0
                for(auto [dx, dy, nbgDir]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni < 0 || ni >= n || nj < 0 || nj >= m || maze[ni][nj] == '#') continue;

                    dist[ni][nj][nbgDir][0] = 1;
                    q.push({ni, nj, nbgDir, 0});
                    
                }
            }
        }
    }

    // BFS
    while(!q.empty()) {
        auto [i, j, currDir, k] = q.front();
        int minDist = dist[i][j][currDir][k];
        q.pop();
 
        if(maze[i][j] == 'T') return minDist;

        for(auto [dx, dy, nbgDir]: dirs) {
            int ni = i + dx, nj = j + dy;
            if(ni >= n || nj >= m || ni < 0 || nj < 0 || maze[ni][nj] == '#') continue;

            if(currDir != nbgDir && minDist+1 < dist[ni][nj][nbgDir][0]) {
                // this transition is not the in the same dir the we push the newDist if it is better 
                dist[ni][nj][nbgDir][0] = minDist+1;
                q.push({ni, nj, nbgDir, 0});
            }
            else if(currDir == nbgDir && k+1 < 3 && minDist+1 < dist[ni][nj][currDir][k+1]) {
                // in the same dir we can only move if there are less than 4 consecutive moves 
                dist[ni][nj][currDir][k+1] = minDist+1;
                q.push({ni, nj, currDir, k+1});
            }
            // for k+1 >= 3 we dont push this nbg 
        } 
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);

    for(int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    int distance = solve(n, m, maze);

    cout << distance << endl;
}