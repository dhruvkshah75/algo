#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        /* build two graphs => where we order groups using topo sort 
           assume group -1 to  be group m 
           build the dependency graph of nodes in the same graph 
           Note: all the -1 => belonging to no group => must get a unique group */

        for (int i = 0; i < n; i++) {
            if(group[i] == -1)
                group[i] = m++;  // each gets a unique group id
        }

        unordered_map<int,vector<int>> grps;
        // grp[i] = {elements of group with group id i} 

        for(int i = 0; i < n; i++) {
            grps[group[i]].push_back(i);
        }

        vector<vector<int>> adjG(m);
        vector<int> indegree(m, 0);
        // make the graph of dependency conditions for each group 

        for(int i = 0; i < n; i++) {
            for(int item: beforeItems[i]) {
                if(group[i] == group[item]) continue;

                // group[item] -> group[i]
                adjG[group[item]].push_back(group[i]);
                indegree[group[i]]++;
            }
        }

        // now we apply topo sort on graph of group dependency which group must appear first 

        vector<int> GrpTopo;
        queue<int> q;

        for(int i = 0; i < m; i++) {
            if(indegree[i] == 0) 
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            GrpTopo.push_back(node);

            for(int nbg: adjG[node]) {
                indegree[nbg]--;
                if(indegree[nbg] == 0) {
                    q.push(nbg);
                }
            }
        }
        
        vector<int> result;

        if((int)GrpTopo.size() != m) 
            return {};
        
        for(int grpId: GrpTopo) {
            unordered_map<int,vector<int>> adj;
            unordered_map<int,int> indeg;

            // initialise for all items
            for(int item: grps[grpId]) {
                indeg[item] = 0;
                adj[item] = {};
            }

            for(int item: grps[grpId]) {
                for(int before: beforeItems[item]) {
                    if(group[before] != grpId) continue;
                    // create the edge => before -> item
                    adj[before].push_back(item);
                    indeg[item]++;
                }
            }

            // now apply topo sort using kahns algorithm 
            int cnt = 0;
            queue<int> q;

            for(auto [item, deg]: indeg) {
                if(deg == 0) 
                    q.push(item);
            }

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                result.push_back(node);
                cnt++;

                for(int nbg: adj[node]) {
                    indeg[nbg]--;
                    if(indeg[nbg] == 0)
                        q.push(nbg);
                }
            }

            if(cnt != (int)grps[grpId].size())
                return {};
        }

        return result;
    }
};