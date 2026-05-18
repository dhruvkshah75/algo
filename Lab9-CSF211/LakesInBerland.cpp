#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/contest/723/problem/D

vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct DSU {
    vector<int> parent, size;
    vector<bool> isLake;

    DSU(int n) : parent(n, -1), size(n, 1), isLake(n, true) {}

    int find(int u) {
        if(parent[u] == -1) return -1;
        if(parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv || pu == -1 || pv == -1) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        // isLake of pu will depend on pv => if both are lake then combining them it will be also a lake 
        isLake[pu] = isLake[pu] && isLake[pv];
    }
};

void solve(int n, int m, int k, vector<string> &grid) {
    // apply dsu to get the number of lakes and then convert the smallest sized lakes to land 

    // initially keep all the cells locked only unlock (parent[i] == i) those which form a lake 
    DSU d(n*m);
    // check if the given water is lake or not and if not then mark them as non lakes in a map 

    // unlock all the water cells and keep the land cells locked and mark the border cells as false
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*') continue;

            int node = i * m + j;
            // unlock this cell
            d.parent[node] = node;
            // mark the border cell as not lake 
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                d.isLake[node] = false;
            }
        }
    }

  
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*') continue;
            
            int node = i * m + j;

            for(auto [dx, dy]: dirs) {
                int ni = i + dx, nj = j + dy;
                if(ni >= n || nj >= m || ni < 0 || nj < 0) continue;

                // connect this node to its neighbour only if it water 
                if(grid[ni][nj] != '*') {
                    int nbg = ni * m + nj;
                    d.unite(node, nbg);
                }
            }
        }
    }

    vector<pair<int,int>> lakes;
    unordered_set<int> seen;

    // now we know what cells are lakes and what are not => store the lakes on the basis of their size 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*') continue;

            int node = i * m + j;
            int pNode = d.find(node);

            if(pNode != -1 && d.isLake[pNode] && !seen.count(pNode)) {
                lakes.push_back({d.size[pNode], pNode});
                seen.insert(pNode);
            } 
        }
    }

    // sort the lakes on their sizes => we remove smallest 
    sort(lakes.begin(), lakes.end());

    // convert smallest lakes.size() - k elements in land 
    unordered_set<int> toConvert;
    
    for(int i = 0; i < (int)lakes.size() - k; i++) {
        toConvert.insert(lakes[i].second);
    }

    int count = 0;
    // convert cells into land whose parent belongs to toConvert set 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*') continue;

            int node = i * m + j;

            if(toConvert.find(d.find(node)) != toConvert.end()) {
                grid[i][j] = '*';
                count++;
            }
        }
    }   

    // count = number of cells that are connected 
    cout << count << endl;

    for(int i = 0; i < n; i++) {
        cout << grid[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // n * m grid and k = lakes we want 
    vector<string> grid(n);

    for(int i = 0; i < n; i++)
        cin >> grid[i];

    solve(n, m, k, grid);
}