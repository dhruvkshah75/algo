#include <bits/stdc++.h>
using namespace std;

/*
    CODE SUMMARY 
    We're running a modified Kahn's algorithm where instead of deciding which node to pick next (via a queue), 
    the topoSort array tells us the order — so we just simulate it.

    At every stage, we maintain a live count of how many nodes currently have indegree 0 
    (i.e., are valid to pick). Before processing each node:
    1. Record the current count
    2. Remove the node (decrement count)
    3.  Update neighbors — if any neighbor's indegree drops to 0, increment count
    4.  Move to the next node in topoSort
*/

vector<int> solve(vector<vector<int>>& edges, vector<int>& topoSort) {
    int n = topoSort.size(), m = edges.size();
    
    vector<vector<int>> adjL(n+1);
    vector<int> indegree(n+1, 0);

    for(int i = 0; i < m; i++) {
        adjL[edges[i][0]].push_back(edges[i][1]);
        // u -> v
        indegree[edges[i][1]]++;
    }

    // the topSort array helps us get the nodes with indegree 0 in one go 
    // ========= Using a modified version of Kahn's Algorithm =================
    
    vector<int> result;
    // we remove elements one by one from the topoSort 
    int l = 0, count = 0;      // count stores the number of elements with indegree 0 

    for(int i = 1; i <= n; i++) 
        if(indegree[i] == 0) count++;

    // this is when we remove 0 elements 
    result.push_back(count);

    while(l+1 < n) {
        int node = topoSort[l];
        count--;
        // now like kahn's algorithm we remove the current node so update the indegree of all the nbgs
        for(int nbg: adjL[node]) {
            indegree[nbg]--;

            if(indegree[nbg] == 0) {
                count++;
            }
        }
        l++;
        result.push_back(count);
    }

    return result;
}
// O(V + E)  => V = vertices E = edges 