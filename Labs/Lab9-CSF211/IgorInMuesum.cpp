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

// question link: https://codeforces.com/problemset/problem/598/D

// DSU + BFS 

vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(int u) {
        if(parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

void solve(int n, int m, int k, vector<string> &grid) {
    
    // we must precompute for each empty cell how many paitings can we see 
    // use DSU to know which empty cell is a part of which component => flatten out the 2d grid 

    DSU d(n * m);

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    unordered_map<int,int> mp;   // mp[pi] = paintings that can be seen in this component

    // ======================= BFS => Precomputation ============================================== 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] || grid[i][j] == '*') continue;

            queue<pii> q;

            q.push({i, j});
            vis[i][j] = true;

            int paintings = 0;

            while(!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                for(auto [dx, dy]: dirs) {
                    int ni = i + dx, nj = j + dy;
                    if(ni >= n || nj >= m || ni < 0 || nj < 0 || vis[ni][nj]) continue;

                    // if the nbg is a wall then we can see a painting 
                    if(grid[ni][nj] == '*') paintings++;
                    else {
                        q.push({ni, nj});
                        vis[ni][nj] = true;

                        d.merge(i * m + j, ni * m + nj);
                    }
                    
                }
            }

            int pi = d.find(i * m + j);
            mp[pi] = paintings;
        }
    }

    // Now proccess the queries in O(1) time 

    while(k--) {
        int x, y;
        cin >> x >> y;
        x--; y--;  // => bring it to 0 based indexing 
        // find the parent of the component of which this cell is a part 
        int p = d.find(x * m + y);

        cout << mp[p] << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);

    for(string &str: grid) 
        cin >> str;

    solve(n, m, k, grid);
}