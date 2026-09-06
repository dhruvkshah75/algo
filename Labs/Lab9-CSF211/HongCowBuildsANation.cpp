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

// question link: https://codeforces.com/problemset/problem/744/A

struct DSU {
    vector<int> parent, size;
    vector<bool> mark;

    DSU(int n, vector<bool> &mark) : parent(n), size(n, 1), mark(mark) {
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

        mark[pu] = mark[pu] || mark[pv];  // mark that this component has a government 
    }
};

void solve(int n, int m, vector<bool> &gov, vector<pii> &edges) {

    /* At the end there should be exactly K different components in the dsu 
       So connect the non government component to the componet with government with biggest size (greedy solution) 
       And after merging make all the government nodes complete i.e. s*(s-1) / 2 */

    DSU d(n+1, gov);

    for(auto &[u, v]: edges) 
        d.merge(u, v);

    // find the component in which the government exists and it has the max component 
    pii pBest = {-1, INT_MIN};

    for(int i = 1; i <= n; i++) {
        if(d.find(i) == i && d.mark[i]) {
            if(d.size[i] > pBest.second) 
                pBest = {i, d.size[i]};
        }
    }

    // now we connect all the non government components with pBest 

    // just merge the pBest with all non government components
    for(int i = 1; i <= n; i++) { 
        if(d.find(i) == i && !d.mark[i]) {
            int p1 = d.find(pBest.first);
            d.merge(p1, i);
        }
    }

    // now get the the total allowed edges in the component that is make each component a complete graph 
    ll result = -m;      // subtract existing m edges 

    for(int i = 1; i <= n; i++) {
        if(d.find(i) == i && d.mark[i]) {
            // make all the government components into complete graph 
            ll s = d.size[i];
            result += s * (s - 1) / 2;
        }
    }
    
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> gov(n+1, false);

    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        gov[x] = true;
    }

    vector<pii> edges(m);

    for(auto &[u, v]: edges)
        cin >> u >> v;

    solve(n, m, gov, edges);
}