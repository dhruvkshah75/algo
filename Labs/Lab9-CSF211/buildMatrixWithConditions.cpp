#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/build-a-matrix-with-conditions/description/

/* Simple question => identifying topological sorting by making two graphs using rowConditions and colConditions */

typedef pair<int,int> pii;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int n = rowConditions.size(), m = colConditions.size();

        // [above, below] and [left, right]

        /* Make two different graphs using rowConditions => above -> below 
           and colConditions => left -> right => store their topo sort */

        vector<int> rowT = topoSort(k, rowConditions);
        vector<int> colT = topoSort(k, colConditions);

        // topoSort is not valid 
        if(rowT.size() != k || colT.size() != k) 
            return {};

        // now store the position of each number 
        vector<pii> pos(k+1);

        for(int i = 0; i < rowT.size(); i++) {
            pos[rowT[i]].first = i;
        }

        for(int j = 0; j < colT.size(); j++) {
            pos[colT[j]].second = j;
        }

        vector<vector<int>> result(k, vector<int>(k, 0));

        for(int i = 1; i <= k; i++) {
            result[pos[i].first][pos[i].second] = i;
        }

        return result;
    }

private: 

    vector<int> topoSort(int k, vector<vector<int>> &edges) {
        int n = edges.size();

        vector<vector<int>> adj(k+1);
        vector<int> indegree(k+1, 0);

        for(int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            // u -> v
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> tp;
        queue<int> q;

        for(int i = 1; i <= k; i++) {
            if(indegree[i] == 0) 
                q.push(i);
        }

        // Kahn's Algorithm
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            tp.push_back(node);

            for(int nbg: adj[node]) {
                indegree[nbg]--;

                if(indegree[nbg] == 0) 
                    q.push(nbg);
            }
        }
    
        return tp;
    }
};