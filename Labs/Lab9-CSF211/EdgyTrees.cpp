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

// question link: https://codeforces.com/problemset/problem/1139/C

// Important Question on DSU and Math 

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

void solve(int n, int k) {
    
    /* Total no of sequences are n ^ k and then subtrack all the bad sequences => the one in which no black edge 
       appears => use DSU to build only red edges and then the components => will have only red edges 
       so invalid sequences are s ^ k where s is size of each component */

    DSU d(n+1);

    for(int i = 0; i < n-1; i++) {
        int x, y, color;
        cin >> x >> y >> color;
        // if the edge is red then form the edge in DSU 
        if(color == 0) 
            d.merge(x, y);
    }

    // calculate n ^ k and s ^ k
    auto power = [&](int n, int k) {
        ll result = 1;
        while(k--) 
            result = (result * 1LL * n) % mod;
        
        return result;
    };

    ll ans = power(n, k);

    for(int i = 1; i <= n; i++) {
        if(d.find(i) == i) {
            int s = d.size[i];
            ans = ((ans - power(s, k)) % mod + mod) % mod;
            // + mod to bring the number back in [0, mod)
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    solve(n, k);
}