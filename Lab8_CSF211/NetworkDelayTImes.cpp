#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/network-delay-time/description/

// Dijikstra Algorithm direct question => EASY Question 

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // here k is the source node 

        // we must determine the minium time for signal to reach all nodes => max value in distance node 
        // The ans is max distance (longest shortest path between two nodes) as this much time is just needed 

        vector<vector<pair<int,int>>> adjL(n+1);

        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0], v = times[i][1], w = times[i][2];

            adjL[u].push_back({v, w});  // directed graph
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // min Heap => pq = {dist, node}

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            // skip the stale entries => we found shorter path 
            if(currDist > dist[node]) continue;

            for(auto [nbg, w]: adjL[node]) {
                int newDist = currDist + w;

                if(newDist < dist[nbg]) {
                    pq.push({newDist, nbg});
                    dist[nbg] = newDist;
                }
            }
        }
        // the max distance will be the result for this question and skip 0th index 
        int maxDist = *max_element(dist.begin()+1, dist.end());

        return (maxDist == INT_MAX) ? -1 : maxDist;
    }
};