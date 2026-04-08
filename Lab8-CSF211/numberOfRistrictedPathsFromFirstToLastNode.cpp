#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/

// ========================================================================================
//          Question based on Dijikstra and dp on Topological Sorting
// ========================================================================================

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        // first  of all we need the shortest distance from node n to all the nodes 
        vector<vector<pair<int,int>>> adjL(n+1);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjL[u].push_back({v, w});
            adjL[v].push_back({u, w});
        }

        vector<int> dist(n+1, INT_MAX);
        // dist[i] = distanceToLastNode(i) => shortest dist from n to ith node 
        dijikstra(n, adjL, dist);

        // now we must use dp to calculate the number of restricted paths 
        // use dp for this z1, z2, z3, zi, zi+1 => dist[Zi] > dist[Zi+1]

        // ================== dp =====================
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        // dp[i] = no of restricted paths from node 1 to n 

        vector<int> nodes(n+1);
        for(int i = 1; i <= n; i++) nodes[i] = i;

        // sort the nodes on the basis of their distance (descending)
        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return dist[a] > dist[b];
        });

        // all the nodes are processed only once no case of recounting => node contains node 1 with max dist
        for(int node: nodes) 
            for(auto [nbg, w]: adjL[node]) 
                if(dist[node] > dist[nbg]) 
                    dp[nbg] = (dp[node] + dp[nbg]) % MOD;
                
            
        return dp[n] % MOD;
    }

private:
    const int MOD = 1e9 + 7;

    void dijikstra(int n, vector<vector<pair<int,int>>> &adjL, vector<int> &dist) {
        // calculates the min distance from node n to other nodes 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // pq = {minDist, node}

        pq.push({0, n});
        dist[n] = 0;

        while(!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            // remove stale entries => already found a better path 
            if(currDist > dist[node]) continue;

            for(auto [nbg, w]: adjL[node]) {
                int newDist = currDist + w;

                if(newDist < dist[nbg]) {
                    dist[nbg] = newDist;
                    pq.push({newDist, nbg});
                }
            }
        }
    } 
};