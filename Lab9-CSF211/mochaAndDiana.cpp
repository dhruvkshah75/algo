#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1559/D1

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
        if(pu == pv) return; // cycle detected 

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }

    bool connected(int u, int v) {
        return (find(u) == find(v)); 
    }
};


void solve(int n, vector<pair<int,int>> &e1, vector<pair<int,int>> &e2) {
    int m1 = e1.size(), m2 = e2.size();

    DSU d1(n+1), d2(n+1);
    // d1 denotes mocha's forest and d2 denotes diana's forest

    for(auto [u, v]: e1) 
        d1.unite(u, v);
    
    for(auto [u, v]: e2) 
        d2.unite(u, v);


    // O(N^2) try adding edges between all nodes 
    vector<pair<int,int>> addedEdges;

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            // try adding edges between node i and node j 
            if(!d1.connected(i, j) && !d2.connected(i, j)) {
                // no cycle is formed then we can add this edge => and then add edge to it 
                d1.unite(i, j);
                d2.unite(i, j);
                addedEdges.push_back({i, j});
            }
        }
    }

    cout << addedEdges.size() << endl;

    for(auto [u, v]: addedEdges) 
        cout << u << " " << v << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    // m1 => edges in mocha's forest, m2 => edges in diana's forest 
    vector<pair<int,int>> e1(m1);
    for(auto &[u, v]: e1)
        cin >> u >> v;

    vector<pair<int,int>> e2(m2);
    for(auto &[u, v]: e2) 
        cin >> u >> v;
    
    solve(n, e1, e2);
}