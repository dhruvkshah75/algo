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

// question link: https://codeforces.com/problemset/problem/1209/D

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
    /* Consider the food items as snacks and guests as edges, so when a guest likes food x, y connect them 
       But only connect if cycle is not formed as this edge (i.e. guest) cannot be taken as other guests already eat that food 
       Use DSU to get the no of edges in a component => size of component - 1 => as each component is a tree */

    DSU d(n+1);

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        // connect these food items by this guest 
        d.merge(x, y);
    }

    int sad_guests = k;
    for(int i = 1; i <= n; i++) {
        if(d.find(i) == i) {
            int happy_guests = d.size[i] - 1;
            sad_guests -= happy_guests;
        }
    }

    cout << sad_guests << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    // n => no of food items and k is the no of guests 

    solve(n, k);
}