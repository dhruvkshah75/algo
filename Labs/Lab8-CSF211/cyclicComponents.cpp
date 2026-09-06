#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/977/E

// cycle detection dfs
bool dfs(vector<vector<int>> &adjL, vector<bool> &visited, const pair<int,int> &node) {
    
    auto [curr, parent] = node;
    visited[curr] = true;

    // the currentNode must have degree 2 
    if(adjL[curr].size() != 2)
        return false;

    for(int nbg: adjL[curr]) {
        // cycle detected => cycle has some modifications 
        if(visited[nbg] && nbg != parent && adjL[nbg].size() == 2)
            return true;
        else if(!visited[nbg])
            if(dfs(adjL, visited, {nbg, curr})) return true;  
    }

    // dfs completetd and no node detected 
    return false;
}

void solve(int n, vector<pair<int,int>> &edges) {
    int m = edges.size();

    // prepare the adjacency list 
    vector<vector<int>> adjL(n+1);

    for(int i=0; i<m; i++) {
        auto [a, b] = edges[i];
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    vector<bool> visited(n+1, false);

    int result = 0;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            // starting node has no parent 
            if(dfs(adjL, visited, {i, -1})) 
                result++;
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // n => no of vertices, m => no of edges 
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> edges(m);

    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    solve(n, edges);
}