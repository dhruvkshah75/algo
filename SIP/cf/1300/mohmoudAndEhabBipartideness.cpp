#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define rall(x) x.begin(), x.end()

using pii = pair<int,int>;

// question link: https://codeforces.com/problemset/problem/862/B

void dfs(int curr, int prev, vector<int> &vis, vector<vector<int>> &adjL) {
    // mark the current node in opposite set as that of prev 
    int prevSet = vis[prev];

    vis[curr] = (prevSet == 1) ? 2 : 1;

    for(int nbg: adjL[curr]) {
        if(vis[nbg] == 0) 
            dfs(nbg, curr, vis, adjL);
    }
}

void solve(int n, vector<pii> &edges) {
    // the given graph is bipartite 
    
    vector<int> vis(n+1, 0);
    // 0 means not visisted, 1 means part of set 1 and 2 means part of set 2 

    // given a tree of n-1 edges 

    vector<vector<int>> adjL(n+1);

    for(auto [u, v]: edges) {
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    dfs(1, -1, vis, adjL);

    int cntSet1 = 0, cntSet2 = 0;

    for(int i = 1; i <= n; i++) {
        if(vis[i] == 1) cntSet1++;
        else cntSet2++;
    }
    // we can add edges to make the bipartite graph into a complete bipartite graph 
    cout << cntSet1 * 1LL * cntSet2 - (n-1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pii> edges(n-1);

    for(int i = 0; i < n-1; i++) 
        cin >> edges[i].first >> edges[i].second;

    solve(n, edges);
}