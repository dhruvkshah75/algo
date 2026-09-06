#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

/*
    In this question we must also track the minDist to reach each node with how many stops 
    so we can reach the same node we can reach that node in many ways but they depend on stops made 
    There are 2 states to track simultaneously 

    use dist as 2d array holding distance and stops 
    dist[distance][stops] => we compare this 
    the dist[i][j] denotes the minDist to reach the ith node with j stops
    
    total stops allowed to reach the destination is k+1 including the destination node

    IMPORTANT QUESTION on Dijikstra Algorithm

    priority queue now handles 3 values at for each node visited 
    pq = {distance, node, stops} => distance to reach node with these many stops 

    we cant do 
    while(!pq.empty()) {
        int pqSize = pq.size();
        while(pqSize--) {
        
        }
        stops++;
    }
    
    As in a min heap order of insertion is not maintained (not fifo)

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // here we must also keep a track of levels i.e. no of stops in each path 
        vector<vector<pair<int,int>>> adjL(n);

        for(int i = 0; i < flights.size(); i++) {
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adjL[u].push_back({v, w});
        }

        // Dijisktra Algorithm

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX)); 
        // min heap => pq = {dist, node, stops} => should not exceed k stops
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        pq.push({0, src, 0});
        dist[src][0] = 0;    

        while(!pq.empty()) {
            auto [currDist, node, stops] = pq.top();
            pq.pop();

            // remove the stale entries in pq & min heap guarantees first hit = cheapest
            if(currDist > dist[node][stops]) continue;
            if(node == dst) return currDist;  

            for(auto [nbg, w]: adjL[node]) {
                int newDist = currDist + w, newStops = stops + 1; 
                // only push if the stops dont exceed k+1 and newDist is better 
                if(newStops <= k+1 && newDist < dist[nbg][newStops]) {
                    dist[nbg][newStops] = newDist;
                    pq.push({newDist, nbg, newStops});
                }
            }
        }

        return -1;
    }
};