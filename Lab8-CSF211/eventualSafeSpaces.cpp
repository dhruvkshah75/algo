#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-eventual-safe-states/description/

// This is a better cycle detection => always use these for directed graph 

class Solution {
private:
    bool dfs(vector<vector<int>>&graph, vector<bool> &visited,  
                vector<bool> &pathVisited, vector<bool> &safe, int node) {
        // mark the current node 
        visited[node] = true;
        pathVisited[node] = true;  // add the current node to the path 

        for(int nbg: graph[node]) {
            if(pathVisited[nbg]) {
                // if the nbg is in the path of the current run then cycle is detected 
                return true;
            }
            else if(!visited[nbg]) {  
                if(dfs(graph, visited, pathVisited, safe, nbg))   
                    return true;
            }
        }

        // on backtrack this node is not a part of the cycle 
        safe[node] = true;       // this node doesnt lead to the cycle or a part of cycle  
        pathVisited[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // terminal node => outdegree = 0
        // safe node => every path taken will result into a terminal node 
        
        // Solve using cycle detection using dfs 
        // any node that is a part of a cycle is not a safe node 
        // any node connected to a cycle is also not a safe node 

        vector<bool> visited(n, false), pathVisited(n, false), safe(n, false);
        // we maintain two arrays => pathVisited is to get to know what nodes are a part of the cycle

        for(int i = 0; i < n; i++) {
            if(!visited[i])
                bool temp = dfs(graph, visited, pathVisited, safe, i);
        }

        // now store all the safe nodes 
        vector<int> result;
        for(int i = 0; i < n; i++)
            if(safe[i]) result.push_back(i);

        return result;
    }
};