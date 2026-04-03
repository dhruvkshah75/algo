#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;
const int inf = 1e9;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/793/B


// 0 = L, 1 = R, 2 = U, 3 = D
vector<tuple<int,int,int>> dirs = {{1, 0, 3}, {0, 1, 1}, {-1, 0, 2}, {0, -1, 0}};

void solve(int n, int m, vector<string> &grid) {
    
    // dist[i][j][dir] = min turns to reach here moving in dir
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, inf)));

    priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<tuple<int,int,int,int>>> pq;
    // pq = {minTurns, i, j, dir}
    
    // consider the turn => weight = 1 edge and no tunr same dir weight = 0

    // ============================ dijikstra algorithm ========================================
    // Same (i,j), same dir, different k(no of turns) → no, futures are identical, just one has used more turns
   
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(grid[i][j] == 'S') {
                // instead of pushing S push all of its neighbours 
                for(auto [dx, dy, dir]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni >= n || nj >= m || ni < 0 || nj < 0 || grid[ni][nj] == '*') continue;

                    dist[ni][nj][dir] = 0;   // initially we make 0 turns 
                    pq.push({0, ni, nj, dir});
                }
            }

    while(!pq.empty()) {
        auto [currTurns, i, j, currDir] = pq.top();
        pq.pop();

        // remove stale entries => if we already reached this cell with lesser number of turns 
        if(currTurns > dist[i][j][currDir]) continue;
        if(currTurns > 2) continue;

        if(grid[i][j] == 'T') {
            yes;
            return;
        }

        for(auto [dx, dy, nbgDir]: dirs) {
            int ni = i + dx, nj = j + dy;
            if(ni >= n || nj >= m || ni < 0 || nj < 0 || grid[ni][nj] == '*') continue;

            int newTurns = currTurns + ((nbgDir != currDir) ? 1 : 0);

            if(newTurns <= 2 && newTurns < dist[ni][nj][nbgDir]) {
                dist[ni][nj][nbgDir] = newTurns;
                pq.push({newTurns, ni, nj, nbgDir});
            }
        }
    }

    no;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

        int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for(int i = 0; i < n; i++) 
        cin >> grid[i];
    
    solve(n, m, grid);

}