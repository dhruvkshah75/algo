// ========================================================= binary search + dijikstra ==========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/network-recovery-pathways/

/* Explanation: binary search + djikstra 
   score of the path is the minimum edge in the valid path 
   total recovery cost of the path <= k
   to find the maximum path score among all valid paths => apply binary search on score 
   and then apply djikstra as predicate function and only explore those nodes which are online 
   and those whose edge cost >= mid 

   djikstra algorithm => predicate returns ..TTTTTFFF.. get the first occurrence of True 
   it returns true if there is a valid path such as the dist[n-1] <= k and all edge costs explore >= mid 
*/

typedef long long ll;

class Solution {
private:
    const ll INF = 1e16;
    int n;
    vector<vector<pair<int,int>>> adj;

    // returns ...TTTTTFFFFF...
    bool djikstra(vector<bool> &online, int mid, ll k) {
        // find the min path to reach n-1 such that all edges in the path >= mid and all intermediate nodes are online 
        vector<ll> dist(n, INF);

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        // pq = {dist, node}

        // start from the node 0
        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // remove stale entries => found better paths to reach node 
            if(d > dist[node]) continue;

            for(auto [nbg, cost]: adj[node]) {
                // only use this edge if >= mid and nbg is online 
                if(cost < mid || !online[nbg]) continue;

                ll new_dist = d + cost;

                if(new_dist < dist[nbg]) {
                    dist[nbg] = new_dist;
                    pq.push({new_dist, nbg});
                }
            }
        }

        // the final dist to reach node n-1 (destination) <= k
        return dist[n-1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, ll k) {
        n = online.size();
        int m = edges.size();
        adj.resize(n);

        int max_edge = -1;

        for(auto &e: edges) {
            // u -> v, wt = cost 
            adj[e[0]].push_back({e[1], e[2]});
            max_edge = max(max_edge, e[2]);
        }

        // max_edge is max possible score of the path => high = max_edge 
        int low = 0, high = max_edge, best_score = -1;

        // binary search on ans 
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(djikstra(online, mid, k)) {
                best_score = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return best_score;
    }
};