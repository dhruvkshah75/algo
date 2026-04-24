#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef tuple<int,int,int> ti;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/contest/1184/problem/E1

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n), size(n, 1) {
        iota(all(parent), 0);
    }

    int find(int u) {
        if(parent[u] == u) return u;
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

void solve(int n, int m, ti c1, vector<ti> &edges) {

    /* Question says we must find the Emax(c1) for the first corrider 
       Goal: Squeeze the first edge into the MST so Dalek has to use it 
       apply Kruskal's on all other corridors except c1 and when we get the shortest w that 
       connectes u1 - v1's components then our max_edge increment to c1 could be this edge weight w */

    sort(all(edges));

    DSU d(n+1);

    int max_edge = 1e9;    
    // default value if this edge c1 => u1 - v1 is a bridge then Emax(c1) = 1e9 => belong to every MST 

    auto [w1, u1, v1] = c1;

    for(auto [w, u, v]: edges) {
        d.merge(u, v);


        if(d.find(u1) == d.find(v1)) {
            max_edge = w;    // edge of c1 must be w for this edge to be included in the MST 
            break;
        }
    }

    cout << max_edge << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int u1, v1, w1;
    cin >> u1 >> v1 >> w1;
    // take the input of the first corrider 
    ti c1 = {w1, u1, v1};

    vector<ti> edges(m-1);

    for(auto &[w, u, v]: edges) 
        cin >> u >> v >> w;

    solve(n, m, c1, edges);

}