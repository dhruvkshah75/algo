#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/505/B

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

void solve(int n, int m, vector<tuple<int,int,int>> &edges) {
    /*
        The best way is using DSU => make a separate DSU instance for each colour
        now for each query just get how many times are nodes connected with edges of only one colour 
        we can have max 1 to 100 colors => DSU for each color
    */
 
    vector<DSU> d(101, n+1);

    for(auto [u, v, color]: edges) {
        // connect u -> v in the DSU for that color 
        d[color].unite(u, v);
    }


    // proccess the queries 
    int q;
    cin >> q;

    while(q--) {
        int u, v;
        cin >> u >> v;

        int cnt = 0;
        // now count the number of colors through which u and v are connected 
        for(int i = 1; i <= 100; i++) {
            if(d[i].find(u) == d[i].find(v)) 
                cnt++;
        }

        cout << cnt << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges(m);

    for(auto &[u, v, c]: edges) 
        cin >> u >> v >> c;

    solve(n, m, edges);
    
}