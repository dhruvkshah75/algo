/*
    BREADTH FIRST SEARCH 
    How it works ??
    BFS traversal 
    For all traversals we always use visited array => vector<bool> visited  => to check which nodes are visisted 

    Breadth first means => same level traversal 
    Same level must be traversed at the same time 
    bfs largely depends on starting node 
    
    Starting node is level 0 and the nodes at a distance of 1 are called level 1 
    subsequently nodes at any equivalent distance from it are in the same level 

            1 
        2      6  => 6 is the starting node 
      3   4  7    8
            5             
    bfs sequence can be => 6 1 7 8 2 5 3 4 
            Levels    =>   0 - 1 - -2- -3-    ==> it is like simulataneously stratching in all breadths  

    We use queue data structure for this traversal to use FIFO (first in first out)

    adjL => 1 = {2, 6}
            2 = {1, 3, 4}
            3 = {2}
            4 = {2, 5}
            5 = {4, 7}
            6 = {1, 7, 8}
            7 = {6, 5}
            8 = {6}
*/


#include<bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int>> &adjL, int start, int n) {
    // adjL denotes the adjacency list of graph and start denotes the starting node 
    
    vector<bool> visited(n+1, false); 
    queue<int> q;

    q.push(start);
    visited[start] = true;

    // put in the queue and put in the queue until it becomes empty 
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";
        
        // now push all the not visited neighbours of the current node that we just poped 
        for(int neighbour: adjL[node]) {
            if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

    // Time Complexity = O(N + 2E) 
    // Inner loop runs for all the degrees of the nodes => 2E (handshaking lemma)
}

// ==============================================================
// BFS = shortest path. Always. In any unweighted graph
// ==============================================================