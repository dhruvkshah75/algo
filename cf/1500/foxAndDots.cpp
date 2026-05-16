#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/510/B

vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(vector<string> &grid, vector<vector<bool>> &vis, pii node, pii parent) {

    int n = grid.size(), m = grid[0].size();

    auto [i, j] = node;
    auto [pi, pj] = parent;

    vis[i][j] = true;

    for(auto [dx, dy]: dirs) {
        int ni = i + dx, nj = j + dy;
        if(ni >= n || nj >= m || ni < 0 || nj < 0) continue;

        // colors of adjacent nodes must always have same color 
        if(vis[ni][nj] && grid[ni][nj] == grid[i][j]) {
            // if this node is visited and not its parent then found a cylce => number of nodes >= 4 (guaranteed)
            if(ni != pi && nj != pj) return true;
        }
        else if(grid[ni][nj] == grid[i][j]) {
            // only call dfs for the same color 
            if(dfs(grid, vis, {ni, nj}, {i, j})) { 
                return true;
            }
        }
    }

    return false;
}

void solve(int n, int m, vector<string> &grid) {
    
    // simple cycle detection using bfs 
    vector<vector<bool>> vis(n, vector<bool>(m, false));   

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            
            // for cycle tracking with dfs => always keep a track of parent 
            if(dfs(grid, vis, {i, j}, {-1, -1})) {
                yes; return;
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

    for(string &s: grid) 
        cin >> s;

    solve(n, m, grid);
}