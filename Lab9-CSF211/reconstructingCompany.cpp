#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()

// question link: https://codeforces.com/problemset/problem/566/D

struct DSU {
    vector<int> parent, nxt, size;
    // nxt => fast forwarding indices 
    // using two DSUs to keep track 

    DSU(int n) : parent(n), nxt(n+1), size(n, 1) {
        iota(all(parent), 0);
        iota(all(nxt), 0);  
    }

    int find(int u) {
        if(parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // for merging x, x+1, ... y => same as finding parent 
    int find_nxt(int i) {
        if(nxt[i] != i) 
            nxt[i] = find_nxt(nxt[i]);   // path compression 
        return nxt[i];
    }

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }

};

void solve(int n, int q) {
    // we use next array to do the type 2 faster => we use the logic of path compression for this query   
    // nxt[i] = i => initially at the start 

    DSU d(n+1);

    while(q--) {
        int type, x, y;
        cin >> type >> x >> y;

        if(type == 1) {
            d.merge(x, y);
        }
        else if(type == 2) {
            // we use the logic of path compression on nxt array and then merge
            // we must merge(x, x+1), merge(x+1, x+2), .... merge(y-1, y)
            // nxt creates a highway between those connected 
            
            for(int i = d.find_nxt(x); i < y; ) {
                // merge the two adjacent 
                d.merge(i, i + 1);

                d.nxt[i] = d.find_nxt(i+1);
                i = d.find_nxt(i+1);  // find the nxt pointed to by i+1 (like the ultimate parent of i+1)
            }
        }
        else {
            // type = 3 
            if(d.find(x) == d.find(y)) { yes; }
            else { no; }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    solve(n, q);
}