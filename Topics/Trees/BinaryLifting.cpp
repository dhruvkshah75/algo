// =============================================== trees + binary lifting ============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

// ============================================= Kth Ancestor of a node ==============================================

/* Explanation: Binary Lifting 
   here to solve the get kth ancestor queries faster than O(Height) we can use the concept of binary lifting 
   where for each node we preprocess the nodes and store their ancestors in the power of 2 
   so we can store the ancestors like 2^1 th ancestor, 2^2 ancestor, .... so on 
   up[i][j] = denotes the 2^j th ancestor of the node i 

   example find the 7th ancestor => instead of making 7 jumps upward => make stones in the powers of 2 why ??
   7 => 0111 => 2 ^ 0 + 2 ^ 1 + 2 ^ 2 ==> make 1 jump then 2 jumps then 4 jumps to reach the 7th ancestor 
   why can we do this => each number (k) can be represented as powers of two => so this always works 
   So we can get these individual jumps => we can get them in O(1) time 
   and we get the Kth Ancestor in O(Log(N)) time complexity 

   we only to get the 2^x <= N => we need to allott only this much area to the up[n][LOG]

   So to solve the question of handling the kth ancestor (binary lifting) => Any type of questiom
   convert the given information always into a parent vector 
   when parent[i] = x means x is the parent node to node i

   A simple logic => if want the 2^k ancestor of the current node then 
   we can do one thing we can jump 2 ^ (k-1) ancestor first and then from the new node jump 
   2 ^ (k-1) ancestor again => as both jumps add up to get 2^k ancestor of the node 

   => this formula derives us the jump up[i][j] = up[up[i][j-1]][j-1]
   up[i][j-1] = node => this is the first 2 ^ (j-1) jump 
   then we make anathor last jump of 2 ^ (j - 1) => up[node][j-1]
   up[i][j] => 2 ^ kth ancestor => up[i][j] = up[node][j-1]

   LOG denotes the max number of bits in N => because that will be the cap of the 2 ^ j that we need to store in 
   the up table 
*/

class TreeAncestor {
private:
    int LOG;
    vector<vector<int>> up;
    // up[node][j] = 2^j th parent of node 

public:
    TreeAncestor(int n, vector<int> &parent) {
        LOG = 0;
        // calculate the value of LOG => 2 ^ LOG <= N ===> so define the size as LOG+1
        while((1 << LOG) <= n) LOG++;

        up.resize(n, vector<int>(LOG, -1));
        
        // assign the up[node][0] with 2 ^ 0 ancestor => directly from parent table 
        for(int i = 0; i < n; i++) 
            up[i][0] = parent[i];


        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                if(up[i][j-1] != -1) {
                    // to get the 2 ^ j ancestor make 2 jumps => each of 2 ^ (j-1) 
                    int node = up[i][j-1];     
                    up[i][j] = up[node][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        // make jumps according to the binary representions of k
        // process the jumps as the set bits in its binary representation

        for(int j = 0; j < LOG; j++) {
            // check if the jth bit of k is set then we jump 
            int jth_bit = k & (1 << j);

            if(jth_bit) {
                node = up[node][j];  // make 2 ^ j th jump
                
                // if the value is -1 then kth ancestor does not exist
                if(node == -1) return -1;
            }
        }
        
        return node;
    }
    // Time Complexity = O(Log(N)) for each Kth ancestor query 
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */




/**
 * This concept of using binary lifting can be used easily to get the LCA of 2 nodes in the graph 
 * Computing LCA of two nodes can help solve many problems quite easily
 * 
 * In a complex question where this must be done in O(Log(N)) time 
 * we cannot preprocess and get the LCA of each pair of nodes as nodes are in the range of n <= 1e5
 * 
 * So how to get the LCA of two nodes using Binary lifting 
 * First of all using dfs compute the depth of each node 
 * now getting LCA(node A, node B) => suppose two nodes are at different depth then we must bring them to the same depth 
 * 
 * so u is at a depth of 5 and v is at depth of 9 => from this we can do one thing so get the ancestor of v which is at a depth of 5 
 * the same depth of u => diff = 4 => so to get them at the same depth => binary lift u to its 4th ancestor 
 * and then when both are at the same depth we can just start lifting them up and when their ancestors match the first time => LCA 
 * 
 * How to lift them up togethor to get the LCA ?
 * start by jumping the max possible value => 2 ^ (LOG - 1) => max jump 
 * so basically if the LCA of two nodes is their 10th ancestor => then we will not jump 1 then 2 or then 4 
 * we will try to jump the max possible then try smaller ones 
 * if we make smaller jumps first then the ans might overshoot
 * 
 * for(int j = LOG-1; j >= 0; j--) => if their 2^j th ancestor is different then make the jump 
 * and then try making smaller jumps to reach the lca
 * 
 * In other queries we knew what jumps we were supposed to make => here we are guessing the jumps to be made 
 */

class LCA {
private:
    int LOG;
    vector<int> depth;
    vector<vector<int>> up;

    // using the adjacency list and dfs make the parent vector => parent of each node = up[node][0]
    // and update the depth vector => useful for getting lca

    void bfs(vector<vector<int>> &adj) {
        int n = adj.size();

        queue<int> q;

        q.push(0);
        depth[0] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nbg: adj[node]) {
                // the nbg should not be the parent of node
                if(nbg == up[node][0]) continue;
                
                // parent of nbg is node and depth of nbg is depth of node + 1
                up[nbg][0] = node;
                depth[nbg] = depth[node] + 1;
                q.push(nbg);
            }
        }
    }
    
    LCA(int n, vector<vector<int>> &adj) {
        // assume the root to be node = 0
        LOG = 0;

        while((1 << LOG) <= n) LOG++;

        up.resize(n, vector<int>(LOG, -1));
        depth.resize(n, 0);

        // compute the depth and the parent = up[node][0]
        // depth[root] = 0 => using bfs compute the values
        bfs(adj);
        
        // now fill the up table for lifting lookups 
        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                // 2 ^ (j-1) jump should valid 
                if(up[i][j-1] != -1) {
                    int node = up[i][j-1];
                    up[i][j] = up[node][j-1];
                }
            }
        }
    }

    int lca(int u, int v) {
        // keep u at lower depth than v 
        if(depth[u] < depth[v]) swap(u, v);

        // Normalise the depths by lifting u to the same depth as of v => get the kth ancestor of u (k = diff) 
        int diff = depth[u] - depth[v];

        for(int j = 0; j < LOG; j++) {
            int jth_bit = diff & (1 << j);

            if(jth_bit) {
                // lift the node by making a jump of 2 ^ j
                u = up[u][j];
            }
        }

        // if u after lifting up = v then v is the LCA of the both nodes 
        if(u == v) return v;
        
        // binary lift both upwards => we dont which ancestor to go to, so we guess 
        // guess => first try making bigger jumps and then go to smaller jumps
        
        for(int j = LOG-1; j >= 0; j--) {
            // If their 2^j-th ancestors are different, jump both
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
            // If they're the same, we skip this jump and try smaller jumps
        }

        // after the loop ends u and v are siblings => have the same parent => this parent is the LCA 
        return up[u][0];
    }
};