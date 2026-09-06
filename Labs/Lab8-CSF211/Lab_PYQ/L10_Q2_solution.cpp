#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*
    NOTE:
    For anything beyond just distance (counts, number of paths, etc.), arrays are always cleaner than pq state.
    So rather than storing them as states in pq just define arrays for all nodes not just the end in dijikstra 
*/

vector<ll> dijikstra(vector<vector<pair<int,int>>> &adjL, int n);

vector<ll> solve(int n, int m, vector<vector<int>> &trains) {
    // SOLVE HERE
    vector<vector<pair<int,int>>> adjL(n+1);

    for(int i = 0; i < m; i++) {
        int u = trains[i][0], v = trains[i][1], w = trains[i][2];

        adjL[u].push_back({v, w});
    }

    return dijikstra(adjL, n);
}

vector<ll> dijikstra(vector<vector<pair<int,int>>> &adjL, int n) {
    // dijikstra returns minFare path 
    
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    // pq = {distance, node}

    vector<ll> dist(n+1, LLONG_MAX);
    vector<int> dp(n+1, 0), minCount(n+1, INT_MAX), maxCount(n+1, INT_MIN);
    // minCount ans maxCount store the min and max number of nodes in the path to reach ith node 

    // path 1 to n 
    pq.push({0, 1});
    minCount[1] = maxCount[1] = 0;
    dist[1] = 0;
    dp[1] = 1;

    while(!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        // remove stale entries 
        if(currDist > dist[node]) continue;
        

        for(auto [nbg, w]: adjL[node]) {
            ll newDist = currDist + w;

            if(newDist == dist[nbg]) {
                dp[nbg] = (dp[nbg] + dp[node]) % MOD;
                // we found a similar path so update the minCount and maxCount 
                minCount[nbg] = min(minCount[nbg], minCount[node] + 1);
                maxCount[nbg] = max(maxCount[nbg], maxCount[node] + 1);
            }
            else if(newDist < dist[nbg]) {
                pq.push({newDist, nbg});
                dist[nbg] = newDist;
                dp[nbg] = dp[node] % MOD;
                // revamp the mincount and maxcount as we found a completely new better path
                minCount[nbg] = minCount[node] + 1;
                maxCount[nbg] = maxCount[node] + 1;
            }
        }
    }

    return {dist[n], dp[n], minCount[n], maxCount[n]};
}