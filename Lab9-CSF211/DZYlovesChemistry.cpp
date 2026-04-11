#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/445/B

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

void solve(int n, int m, vector<pair<int,int>> &chem) {
    // define the dsu and connect the reacting chemicals in one group 
    DSU d(n+1);
    // nodes are the chemicals => 1 to n

    // the best way is to pour is pouring all the reacting chemicals one after the other 

    for(auto [u, v]: chem) 
        d.unite(u, v);

    ll result = 1;

    for(int i = 1; i <= n; i++) {
        if(d.find(i) == i) {
            // only calculate for those that are ultimate parents 
            result = result * (1LL << (ll)(d.size[i]-1));
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; 

    vector<pair<int,int>> chemicals(m);

    for(int i = 0; i < m; i++) {
        cin >> chemicals[i].first >> chemicals[i].second;
    }

    solve(n, m, chemicals);
}