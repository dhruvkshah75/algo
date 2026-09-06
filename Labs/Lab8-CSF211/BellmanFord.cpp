#include<bits/stdc++.h>
using namespace std;

// =====================================================================================
//                      Bellman Ford Algorithm
// =====================================================================================

/*
    Bellman ford works on negative weights or negative edges => dijkstra fails 
    Bellman Ford also detects negative cycles 

    works on directed graph 
    to implement bellman ford make the indirected graph into a directed graph 

    1. Relax all the edges n-1 times sequentially 
        Relax => if(dist[u] + wt < dist[v]) dist[v] = dist[u] + wt ==> this is called as relaxation of edges 
        we do this N-1 times 

    We relax edges N-1 times 
    Outer loop for Relaxation of N-1 times and the inner loop for each edge 

    Why N-1 relaxations
*/

bool bellmanFord(int n, int startNode, vector<tuple<int,int,int>> &edges) {
    // edges = {u, v, w} 

    vector<int> dist(n, INT_MIN);
    dist[startNode] = 0;

    for(int i = 0; i < n-1; i++) {
        // relax all the edges n-1 times 
        for(int j = 0; j < edges.size(); j++) {
            auto [u, v, w] = edges[j];
            // u->v, weight = w => only relax those edges who is not reached yet 
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // O(V*E)

    bool hasNegativeCycle = false;
    // to detect the negative cycle detection relax the edges for the Nth time => if we are able a relax an edge that means cycle exists 
    for(auto [u, v, w]: edges) {
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            // only N-1 relaxations are needed to get shortest path 
            hasNegativeCycle = true;
            break;
        }
    }

    return hasNegativeCycle;
}


// =============================================================================
//                  Bellman Ford on Undirected graphs 
// =============================================================================
bool BellmanFord(int n, int startNode, vector<tuple<int,int,int>> &edges) {
     
    vector<int> dist(n, INT_MAX);
    dist[startNode] = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < edges.size(); j++) {
            auto [u, v, w] = edges[j];
            // onyl relax those nodes that are reached (dist != INT_MAX)
            // relax u -> v 
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) 
                dist[v] = dist[u] + w;
            
            // relax v -> u
            if(dist[v] != INT_MAX && dist[v] + w < dist[u]) 
                dist[u] = dist[v] + w; 
        }
    }

    // to detect the negative cycle relax edges Nth time 
    for(auto [u, v, w]: edges) {
        if((dist[u] != INT_MAX && dist[u] + w < dist[v]) || (dist[v] != INT_MAX && dist[v] + w < dist[u]))
            return true;
    }

    return false;
}


