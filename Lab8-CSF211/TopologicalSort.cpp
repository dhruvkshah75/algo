// What is Topological Sorting in graphs 

#include<bits/stdc++.h>
using namespace std;

// ============================================================================================
//                      Topological Sorting using DFS 
// ============================================================================================

/*
    Works only on any DAG (directed ayclic graph) with no cycles 
    Topological Sort:
        Linear ordering of vertices such that if there is an edge between u and v,
        u appears before v in that ordering 

    If there is a cycle assume 1->2->3->1 this is a cycle => linear ordering of this would not be possible 
        1 2 3 => this violates the case of 3 should appear before 1 but because of cycle it becomes false
        as this creates a cyclic dependency 

    we use a stack data structure for topo sort in 

    Intuition of the stack logic in the code 
    Whenever we call dfs for a node => then we call dfs for its neighbours (u -> v)
    So u should appear before v in the linear ordering so after the call store the node in stack 

*/

void dfs(int node, vector<vector<int>> &adjL, stack<int> &st, vector<bool> &visited) {

    visited[node] = true;

    // now we call dfs on all the neigbours 
    // so they are stored first in the stack (u -> v) v should be lower than u in stack

    for(int nbg: adjL[node]) {
        if(!visited[nbg])
            dfs(nbg, adjL, st, visited);
    }

    st.push(node);
}
// O(V + E) for directed graphs 

vector<int> topoSort(int n, vector<vector<int>> &adjL) {
    // we are given the adjL and the number of nodes 

    vector<bool> visited(n, false);

    stack<int> st;

    // since this is a directed graph so we must run dfs on all non visited nodes 
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adjL, st, visited);
        }
    }

    vector<int> result;

    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}


// =========================================================================================================
//                               Kahn's Algorithm (topological sorting using bfs)
// =========================================================================================================
/*
    Only valid on Directed Acyclic graph (DAG)
    How does it work ??

    We keep indegree vector and start from those whose indegree = 0 
    so push nodes with indegree = 0

    the node with indgree = 0 this means there is no node that appears before it in the linear ordering 
    no edge to this node 

*/

vector<int> indegreeCalc(vector<vector<int>> &adjL, int n) {
    // how to prepare the indegree vector when adjacency list is given to us 
    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++) {
        int node = i; 
        for(int nbg: adjL[node]) {
            indegree[nbg]++;
        }
    }

    return indegree;
}

void KahnsAlgorithm(int n, vector<pair<int,int>> &edges) {
    // we must use indegree of each vector => because of the indegree we dont need to use the visited array 

    // =============================== Kahn's Algorithm ==================================
    vector<int> indegree(n, 0);

    vector<vector<int>> adjL(n);   // 0 - n-1 vertices

    for(int i = 0; i < n; i++) {
        auto [u, v] = edges[i];
        // u -> v
        adjL[u].push_back(v);
        indegree[v]++;
    }

    // queue only contains the nodes which have a indegree = 0
    queue<int> q; 
    vector<int> result;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int nbg: adjL[node]) {
            // think of like removing the node(edge also gets removed) so we decrease the indegree of all the nbg by 1 
            indegree[nbg]--;

            if(indegree[nbg] == 0) {
                q.push(nbg);
            }
        }
    }

    // now if all the all nodes get pushed in the result vector (topo sort) then the curr topological sorting is valid 

    bool isDAG = (result.size() == n);

    // bool isDAG = (result.size() == n); => clean
    // bool isDAG = (all indegrees == 0); => also correct 
} 