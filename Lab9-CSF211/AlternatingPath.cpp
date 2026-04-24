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

// question link: https://codeforces.com/problemset/problem/2204/D

void dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &color, int node, int set, vector<int> &freq, bool &bip) {

    vis[node] = true;
    color[node] = set;
    freq[set]++;

    int nbgSet = (set == 1) ? 2 : 1;

    for(int nbg: adj[node]) {
        if(vis[nbg]) {
            // nbg and node have the same color => not bipartite 
            if(color[node] == color[nbg]) bip = false;

            continue;
        }

        dfs(adj, vis, color, nbg, nbgSet, freq, bip);
    }
}

void solve(int n, vector<vector<int>> &adj) {

    /* since we want to make an alternate path => the component of the graph should be bipartite 
       the ans would be the size of the larger component. Note: Let the bipartite check be complete so the 
       visited array is correctly marked so we dont revisit the same component */ 

    int result = 0;

    vector<bool> vis(n+1, false);
    vector<int> color(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        
        // using dfs check bipartiteness
        vector<int> freq(3, 0); 

        bool bip = true;
        dfs(adj, vis, color, i, 1, freq, bip);
        
        if(bip) {
            // this component is bipartite 
            result += max(freq[1], freq[2]);
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n+1);

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            // u - v
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve(n, adj);
    }
}