
#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/critical-connections-in-a-network/description/

/**
 * Tarjans Algorithm: using the arrays like tin and low 
 * tin = time of DFS insertion 
 * low = min time of insertion of any neighbour of the node apart from the parent 
 * we exclude the parent from this because (parent -> node) is the edge that we are trying to remove 
 * to check if it is the bridge 
 * 
 * We update the low of a node at two times 
 * When a back edge is detected (i.e. cycle detected) so update the low of the node 
 * and on the second time after recursive calls to the nbg update the low[node] to the 
 * min of low of the nbg and current value => this is on the step of backtracking 
 * 
 * For checking if this edge node --- nbg is a bridge or not 
 * the low[nbg] > tin[node] then we cannot reach nbg through node in anny other way (if this edge is deleted )
 * */

class Solution {
private:
	int time;
	vector<vector<int>> adj, bridges;

	void dfs(int node, int parent, int low[], int tin[], bool vis[]) {
		// mark the insertion time of the node 
		tin[node] = low[node] = time++;
		vis[node] = true;

		for(int nbg: adj[node]) {
			// skip the parent edge 
			if(nbg == parent) continue;

			if(vis[nbg]) {
				// node - nbg => back edge so update the low
				low[node] = min(low[node], tin[nbg]);
			}
			else {
				// recurse to the next node 
				dfs(nbg, node, low, tin, vis);

				// on backtracking update the low and check for bridge 
				low[node] = min(low[node], low[nbg]);

				// check if this egde is bridge or not => node ---- nbg
				// if min time to reach any adj neighbour of nbg is more than time of insertion of node then it is bridge 
				if(low[nbg] > tin[node]) bridges.push_back({node, nbg});
			}
		}
	}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &edges) {
        int m = edges.size();

        adj.resize(n);

        int low[n], tin[n];
        bool vis[n] = {false};

        for(auto &e: edges) {
        	adj[e[0]].push_back(e[1]);
        	adj[e[1]].push_back(e[0]);
        }

        time = 1;

        // fix the node 0 as the root and start the dfs call from there 
        dfs(0, -1, tin, low, vis);

        return bridges;
    }	
};