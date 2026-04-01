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
// Time Complexity = O(E*Log(V))


// =================================================================================================
//                          Dijikstra Algorithm using SETS 
// =================================================================================================
/*
    NOTES:
    We can use set as it works in a similar way as a min heap 
    Why is Set method most effecient ??
    It saves some iterations as we erase the stale entry while inserting in the set 
    So the Log calls are called on a smaller set value 
    It is a minor improvement as compared to priority queue 

*/
class Solution2 {
public:
    vector<int> dijikstra(int v, vector<tuple<int,int,int>> &edges, int src) {
        // vertices are 0 to V-1
        // edges[][], where edges[i]=[u, v, w]  => w is the weight of edge between u and v 

        // prepare the adjL 
        vector<vector<pair<int,int>>> adjL(v);

        for(int i = 0; i < edges.size(); i++) {
            auto [u, v, w] = edges[i];
            adjL[u].push_back({v, w});
            adjL[v].push_back({u, w});
        }

        // ============ Dijikstra Algorithm ===========================
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;

        // set stores {distance, node} — automatically sorted by distance
        set<pair<int,int>> s;
        s.insert({0, src});

        while(!s.empty()) {
            auto [currDist, node] = *s.begin();
            s.erase(s.begin());

            for(auto [nbg, w]: adjL[node]) {
                int newDist = currDist + w;
                // only push if we have a better way to reach nbg 
                if(newDist < dist[nbg]) {
                    // remove if there is any other entry in the set => when dist != INT_MAX => someone reached 
                    if(dist[nbg] != INT_MAX) 
                        s.erase({dist[nbg], nbg});
                    // now update the newer better distance and push in the set 
                    dist[nbg] = newDist;
                    s.insert({newDist, nbg});
                }
            }
        }
        return dist;
    }
};



// ==================================================================================================
//                     Modified version of Dijikstra to print the shortest path
// ==================================================================================================
/*
    NOTES:
    We must store where we come back from 
        
*/
vector<int> shortestPath(int v, vector<tuple<int,int,int>> &edges, int src, int target) {
    // print shortest path using Dijikstra Algorithm

    // vertices are 0 to V-1
    // edges[][], where edges[i]=[u, v, w]  => w is the weight of edge between u and v 

    // prepare the adjL 
    vector<vector<pair<int,int>>> adjL(v);

    for(int i = 0; i < edges.size(); i++) {
        auto [u, v, w] = edges[i];
        adjL[u].push_back({v, w});
        adjL[v].push_back({u, w});
    }

    // ============ Dijikstra Algorithm and Print the shortest path ===========================
    // shortest path between src and target node 

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> parent(v);   // this stores from where did the ith node come => parent of ith node in shortest traversal
    // prefill this array with the indexes by default 
    for(int i = 0; i < v; i++)
        parent[i] = i;

    // dist array is a need as it acts like the visited arrays 
    vector<int> dist(v, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        // remove the stale entries => we alreadty have better path
        if(currDist > dist[node]) continue;

        for(auto [nbg, w]: adjL[node]) {
            int newDist = currDist + w;
            // visit this node only if we found a better way 
            if(newDist < dist[nbg]) {
                dist[nbg] = newDist;
                // now mark the parent of this nbg node => where this nbg node came from
                parent[nbg] = node;
                pq.push({newDist, nbg});
            }
        }
    }
    
    // The parent array simply helps us to build the shortest path between src and target 
    vector<int> path;

    // start from target node and go to where it comes from 
    // until the we get the node which arises from itself => if this not the start node then the node is unreachable 
    int currNode = target;
    path.push_back(currNode);

    while(true) {
        int prevNode = parent[currNode];
        // if the parent of currNode is same as currNode then we stop
        if(prevNode == currNode) {
            if(prevNode != src) return {-1};  // no path 
            
            path.push_back(prevNode);
            break;
        }

        path.push_back(prevNode);
        currNode = prevNode;
    }
    // we have the path in a reverse order 
    reverse(path.begin(), path.end());

    return path;
}