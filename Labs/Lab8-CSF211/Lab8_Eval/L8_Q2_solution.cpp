#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int n, int m, std::vector<std::vector<int>> &flights) {

    vector<vector<pair<int,int>>> adjL(n+1);

    for(int i = 0; i < flights.size(); i++) {
        int u = flights[i][0], v = flights[i][1], w = flights[i][2];
        adjL[u].push_back({v, w});
        // u -> v
    }

    // apply dijkstra 
    vector<vector<ll>> dist(n+1, vector<ll>(2, LLONG_MAX));
    // dist[node][couponUsed] 

    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;
    // pq = {currFare, node, couponUsed} => 0 indicates coupon is not used, 1 means coupon is used cannot be used further 

    pq.push({0, 1, 0});
    dist[1][0] = 0;  

    while(!pq.empty()) {
        auto [currDist, node, couponUsed] = pq.top();
        pq.pop();

        // remove the stale entries 
        if(currDist > dist[node][couponUsed]) continue;

        for(auto [nbg, w]: adjL[node]) {
            ll newDist = currDist + w;
            if(newDist < dist[nbg][couponUsed]) {
                dist[nbg][couponUsed] = newDist;
                pq.push({newDist, nbg, couponUsed});
            }

            if(couponUsed == 0) {
                // not used discount yet => use it on this edge 
                ll distC = currDist + w/2;

                if(distC < dist[nbg][couponUsed+1]) {
                    dist[nbg][couponUsed+1] = distC;
                    pq.push({distC, nbg, couponUsed+1});
                }
            }
        }
    }

    return min(dist[n][0], dist[n][1]);
}