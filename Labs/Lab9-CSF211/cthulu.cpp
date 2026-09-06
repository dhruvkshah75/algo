#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/103/B

// simple cycle detection 

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

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

void solve(int n, int m, vector<pair<int,int>> &edges) {
    // there should be only 1 component and 1 cycle in the graph 

    DSU d(n+1);

    bool cycle = false;
    int cntCycle = 0;

    for(auto [u, v]: edges) {
        if(!d.unite(u, v)) {
            // cycle detected 
            cycle = true;
            cntCycle++;

            if(cntCycle > 1) {
                no; return;
            }
        }
    }

    // now check the number of components 
    if(!cycle) {
        no; return;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(d.find(i) == i) {
            cnt++;

            if(cnt > 1) {
                no; return;
            }
        }
    }

    cout << "FHTAGN!" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> edges(m);

    for(auto &[u, v]: edges) 
        cin >> u >> v;

    solve(n, m, edges);
}