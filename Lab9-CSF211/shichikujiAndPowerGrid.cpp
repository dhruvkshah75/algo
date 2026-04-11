#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1245/D
// VERY IMPORTANT Question on MST 

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

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];

        return true;
    }
};

void solve(int n, vector<pair<int,int>> &city, vector<int> &c, vector<int> &k) {

    // create a virtual node 0 which is connected to all the cities (virtual node indicates power station)
    // so if a station is connected to the node 0 it means that there is a power source there 
    // Kruskal's algorithm will decide which edge to take in mst 

    vector<tuple<ll,int,int>> edges;
    // edges = {wt, node1, node2} => node1 ---> node2 

    // first make connections with the virtual node 
    // weight of city i with virtual node 0 is the cost to build power station at city i 

    for(int i = 1; i <= n; i++) {
        edges.push_back({c[i], 0, i});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            ll wt = (k[i] + k[j]) * 1LL * (abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second));
            edges.push_back({wt, i, j});
        }
    }

    DSU d(n+1);
    // nodes => 0 to n

    vector<int> pBuild;
    ll minWtSum = 0;
    vector<pair<int,int>> connections;

    sort(edges.begin(), edges.end());
    // sort on the basis of edge weight 

    for(auto &[wt, u, v]: edges) {
        if(d.unite(u, v)) {
            minWtSum += wt;

            if(u == 0 || v == 0) {
                int city = (u == 0) ? v : u;
                pBuild.push_back(city);
            } 
            else {
                connections.push_back({u, v});
            }
        }
    }

    // print the results
    cout << minWtSum << endl;

    cout << pBuild.size() << endl;

    for(int city: pBuild) 
        cout << city << " ";
    cout << endl;

    cout << connections.size() << endl;

    for(auto [u, v]: connections) 
        cout << u << " " << v << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> city(n+1);

    for(int i = 1; i <= n; i++) 
        cin >> city[i].first >> city[i].second;

    vector<int> costPower(n+1), costWire(n+1);

    for(int i = 1; i <= n; i++) 
        cin >> costPower[i];

    for(int i = 1; i <= n; i++) 
        cin >> costWire[i];

    solve(n, city, costPower, costWire);
}