#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/all-paths-from-source-to-target/description/

// Simple DFS and backtracking 


class Solution {
    void dfs(vector<vector<int>> &adjL, vector<int> &currPath, 
                                vector<vector<int>> &result, int currNode) {
        int n = adjL.size();
        if(currNode == n-1) {
            result.push_back(currPath);
            return;
        }

        // push the neighbours 
        for(int nbg: adjL[currNode]) {
            currPath.push_back(nbg);
            dfs(adjL, currPath, result, nbg);
            // bactrack => remove the last entry to allow next step
            currPath.pop_back(); 
        }

        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // question is based on backtracking 
        int n = graph.size();

        // find paths from 0 to n-1 
        vector<vector<int>> result;

        vector<int> currPath;
        currPath.push_back(0);

        dfs(graph, currPath, result, 0);

        return result;
    }
};