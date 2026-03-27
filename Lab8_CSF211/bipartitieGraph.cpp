#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/is-graph-bipartite/description/

// ===========================================================================
//                      Solution using BFS 
// ===========================================================================

bool isBipartite(vector<vector<int>>& graph) {
    // graph is adjList of the graph 
    int n = graph.size();     // nodes from 0 to n-1

    vector<int> visited(n, 0);       
    // 0 indicates not visited, 1 = nodes are a part of set A, 2 = nodes are a part of set B 

    // BFS on every node as the graph may be disconnected 
    for(int start = 0; start < n; start++) {
        if(visited[start] != 0) continue; 

        queue<int> q;
        q.push(start);
        visited[start] = 1;        // put the starting node in set A 

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            int set = visited[node];

            // all neighbours of node must be either unvisited or be a part of different set than node
            for(int neighbour: graph[node]) {
                if(visited[neighbour] != 0 && visited[neighbour] == set) 
                    return false;
                else if(visited[neighbour] == 0){
                    // neighbor is not visited then put in a different set than node's
                    q.push(neighbour);
                    if(set == 1)
                        visited[neighbour] = 2;
                    else 
                        visited[neighbour] = 1;
                }
            }
        }
    }
    return true;
}


// ===========================================================================
//                      Solution using DFS 
// ===========================================================================
