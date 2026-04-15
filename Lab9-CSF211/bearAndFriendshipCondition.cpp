#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/771/A

struct DSU {
    vector<int> parent, size;
    vector<ll> edges;
    // edges[pu] denotes the edges in that component with pu as the parent

    DSU(int n) : parent(n), size(n, 1), edges(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if(parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) {
            edges[pu]++;      // cyclic edge is added 
            return;
        }

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        // when pv is connected to pu the all edges of pu + all edges of pv + new edge 
        edges[pu] += edges[pv] + 1;
        size[pu] += size[pv];
    }
};

void solve(int n, int m, vector<pair<int,int>> &e) {
    // connect nodes using dsu and also track the number of edges in each component 
    // for the component to be valid or reasonable it should be a complete graph => n*(n-1)/2 edges 
    DSU d(n+1);

    for(auto [u, v]: e) 
        d.unite(u, v);

    for(int i = 1; i <= n; i++) {
        if(d.find(i) != i) continue; 

        int pi = d.find(i);

        int l = d.size[pi];
        // check if this component has all possible edges 
        if((l * 1LL * (l-1)) / 2 != d.edges[pi]) {
            no;
            return;
        }
    }

    yes;
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