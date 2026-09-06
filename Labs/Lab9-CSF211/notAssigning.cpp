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

// question link: https://codeforces.com/problemset/problem/1627/C

void dfs(vector<vector<pii>> &adj, vector<bool> &vis, int node, int prevWt, vector<int> &result) {
    // mark the current node as visited 
    vis[node] = true;

    for(auto [nbg, idx]: adj[node]) {
        if(vis[nbg]) continue;
        // mark the edge with alternating edge 
        if(prevWt == 2) result[idx] = 3;
        else result[idx] = 2;

        int nextWt = (prevWt == 2) ? 3 : 2;

        dfs(adj, vis, nbg, nextWt, result);
    }
}

void solve(int n, vector<pair<pii,int>> &edges) {
    
    /* Note: prime + prime = prime only true when one of the prime is 2 
       2 + p = prime 
       We can assign all the weights as 2 or 3 
       1 important check is that degree of a vertex should not be >= 3 */

    vector<vector<pii>> adj(n+1);

    for(int i = 0; i < edges.size(); i++) {
        auto [e, idx] = edges[i];
        // e1 - e2
        adj[e.first].push_back({e.second, idx});
        adj[e.second].push_back({e.first, idx});
    }

    // check if deg >= 3 then print -1 ==> BASE CHECK (deg < 3)
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() >= 3) {
            cout << -1 << endl;
            return;
        }
    }

    // now assign prime numbers (2 or 3) to the edges 
    vector<bool> vis(n+1, false);
    vector<int> result(edges.size());

    // call dfs on a node with only 1 degree so it correctly assigns alternating 
    // the tree will always have a node with a node with degree = 1 => consider this as root and start dfs from there 
    int root = 1;
    for(int i = 1; i <= n; i++) {
        if(adj[i].size() == 1) { root = i; break; };
    }

    dfs(adj, vis, root, -1, result);

    for(int &val: result) 
        cout << val << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<pii,int>> edges;

        for(int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y;
            // store the index so we can update the ans 
            edges.push_back({{x, y}, i});
        }

        solve(n, edges);
    }
}