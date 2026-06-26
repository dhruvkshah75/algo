// ================================================= topological Sorting =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/loud-and-rich/description/

/* Explanation: topological sorting => Kahn's Algorithm
   Form the graph using the richer relation => [a, b] where a is richer than b 
   and then for forming the answer array we simply update the best min quiet value 
   when we visit the nbg of the curr node in the bfs loop
    
   Simply apply this condition while processing each node in topo sort 
   and only push the node once the indegree becomes 0
   if(quiet[res[node]] < quiet[res[nbg]]) res[nbg] = res[node];

   Time Complexity = O(V + E) => here E >> V so time complexity = O(E) = O(N^2)
*/

class Solution {
private:
    vector<vector<int>> adj;
    vector<int> indeg;

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        // people are labeled 0 - n-1

        adj.resize(n);
        indeg.resize(n, 0);

        for(auto &e: richer) {
            // u -> v
            indeg[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }

        queue<int> q;
        vector<int> res(n);
        // prefill the res with res[i] = i
        std::iota(res.begin(), res.end(), 0);

        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
                // initial starting nodes => answer[x] = x
                res[i] = i;
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nbg: adj[node]) {
                indeg[nbg]--;

                // update the res[nbg] (node -> nbg) 
                // res[node] and res[nbg] corresponds to the most quite person
                if(quiet[res[node]] < quiet[res[nbg]]) res[nbg] = res[node];
                
                if(indeg[nbg] == 0) q.push(nbg);
            }
        }

        return res;
    }
};