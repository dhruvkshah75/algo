#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

/*
    VERY IMPORTANT LOGIC: 
    Apply simple bfs but the instead of having the logic visited array 
    => we can visit the same node twice to get shortest distance 
    calculate the distance and update only if we find a better path to reach till this point 

    dist[node][lastColor] = shortest path to reach the node with the prev Edge connecting to it with lastColor 
    This will ensure that bfs is not stuck in a circular loop 
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int m1 = redEdges.size(), m2 = blueEdges.size();

        // prepare the adjacency List 
        vector<vector<pair<int,int>>> adjL(n);

        for(int i = 0; i < m1; i++) {
            // red edges 
            int u = redEdges[i][0], v = redEdges[i][1];
            adjL[u].push_back({v, 0});
        }

        for(int i = 0; i < m2; i++) {
            // blue edges 
            int u = blueEdges[i][0], v = blueEdges[i][1];
            adjL[u].push_back({v, 1});
        }

        // ========================= BFS ====================================

        // 0 => red edge and 1 => means blue edge 
    
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX)); 
        // dist[node][last_color] => update only if we found a better way to visit the node with same last edge
        queue<pair<int,int>> q;     
        // q = {node, edge} queue stores the node with the prevEdge is blue or red 

        int distance = 0;    
        q.push({0, -1});
        dist[0][0] = 0, dist[0][1] = 0;  

        // BFS
        while(!q.empty()) {
            int qSize = q.size();
            while(qSize--) {
                auto [node, edge] = q.front();
                q.pop();

                // now push the nbgs with alternating edges 
                for(auto [nbg, nbgEdge]: adjL[node]) {
                    // the edges should not match => should be alternating
                    if(edge != nbgEdge && distance+1 < dist[nbg][nbgEdge]) {
                        q.push({nbg, nbgEdge});
                        dist[nbg][nbgEdge] = distance + 1;
                    }
                }
            }
            distance++;
        }

        vector<int> result;
        // now we must replace all the INT_MAXs with -1 
        for(int i = 0; i < n; i++) {
            int best1 = dist[i][0], best2 = dist[i][1];

            if(min(best1, best2) == INT_MAX) {
                result.push_back(-1);
                continue;
            }
            result.push_back(min(best1, best2));
        }

        return result;
    }
};