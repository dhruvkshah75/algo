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

// question link: https://codeforces.com/problemset/problem/691/D

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

void solve(int n, int m, vector<int> &p) {
    
    DSU d(n+1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // these positions can be swapped 
        d.merge(u, v);
    }

    unordered_map<int,vector<int>> mp;

    for(int i = 1; i <= n; i++) 
        mp[d.find(i)].push_back(p[i]);

    // now sort these positions 
    for(auto &[parent, v]: mp) 
        sort(all(v));

    // place the numbers to get the lexicographically maximal perm 
    for(int i = 1; i <= n; i++) {
        int parent = d.find(i);
        p[i] = mp[parent].back();
        mp[parent].pop_back();

        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> p(n+1);

    for(int i = 1; i <= n; i++) 
        cin >> p[i];

    solve(n, m, p);
}