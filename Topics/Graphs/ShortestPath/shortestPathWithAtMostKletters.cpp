// =========================================================== multi state djikstra ======================================

#include<bits/stdc++.h> 
using namespace std;

// question link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/description/

/* Explanation: djikstra algorithm on multiple states
   Here the two states that are needed are the (node, count)
   to reach a node from 0 also depends on the number of consecutive identical characters 
   were recorded on the path

   use a 2d vector of dist => dis[node][count] = min distance to reach node from 0 with count number of consecutive 
   identical characters 
*/

class Solution {
private:
    const int INF = INT_MAX;

public:
    int shortestPath(int n, vector<vector<int>>& edges, string &labels, int k) {
        int m = edges.size();

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e: edges) {
            // directed path => u -> v
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k+1, INF));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        // pq = {distance, count, node}

        // start from node = 0;
        pq.push({0, 1, 0});
        dist[0][1] = 0;

        while(!pq.empty()) {
            auto [d, cnt, node] = pq.top();
            pq.pop();

            // remove stale entries => found a better path already
            if(d > dist[node][cnt]) continue;

            for(auto [nbg, wt]: adj[node]) {
                int nxt_dist = d + wt;
                
                if(labels[node] == labels[nbg]) {
                    // case 1: letter of node and nbg matches 
                    if(cnt + 1 <= k && nxt_dist < dist[nbg][cnt+1]) {
                        dist[nbg][cnt+1] = nxt_dist;
                        pq.push({nxt_dist, cnt+1, nbg});
                    }
                }
                else {
                    // case 2: label of node and nbg dont match => nbg starts fresh (count = 1)
                    if(nxt_dist < dist[nbg][1]) {
                        dist[nbg][1] = nxt_dist;
                        pq.push({nxt_dist, 1, nbg});
                    }
                }
            }
        }

        // the minimuim total edge width with at most k consecutive identical characters => min(dist[n-1])
        int res = *min_element(dist[n-1].begin(), dist[n-1].end());

        if(res == INF) return -1;
        else return res;
    }
};