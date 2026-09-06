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

// question link: https://codeforces.com/problemset/problem/843/A

struct DSU {
    vector<int> parent, size;
    
    DSU(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(int u) {
        if(parent[u] == u) 
            return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

void solve(int n, vector<pii> &a) {
    
    DSU d(n+1);

    vector<pii> s = a;

    sort(s.begin() + 1, s.end());

    // now form the connections of a with s in sorted order 
    for(int i = 1; i <= n; i++) 
        d.merge(s[i].second, a[i].second);

    unordered_map<int,vector<int>> mp;

    for(int i = 1; i <= n; i++) {
        int p = d.find(i);
        mp[p].push_back(i);
    }

    cout << mp.size() << endl;

    for(auto &[p, v]: mp) {
        cout << v.size() << " ";

        for(int x: v) 
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pii> a(n+1);

    for(int i = 1; i <= n; i++) {
        int x;  cin >> x;
        a[i] = {x, i};
    }

    solve(n, a);
}