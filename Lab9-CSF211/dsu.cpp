#include<bits/stdc++.h>
using namespace std;

/*
    DSU is a data structure 
    What is DSU (Disjoint Union Set) or Union Find ?
    How does it work 

    if there are 2 connected components and someone asks if node 1, node 5 are of the same group or not 
    DSU helps to solve this constant time O(1)

    2 main things DSU does => find parent() and union() by rank and size 

    union() goes and connects two things 

    Union is based on => 1. Rank and 2. Size 
*/

// union based on rank 
/*
    Union(u, v)
    1. Find ultimate parent of u, v => pu and pv 
    2. find rank of pu, pv 
    3. connect smaller rank to larger rank (always)
       if rank is same connect in any way 
       After connecting we must update the rank and the parent of node 
       
    find => we must compare their ultimate the parent => if same then belong to the same component 

    We apply path compression to make the time constant 
    so if 4 -> 6 -> 7 ==> parent of 7 is 6 and parent of 6 is 4 and we are dealing only with parents 
    so update the parent of 7 to be 4 so this is path compression 

    Edges are formed on the basis of parent connections 
    Expand the tree to have least number of levels rather than it being longer  

    rank => default = 0
    parent => default = i (parent of itself)

    While path compression we cannot update the rank (as rank will technically decreases)

    if(rank_[pu] == rank_[pv]) rank_[pu]++;
    only increase if rank is same otherwise pu's rank is already bigger than pv's rank so connection of 
    doesnt increase the rank of pu 

    Union by rank — always attach the shorter tree under the taller one, keeping the tree flat

    When UnionByRank() returns false => means already a part of the same group 
*/

struct DSU {
    vector<int> parent, rank_;

    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);  // parent[i] = i
    }

    // find => find the parent and do path compression
    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]);  // path compression while calling find 
        }

        return parent[u];
    }

    bool unionByRank(int u, int v) {
        // first find all ultimate parent of u, v 
        int pu = find(u), pv = find(v);

        if(pu == pv) return false;  // already of the same connected 

        // union by rank => keep pu as the bigger one 
        if(rank_[pu] < rank_[pv]) swap(pu, pv);
        parent[pv] = pu;    // pv is connected to pu (rank of pv is less than pu)
        if(rank_[pu] == rank_[pv]) rank_[pu]++;
        
        return true;
    }

};


// ============================================================================
//              DSU union by size 
// ============================================================================
/*
    Size array => default => 1 as all nodes initially have size 1 
*/

struct DSU {
    vector<int> size, parent;

    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]);   // apply path compression
        }
        return parent[u];
    }

    // union by size 
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        // same ultimate parent already of the same component 
        if(pu == pv) return false;

        // union by size => attach the smaller tree to the larger tree 
        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];   // update the size of the root = pu 

        return true;
    }
};