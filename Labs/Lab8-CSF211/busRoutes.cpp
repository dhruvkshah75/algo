#include<bits/stdc++.h>
using namespace std;

// question link: 

/*
    Algorithm: 
    Nodes = stops, Edges = implicit through buses
    Two stops are connected if there EXISTS a bus that visits both

    Create a map => stop = key and value = all the buses which have this stop in their routes 
    start from the source => take each bus asscoiated with this stop and then move the to the next stops via routes[bus]

*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // we start from the routes that have the source and then 
        // we start swtching routes if two routes have same common stops => similar to word ladder 
        int n = routes.size();

        unordered_map<int,vector<int>> stops;
        // stops[i] = {} => ith stop is part of which bus route 

        for(int b = 0; b < n; b++) {
            for(int stop: routes[b]) 
                stops[stop].push_back(b);
                // this stop can taken by any bus which is a part of stops[stop]
        }

        // BFS on stops
        // levels taken to reach the target stop is the final answer 
        vector<bool> takenBus(n, false);
        unordered_set<int> visitedStops;

        queue<int> q;  // q = {stop} queue of stops 
        
        q.push(source);
        visitedStops.insert(source);

        int level = 0;

        while(!q.empty()) {
            int qSize = q.size();
            while(qSize--) {
                int currStop = q.front();
                q.pop();

                if(currStop == target) return level;

                // now traverse through all the buses for which currStop is a part of 
                for(int bus: stops[currStop]) {
                    // if the bus is already visited then skip 
                    if(takenBus[bus]) continue;
                    takenBus[bus] = true;

                    // now try all the stops that this bus visits 
                    for(int nextStop: routes[bus]) {
                        if(visitedStops.find(nextStop) != visitedStops.end()) continue;
                        q.push(nextStop);
                        visitedStops.insert(nextStop);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};