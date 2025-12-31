#include<bits/stdc++.h>
using namespace std;

/*
    NOTES: Depth First Search (DFS)
    randomly go in the depth of one of root and then go into the complete depth of it 
    we use a visited array to make sure that infinte loop does not occur 
    size of visited array is no of vertices in the graph or tree

    Given inputs:
    N = 6, M = 9 (6 vertices and 9 edges)
    folowing m lines are the edges 
    1 3 
    1 5 
    3 5
    3 4
    3 6
    3 2
    6 2
    4 6
    5 6

*/

const int N = 1e5;
vector<int> g[N];   // adjacency list method 
vector<bool> visited(N, false);

void dfs(int vertex){
    visited[vertex] = true;
    // Take action on vertex after entering the vertex
    for(int &child: g[vertex]){
        if(visited[child]) continue;
        //Take action on child before entering the child node
        dfs(child);
        // Take action on child after exiting child node 
    }
    // Take action on vertex before exeting the vertex  
}
// Time complexity: O(V + E) where V is the vertices and E are the edges 


int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);
}