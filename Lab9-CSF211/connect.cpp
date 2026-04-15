#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1130/C

vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if(parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

void dfs(int n, vector<string> &grid, vector<vector<bool>> &vis, DSU &d, int i, int j) {
    if(i >= n || j >= n || i < 0 || j < 0 || grid[i][j] == '1')
        return;

    // mark the node visited 
    vis[i][j] = true;

    for(auto [dx, dy]: dirs) {
        int ni = i + dx, nj = j + dy;
        if(ni >= n || nj >= n || ni < 0 || nj < 0 || vis[ni][nj] || grid[ni][nj] == '1') continue;

        int u = ni * n + nj, v = i * n + j;
        d.unite(u, v);

        dfs(n, grid, vis, d, ni, nj);
    }
}

// [r1][c1] = start, [r2][c2] = end ==> 0 indexed 

void solve(int n, int r1, int c1, int r2, int c2, vector<string> &grid) {
    // use dsu to store the connected components of land in dsu 
    // and then if parent of start and end is same then cost is 0 and then find cost between each of them 

    // for dsu flatten the 2d grid => i * n + j
    DSU d(n*n);

    // run dfs to connect the land nodes 
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1' || vis[i][j]) continue;

            dfs(n, grid, vis, d, i, j);
        }
    }

    int pStart = d.find(r1 * n + c1), pEnd = d.find(r2 * n + c2);

    if(pStart == pEnd) {
        // start and end in the same component 
        cout << 0 << endl;
        return;
    }

    // now calculate the min cost for building a tunnel 
    int minCost = INT_MAX;

    // outer loop i for pStart and inner loop j for pEnd

    for(int i = 0; i < (int)d.parent.size(); i++) {
        if(d.find(i) != pStart || grid[i/n][i%n] == '1') 
            continue;
        
        for(int j = 0; j < (int)d.parent.size(); j++) {
            if(d.find(j) != pEnd || grid[j/n][j%n] == '1') 
                continue;

            int row1 = i / n, col1 = i % n;
            int row2 = j / n, col2 = j % n;

            int cost = (row1 - row2) * (row1 - row2) + (col1 - col2) * (col1 - col2);

            minCost = min(cost, minCost);
        }
    }

    cout << minCost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int r1, c1, r2, c2;

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--; c1--; r2--; c2--;
    // convert to 0 indexed 

    vector<string> grid(n);

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    solve(n, r1, c1, r2, c2, grid);
}