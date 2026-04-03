#include<bits/stdc++.h>
using namespace std;

// question link: 

/*
    We simply use dijikstra and while applying we also use dp to calculate the no of paths to reach ith node 
    for ith node we calculate number of ways we can reach its nbg as it depends on its previous nodes 
*/

typedef long long ll;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m = roads.size();

        vector<vector<pair<int,int>>> adjL(n);

        for(int i = 0; i < m; i++) {
            int u = roads[i][0], v = roads[i][1], w = roads[i][2];
            adjL[u].push_back({v, w});
            adjL[v].push_back({u, w});
        }

        return dijikstra(adjL, n);
    }

private:
    const int mod = 1e9 + 7;

    int dijikstra(vector<vector<pair<int,int>>> &adjL, int n) {

        vector<ll> dist(n, LLONG_MAX);

        vector<int> dp(n, 0); 
        // dp[i] = no of ways to reach the ith node 

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

        pq.push({0, 0});
        dist[0] = 0;
        dp[0] = 1;

        while(!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            // remove the stale entires => already found a better path 
            if(currDist > dist[node]) continue;

            for(auto [nbg, w]: adjL[node]) {
                ll newDist = currDist + w;
                // if the dist is same that is also a shortest path
                if(newDist == dist[nbg]) {
                    dp[nbg] = (dp[nbg] * 1LL + dp[node]) % mod;
                }
                // if we find a better path then reset the dp[nbg]
                if(newDist < dist[nbg]) {
                    dist[nbg] = newDist;
                    dp[nbg] = dp[node];
                    pq.push({newDist, nbg});
                }
            }
        }

        // the number of ways to reach the nth node 
        return dp[n-1];
    }
};