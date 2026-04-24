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

// question link: https://codeforces.com/problemset/problem/802/J1

void dfs(vector<vector<pii>> &adj, vector<bool> &vis, int &maxPath, int prevSum, int node) {

    // while visiting this node add the prevSum 
    vis[node] = true;

    for(auto [nbg, w]: adj[node]) {
        if(vis[nbg]) continue;

        int newSum = prevSum + w;
        maxPath = max(maxPath, newSum);

        dfs(adj, vis, maxPath, newSum, nbg);
    }
} 

void solve(int n, vector<vector<pii>> &adj) {
    /* Find the path with maximum sum starting from node 0 => Jenny 
    */

    int result = 0;
    vector<bool> vis(n, false);

    // start with the prevSum as 0 and starting node as 0 
    dfs(adj, vis, result, 0, 0);

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pii>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        // u -- v
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    solve(n, adj);
}