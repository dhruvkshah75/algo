#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/60/B

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

void solve(int K, int N, int M, vector<vector<string>> &plate) {

    /* we must find out the number of empty cells which are in the same component as [x][y]
       to denote a cell => [i][x][y] => val = (i * n * m) + (x * m) + y
       i denotes the ith depth 
       tap is placed on the 0th layer at x, y */

    DSU d(K * N * M);

    auto encode = [&](int k, int n, int m) {
        return (k * N * M) + (n * M) + m;
    };

    // movement is allowed in 6 dirs => 4 usual and 1 up and 1 down 
    vector<tiii> dirs = {{0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}, {1,  0, 0}, {-1, 0, 0}};

    for(int k = 0; k < K; k++) 
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < M; j++) {
                if(plate[k][i][j] == '#') continue;

                for(auto [dk, dx, dy]: dirs) {
                    int nk = k + dk, ni = i + dx, nj = j + dy;
                    if(nk >= K || ni >= N || nj >= M || nk < 0 || ni < 0 || nj < 0) continue;

                    if(plate[nk][ni][nj] == '.') {
                        // connect this nbg empty cell to the current cell 
                        d.merge(encode(nk, ni, nj), encode(k, i, j));
                    }
                }
            }
        
    int x, y;
    cin >> x >> y;
    x--; y--;       // 0 based indexing 

    // tap is placed on a empty cell => [0][x][y]
    int idx = encode(0, x, y);

    cout << d.size[d.find(idx)] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<string>> plate(k, vector<string>(n));
    // plate[k][i][j] = kth rectangle 

    for(int i = 0; i < k; i++) 
        for(int x = 0; x < n; x++)
            cin >> plate[i][x];
            
    solve(k, n, m, plate);
}