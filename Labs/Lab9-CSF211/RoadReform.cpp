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

// question link: https://codeforces.com/problemset/problem/1468/J

// MST using Kruskal's algorithm

/*  Logic:
    In this question all the edges (w <= k) below the speed limit are free edges as these dont directly need to change 
    if these edges (w <= k) form a spanning tree then we must just add any one road to the existing graph 
    whose |w - k| is minimum 
    
    If these Free edges (w <= k) couldnt form a spanning tree then we apply Kruskal's algorithm on every larger edge
    (w > k) => sort these edges in ascending order and then add these edges that dont form a cycle
    for each addition we must bring down the edges to exactly k so update the cost 
    cost += (w - k) */

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

    bool merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

void solve(int n, int m, int k) {
    
    /* Speed Limit changes allowed is either increasing the speed count by 1 or decreasing the speed count by 1 
       Apply Kruskal in two phase => apply on all the edges with w <= k then 
       sort the remaining edges (w > k) on their closesnes to k => |w-k| and then bring down the bigger ones if many 
       to k or if no bigger than k then bring up the one (w <= k) largest w to k  */

    DSU d(n+1);

    struct Edge {
        int u, v, w;
    };

    int min_diff = INT_MAX;

    vector<Edge> larger;  
    // store the edges with w <= k and w > k

    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        min_diff = min(min_diff, abs(w-k));

        if(w <= k) {
            // this is a free edge so directly connect in DSU 
            if(d.merge(x, y)) {
                // merge happens but these edges are free of cost so do nothing just update the maxEdge 
            }
        }
        else {
            larger.push_back({x, y, w});
        }
    }   

    // if the tree is complete then just increase the max_edge_below_k
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(d.find(i) == i) {
            cnt++;
            if(cnt > 2) break;
        }
    }

    if(cnt == 1) {
        // already connected graph (components = 1) => adjust the edge which is closest to k 
        cout << min_diff << endl;
        return;
    }

    /* now the larger vector only contains the edges with a weight more than k 
       now see how many need to be connected more to completely connect the graph to form tree 
       for each edge to be connected to form the spanning tree the edge's weight must to brought down to k
    */

    sort(all(larger), [&](const Edge &a, const Edge &b){
        return a.w < b.w; // sort in ascending => closest to k
    });

    ll cost = 0;
    for(auto [u, v, w]: larger) {
        if(d.merge(u, v)) {
            // this edge creation is allowed => no cycle is formed 
            cost += (ll)(w - k);
        }
    }

    cout << cost << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        solve(n, m, k);
    }
}