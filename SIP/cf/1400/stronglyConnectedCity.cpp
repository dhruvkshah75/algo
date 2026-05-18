#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/475/B

vector<tuple<int,int,char>> dirs = {{1, 0, 'v'}, {0, 1, '>'}, {0, -1, '<'}, {-1, 0, '^'}};

void solve(int n, int m, string row, string col) {
    // apply bfs for each city => brute force 

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // apply bfs with [i][j] as start 
            vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));

            queue<pair<int,int>> q;
            q.push({i, j});
            vis[i][j] = true;

            // BFS 
            while(!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                for(auto [dx, dy, dir]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni < 1 || nj < 1 || ni > n || nj > m || vis[ni][nj]) continue;

                    // now check for all cases 
                    if(nj == j && dir == col[j-1]) {
                        // vertical movement 
                        q.push({ni, nj});
                        vis[ni][nj] = true;
                    }
                    else if(ni == i && dir == row[i-1]) {
                        // horizontal movement 
                        q.push({ni, nj});
                        vis[ni][nj] = true;
                    }
                }
            }

            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(!vis[i][j]) {
                        no; return;
                    }
                }
            }
        }
    }

    yes;
}       

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // n rows and m columns 

    string rowRoads, colRoads;
    cin >> rowRoads >> colRoads;

    solve(n, m, rowRoads, colRoads);
}