#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/1365/D

vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve(int n, int m, vector<string> &grid) {
    
    /* If no Good People => then always yes as we can block the exit so bad cant escape 
       block out all the bad B by making walls around them and then run bfs from exit and see if each G is reached or not 
       If a B is directly in contact with G => then no as we can block them from meeting */

    int cntG = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'G') cntG++;

            if(grid[i][j] != 'B') continue;

            // block the B with walls on all four sides 
            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= m || ni < 0 || nj < 0) continue;

                if(grid[ni][nj] == 'G') {
                    no; return;
                }
                else if(grid[ni][nj] == '.') {
                    // block the empty cell 
                    grid[ni][nj] = '#';  
                }
            }
        }
    }

    if(cntG == 0) {
        // no good people then always yes as we can block the exit 
        yes; return;
    }

    // if there G and the exit is blocked beacuse of B then no
    if(grid[n-1][m-1] == '#') {
        no; return;
    }

    // now apply bfs from exit and see if G are reachable or not and if a B is reachable then return no 
    queue<pii> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    q.push({n-1, m-1});
    vis[n-1][m-1] = true;

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for(auto [dx, dy]: dirs) {
            int ni = i + dx, nj = j + dy;
            if(ni >= n || nj >= m || ni < 0 || nj < 0 || vis[ni][nj]) continue;

            if(grid[ni][nj] != '#') {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }

    // final check if all G were reachable and B were not 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((grid[i][j] == 'B' && vis[i][j]) || (grid[i][j] == 'G' && !vis[i][j])) {
                no; return;
            }
        }
    }

    yes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);

        for(string &str: grid) 
            cin >> str;

        solve(n, m, grid);
    }
}