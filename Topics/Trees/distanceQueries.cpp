// ====================================== binary lifting to get LCA ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://cses.fi/problemset/task/1135

/**
 * The question askes us to get the distance between two nodes 
 * so we can get the ans using lca => lowest common ancestor 
 * it wont be just the bfs between them -> this would correctly give the ans the queries are very large cant apply 
 * bfs on each of them 
 * so the correct solution => (depth(A) - depth(lca(A, B))) + (depth(A) - depth(lca(A, B)))
 * => depth[A] + depth[B] - 2 * depth[LCA(A, B)]
 * To get the LCA we use binary lifting concept
 * 
 * keep the node = 1 as the root of the tree
 */

class DistanceQueries {
private:
    int n, LOG;
    vector<vector<int>> up;
    vector<vector<int>> adj;
    vector<int> depth;

    void bfs() {
        queue<int> q;

        q.push(1);
        depth[1] = 0;
        // parent = -1

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nbg: adj[node]) {
                // parent of node is nbg then => nbg is already processed earlier 
                if(up[node][0] == nbg) continue;

                depth[nbg] = depth[node] + 1;
                up[nbg][0] = node;
                q.push(nbg);
            }
        }
    }

    int lca(int u, int v) {
        // keep u at the lower depth 
        if(depth[u] < depth[v]) swap(u, v);

        // lift u to get v and u at the same depth => get the kth ancestor of u (k = diff)
        int diff = depth[u] - depth[v];

        for(int j = 0; j < LOG; j++) {
            int bit = diff & (1 << j);
            // if bit is set then lift it to its 2^j ancestor
            if(bit) {
                u = up[u][j];
            }
        }

        // if the diff th ancestor of u = v then lca is v 
        if(u == v) return v;

        // now binary lift them both till their ancestors are different => we are guessing what is the k of (kth ancestor) thier lca
        for(int j = LOG-1; j >= 0; j--) {
            // jump if their 2 ^ j th ancestor is diff
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        } 

        return up[u][0];
    }

public:

    DistanceQueries(int n, vector<pair<int,int>> &edges) {
        this->n = n;
        // compute the value of LOG 
        LOG = 0;

        while((1 << LOG) <= n+1) LOG++;

        adj.resize(n+1);
        up.resize(n+1, vector<int>(LOG, -1));
        depth.resize(n+1);

        for(auto [a, b]: edges) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // populate up[node][0] = parent and depth of the edges using bfs 
        bfs();

        // populate the up table for binary lifting lookups 
        for(int j = 1; j < LOG; j++) {
            for(int i = 1; i <= n; i++) {
                // only lift if the 2^(j-1) jump is allowed
                if(up[i][j-1] != -1) {
                    int node = up[i][j-1];
                    up[i][j] = up[node][j-1];
                }
            }
        }
    }

    void solve(vector<pair<int,int>> &queries) {
        
        for(auto [a, b]: queries) {
            int lca_ab = lca(a, b);

            cout << depth[a] + depth[b] - 2 * depth[lca_ab] << endl;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<pair<int,int>> edges(n-1);

    for(int i = 0; i < n-1; i++) 
        cin >> edges[i].first >> edges[i].second;

    DistanceQueries dq(n, edges);

    vector<pair<int,int>> queries(q);

    for(int i = 0; i < q; i++) 
        cin >> queries[i].first >> queries[i].second;

    dq.solve(queries);
}

