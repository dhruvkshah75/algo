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

// question link: https://codeforces.com/problemset/problem/1433/D

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

void solve(int n, vector<int> &a) {
    // apply brute force and try all connections => O(N^2)
    // Kruskal type approach 

    DSU d(n+1);
    vector<pii> edges;

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            // same gang city should not be adjacent
            if(a[i] != a[j] && d.find(i) != d.find(j)) {
                d.merge(i, j);

                edges.push_back({i, j});

                if(edges.size() == (size_t)(n-1)) 
                    break;
            }
        }
    }
    

    if(edges.size() != (size_t)(n-1)) { no; return; }

    yes;

    for(auto &[u, v]: edges) 
        cout << u << " " << v << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) 
            cin >> a[i];

        solve(n, a);
    }
}