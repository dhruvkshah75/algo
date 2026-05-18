#include<bits/stdc++.h>
using namespace std;

// question link: https://takeuforward.org/plus/dsa/problems/detect-a-cycle-in-an-undirected-graph


// ====================================== BFS ===========================================

// CYCLE DETECTION IN UNDIRECTED GRAPH USING BFS
/*
    We must take care in undirected graphs as they can return true for all cases 
    edge a->b and edge a<-b
    The "Path Back Home": Moving from Node A to Node B, then seeing Node A again from Node B. 
    This is just the same edge viewed from the other side.
*/

bool bfs(vector<vector<int>> &adjL, vector<bool> &visited, int n, int start) {
    // we apply bfs starting from start node 

    // Queue holds {currentNode, parentNode}
    queue<pair<int,int>> q;

    q.push({start, -1});    // starting node has no parent
    visited[start] = true;

    // BFS 
    while(!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for(int nbg: adjL[node]) {
            if(!visited[nbg]) {
                // nbg's parent is currNode
                q.push({nbg, node});
                visited[nbg] = true;                
            }
            else if(visited[nbg] && nbg != parent) {
                // if the nbg is already visited and is not the parent of the curr node then there exists a cycle 
                return true;
            }
        }
    }

    return false;
}

bool isCycle(vector<vector<int>> &adjL, int n) {
    // n vertices => 0 to n-1

    vector<bool> visited(n, false);

    // run bfs on all non visited nodes as there might be some nodes that are not visited
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(bfs(adjL, visited, n, i)) {
                return true;
            }
        }
    }

    return false;
} 


// =================================== DFS ======================================================

bool dfs(vector<vector<int>>&adjL, vector<bool>&visited, const pair<int,int> &node) {

    auto [currNode, parent] = node;

    // mark the current node as marked 
    visited[currNode] = true;

    for(int nbg: adjL[currNode]) {
        // if we already visited the nbg of currnode and it is not the parent then cycle detected 
        if(visited[nbg] && parent != nbg){
            return true;
        }
        else if(!visited[nbg]) {
            if(dfs(adjL, visited, {nbg, currNode}))
                return true;
        }
    }

    return false;
}

bool hasCycle(vector<vector<int>> &adjL, int n) {
    // n vertices => 0 to n-1
    vector<bool> visited(n, false);

    // we call the dfs function for all the unvisited nodes as there may be multiple connected components 

    // we must keep a track of parent and currentNode => 
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(adjL, visited, {i, -1})) return true;
        }
    }

    return false;
}