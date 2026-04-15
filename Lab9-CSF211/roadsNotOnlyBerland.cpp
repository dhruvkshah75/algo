#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/25/D

// Important Question => Easy 

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

void solve(int n, vector<pair<int,int>> &edges) {
    // it will take k-1 days to connect all cities if there are k disconnected components 
    // we close down roads that form a cycle 

    DSU d(n+1);
    // nodes in dsu => cities and roads are edges 

    vector<pair<int,int>> closeRoads;

    for(auto [u, v]: edges) {
        if(!d.unite(u, v)) 
            closeRoads.push_back({u, v});
    }

    // count the number of roads we need to built 
    vector<pair<int,int>> newRoads;
    // important logic to build k-1 roads to connect all the components 
    vector<int> seenNode;
    int roadsNeeded = -1;
    for(int i = 1; i <= n; i++) {
        if(d.find(i) == i) {
            roadsNeeded++;

            if(!seenNode.empty()) {
                int prevNode = seenNode.back();
                seenNode.pop_back();
                newRoads.push_back({prevNode, i});
            }
            
            seenNode.push_back(i);
        }
    }

    if(roadsNeeded == 0) {
        cout << 0 << endl;
        return;
    }

    cout << roadsNeeded << endl;

    for(int j = 0; j < newRoads.size(); j++) {
        cout << closeRoads[j].first << " " << closeRoads[j].second 
            << " " << newRoads[j].first << " " << newRoads[j].second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> edges(n-1);

    for(int i = 0; i < n-1; i++) 
        cin >> edges[i].first >> edges[i].second;

    solve(n, edges);
}