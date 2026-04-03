#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

// =================================================================================================
//                          Dijikstra Algotithm Approach 
// =================================================================================================

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // we can apply dijikstra on each node to get the city => weights are non negative 
        int m = edges.size();
        vector<vector<pair<int,int>>> adjL(n);

        for(int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjL[u].push_back({v, w});
            adjL[v].push_back({u, w});
        }

        // now we find the city with the least cities within the threshold 
        pair<int,int> result = {-1, INT_MAX};

        for(int i = 0; i < n; i++) {
            int cityCount = dijikstra(i, distanceThreshold, adjL);

            if(cityCount < result.second) {
                result = {i, cityCount};
            }
            else if(cityCount == result.second && i > result.first) {
                result = {i, cityCount};
            }
        }

        return result.first;
    }

private:
    int dijikstra(int start, int distThreshold, vector<vector<pair<int,int>>> &adjL) {
        // find how many cities does start connect to this city with less than distThreshold
        int count = 0;
        int n = adjL.size();

        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // pq = {distance, node}

        pq.push({0, start});
        dist[start] = 0;

        while(!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if(currDist > dist[node]) continue;

            for(auto [nbg, w]: adjL[node]) {
                int newDist = currDist + w;
                // only push the nbg if the distance is less than threshold 
                if(newDist < dist[nbg] && newDist <= distThreshold) {
                    dist[nbg] = newDist;
                    pq.push({newDist, nbg});
                }
            }
        }

        // dijikstra algorithm could only reach the those city that are within threshold 
        for(int i = 0; i < n; i++) {
            if(i == start || dist[i] == INT_MAX) continue;
            count++;
        }

        return count;
    }
};


// ==========================================================================================
//                            Floyd Warshall Algorithm Approach 
// ==========================================================================================