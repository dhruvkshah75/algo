#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/580/C

void dfs(vector<vector<int>> &adjL, vector<bool> &visited, unordered_set<int> &catLoc, 
    int m, int node, int cntCats, int &result) {
    
    visited[node] = true;
    
    if(catLoc.find(node) != catLoc.end()) cntCats++;
    else cntCats = 0;
    // if m consecutive cats appear then we can go further 
    if(cntCats == m + 1) return;

    int unvisitedNodes = 0;

    for(int nbg: adjL[node]) {
        if(!visited[nbg]) {
            unvisitedNodes++;
            dfs(adjL, visited, catLoc, m, nbg, cntCats, result);
        }
    }

    // if the current node has no further children to go onto => leaf node
    // leaf node => is the one for which dfs is not called for any of its neighbours 
    if(unvisitedNodes == 0) {
        result++;
    }
}

void solve(int n, int m, vector<pair<int,int>> &edges, unordered_set<int> &catLoc) {

    vector<vector<int>> adjL(n+1);

    for(int i = 0; i+1 < n; i++) {
        auto [a, b] = edges[i];
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    // leaf node is the one whose adjL contains only 1 node (the parent)
    vector<bool> visited(n+1, false);

    int result = 0;
    // we start dfs from node 1 
    dfs(adjL, visited, catLoc, m, 1, 0, result);

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // n is number of vertices and m is max consecutive cats that are allowed 
    int n, m;
    cin >> n >> m;

    unordered_set<int> catLoc;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x) catLoc.insert(i);
    }

    vector<pair<int,int>> edges(n-1);

    for(int i = 0; i + 1 < n; i++) 
        cin >> edges[i].first >> edges[i].second;

    solve(n, m, edges, catLoc);
}