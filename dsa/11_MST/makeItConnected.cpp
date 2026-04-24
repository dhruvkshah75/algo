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
#define allr(x), x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/1095/F

// question on Minimum Spanning Trees => Kruskal's Algorithm

/* Core Logic: 
   Instead of building the entire graph build only those edges which are useful and needed 
   to get the MST we add the special offer edges always and add the edges with a[x] + a[min] for all x */

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

    bool merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

void solve(int n, int m, vector<ll> &a) {
    // instead of building the entire graph => connect the node with min(a) to all other nodes and the special offers 

    auto minIt = min_element(all(a));
    int minIdx = distance(a.begin(), minIt);

    vector<tuple<ll,int,int>> edges;

    for(int i = 1; i <= n; i++) {
        if(i == minIdx) continue;
        edges.push_back({a[i] + a[minIdx], minIdx, i});
    }

    // now create the edges with special offer 
    for(int i = 0; i < m; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;

        edges.push_back({w, x, y});
    }

    // now apply kruskal's algorithm to get the mst 
    DSU d(n+1);
    sort(all(edges));

    ll cost = 0;

    for(auto [w, u, v]: edges) {
        if(d.merge(u, v)) {
            cost += w;
        }
    }

    cout << cost << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n+1);
    a[0] = LLONG_MAX;   // so min element search doesnt go wrong 

    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    solve(n, m, a);
}