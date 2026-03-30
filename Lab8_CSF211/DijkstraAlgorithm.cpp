#include<bits/stdc++.h>
using namespace std;

// question link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// ==================================================================================================
//                      Dijikstra Algorithm Using Priority Queues 
// ==================================================================================================

/*
    NOTES:
    now each edges has weights assoiated with them 
    To apply Dijikstra Algorithm => the weights of the edges cannot be negative 

    use minHeap that stores distance and the node 
    Instead of using a visited array we use the answer that is distance array and visit the node if found a shorter 
    i.e. less weigthed total path to reach that node 

*/
class Solution1 {
public: 
    vector<int> dijkstra(int V, vector<tuple<int,int,int>> &edges, int src) {
        // vertices are 0 to V-1
        // edges[][], where edges[i]=[u, v, w]  => w is the weight of edge between u and v 

        // prepare the adjL 
        vector<vector<pair<int,int>>> adjL(V);

        for(int i = 0; i < edges.size(); i++) {
            auto [u, v, w] = edges[i];
            adjL[u].push_back({v, w});
            adjL[v].push_back({u, w});
        }

        // ============ Dijikstra Algorithm ===========================

        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  // min heap
        // pq = {dist, node} 
        
        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            // throw out those entries which are invalid => we found a better way to reach already 
            if(currDist > dist[node]) continue;

            for(auto [nbg, w]: adjL[node]) {
                int newDist = currDist + w;
                // push the nbg if we found a shorter way => less weihted path
                if(newDist < dist[nbg]) {
                    pq.push({newDist, nbg});
                    dist[nbg] = newDist;
                }
            }
        }

        return dist;  // dist[i] = shortest distance from src to i
    }
};


// =================================================================================================
//                          Dijikstra Algorithm using SETS 
// =================================================================================================
/*
    NOTES:

*/
class Solution2 {
public:
    vector<int> dijikstra(int v, vector<tuple<int,int,int>> &edges, int src) {

    }
};



// ==================================================================================================
//                     Modified version of Dijikstra to print the shortest path
// ==================================================================================================
/*
    NOTES:
        
*/
vector<int> shortestPath(int v, vector<tuple<int,int,int>> &edges, int src) {
    // print shortest path using Dijikstra Algorithm


}