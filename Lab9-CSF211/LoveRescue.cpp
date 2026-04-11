#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/939/D

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


void solve(int n, string &s1, string &s2) {
    // a = 0 and z = 26 for dsu 
    // we simply want to find which letter is connected to what when we apply spells 
    DSU d(27);

    vector<pair<char,char>> spells;

    int result = 0;

    for(int i = 0; i < n; i++) {
        int c1 = (int)(s1[i] - 'a'), c2 = (int)(s2[i] - 'a');

        if(d.find(c1) == d.find(c2)) continue;
        // if they are not equal create a connection in dsu 
        result++;
        d.unite(c1, c2);
        spells.push_back({s1[i], s2[i]});
    }

    cout << result << endl;
    for(auto [c1, c2]: spells) {
        cout << c1 << " " << c2 << endl;
    }
}
// O(N)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
     
    string s1, s2;
    cin >> s1 >> s2;

    solve(n, s1, s2);
}