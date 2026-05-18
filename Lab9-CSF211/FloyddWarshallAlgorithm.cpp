#include<bits/stdc++.h>
using namespace std;

/*
    ==========================================================================================
                                    Floyd Warshall Algorithm
    ==========================================================================================

    All pairs Shortest path Algorithm 
    O(N^3)

    Go to each node 

    dist[i][j] = min(dist[i][k] + dist[j][k]) over all values of k

    We make D(i) matrix at each ith iteration 
    ith iteration denotes the intermediate nodes => logic is based on dp 

    i -> j ==> i -> interm -> j
    dist[i][j] = min(dist[i][j], dist[i][interm] + dist[interm][j])

    How to detect a negative cycle in this ??
    dist[i][i] => should be 0 (node to itself) 
    if dist[i][i] < 0 =>> then negative cycle exists 

    for(int i = 0; i < n; i++) 
        if(cost[i][i] < 0) 
            negative cycle 


    AdjMat => if not reachable then dist = inf and dist[i][i] = 0
*/

const int inf = 1e9;

void floydWarshal(int n, vector<vector<int>> &adjMat) {
    // n = |V| => 0 to n-1
    // given the adjacency matrix which holds the weight if there is edge otherwise it is inf  

    /* Core triple loop logic:
       k is the intermediate node 
       i is the source vertex
       j is the destination vertex. */

    vector<vector<int>> dist = adjMat;

    // for the 0th iteration => no intermediate nodes 
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == -1) dist[i][j] = inf;
            // node to itself
            if(i == j) dist[i][j] = 0;
        }
    

    for(int k = 0; k < n; k++) 
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                if(dist[i][k] != inf && dist[k][j] != inf) 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    
    for(int i = 0; i < n; i++) 
        if(dist[i][i] < 0) {
            cout << " Negative cycle detected!" << endl;
            break;
        }    
}