// EASY VERSION 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/contest/2183/problem/D1

int bfs(vector<vector<int>> &adjL, vector<bool> &visited, vector<int> &level) {
    int heightTree = 1;

    queue<pair<int,int>> q;
    // q = {node, level} 
    q.push({1, 0});
    visited[1] = true;

    while(!q.empty()) {
        auto [node, nodeLevel] = q.front();
        q.pop();

        level[nodeLevel]++;
        heightTree = max(heightTree, nodeLevel);

        for(int nbg: adjL[node]) {
            if(!visited[nbg]) {
                q.push({nbg, nodeLevel + 1});
                visited[nbg] = true;
            }
        }
    }
    return heightTree;
}

void solve(vector<pair<int,int>> &edges, int n) {
    // make the adjacency list 
    vector<vector<int>> adjL(n+1);

    for(int i = 0; i+1 < n; i++) {
        auto [a, b] = edges[i];
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    // level[i] = no of nodes that ith level
    vector<int> level(n, 0);
    vector<bool> visited(n+1, false);

    int heightTree = bfs(adjL, visited, level);
    
    // Result => ans = max(maxLevel, children+1) => children = adjL[node].size()-1 for non root 
    int ans = 0;
    // children + 1 — the node + its just next children => node + direct children also need unique moves to color 

    for(int i = 0; i <= heightTree; i++) {
        ans = max(ans, level[i]);
    }

    // for root the number of children is degree as there is no parent
    for(int i = 1; i <= n; i++) {
        if(i == 1) ans = max(ans, (int)adjL[i].size() + 1);
        else ans = max(ans, (int)adjL[i].size());
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        // number of nodes from 1 to n
        int n;
        cin >> n;

        vector<pair<int,int>> edges(n-1);

        for(int i = 0; i+1 < n; i++) 
            cin >> edges[i].first >> edges[i].second;

        solve(edges, n);
    }
}