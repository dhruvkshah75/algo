#include <bits/stdc++.h>
using namespace std;

// Simple BFS DFS traversal question 

int minReorder(int n, vector<vector<int>>& connections) {
    // connections.length = n-1
    int m = connections.size();
    // assume the graph as undirected and then apply bfs traversal annd add those edges which were in the wrong dir 
    
    // build the undirected graph 
    vector<vector<pair<int,int>>> adjL(n);
    // adjL[u][i] = {v, direction} => store the actual direction 

    // [u, v] => dir = 0 means u->v and 1 means v->u 
    for(int i = 0; i < m; i++) {
        int u = connections[i][0], v = connections[i][1];
        adjL[u].push_back({v, 0});  // stored in the correct direction
        adjL[v].push_back({u, 1});  // stored in the reverse direction
    }

    // BFS 
    queue<int> q;
    vector<bool> vis(n, false);
    
    q.push(0);
    vis[0] = true;

    int count = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto [nbg, dir]: adjL[node]) {
            if(vis[nbg]) continue;

            q.push(nbg);
            vis[nbg] = true;
            // [u, v] => u->v means dir = 0 but we want the opposite we want everything to point towards u = 0
            if(dir == 0) count++;
        }
    }

    return count;
}
