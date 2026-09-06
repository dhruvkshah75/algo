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

// question link: https://codeforces.com/problemset/problem/1213/G

// DSU + Offline and Sortings 

ll nC2(int n) {
    if(n < 2) return 0;
    return (((ll)n * (n - 1)) / 2);
}

struct DSU {
    vector<int> parent, size;
    ll total_pairs;   // we calculate the total pairs formed whiling merging in the DSU itself 

    DSU(int n) : parent(n), size(n, 1), total_pairs(0) {
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

        total_pairs = total_pairs - (nC2(size[pu])  + nC2(size[pv]));
            
        if(size[pu] < size[pv]) swap(pu, pv); 
        parent[pv] = pu;
        size[pu] += size[pv];

        // first remove the non merged pairs => add the merged size into total pairs 
        total_pairs += nC2(size[pu]);
    }
};

struct Edge { int u, v, w; };

void solve(int n, int m, vector<Edge> &edges) {
    
    vector<pii> queries(m);
    // store the index of it so we can the print the answer in correct order 
    for(int i = 0; i < m; i++) {
        int x; 
        cin >> x;
        queries[i] = {x, i};
    }

    sort(all(queries));

    /* Since we have all the queries in advance we can sort them so we can process them from smallest to biggest 
       we also sort the edges on their wieghts and then we process the queries one by one and then we connect those 
       edges whose weight is less than q[i] 
       The number of components whose size > 1 we do nC2 for them to get the number of pairs 
       We update the total_pairs each time we merge a component in the DSU in O(1) time */

    sort(all(edges), [&](const Edge &a, const Edge &b){ return a.w < b.w; });

    vector<ll> result(m, 0);
    DSU d(n+1);

    int j = 0;  // ptr for traversing the edges 
    
    for(auto [q, idx]: queries) {
        
        while(j < n-1 && edges[j].w <= q) {
            // build the connection of edges whose weight <= w
            d.merge(edges[j].u, edges[j].v);
            j++;
        }

        result[idx] = d.total_pairs;
    }
    // O(N)

    // now print the result 
    for(ll val: result) 
        cout << val << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(n-1);

    for(int i = 0; i < n-1; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    solve(n, m, edges);
}