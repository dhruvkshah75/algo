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

// question link: https://codeforces.com/contest/1249/problem/B2

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

void solve(int n) {
    // we must print the days taken for the ith kid to get his book back => size of the component he is a part of 
    DSU d(n+1);

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        d.merge(x, i);
    }

    for(int i = 1; i <= n; i++) 
        cout << d.size[d.find(i)] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;
        solve(n);
    }
}