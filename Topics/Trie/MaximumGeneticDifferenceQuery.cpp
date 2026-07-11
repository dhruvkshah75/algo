// ========================================== dfs + bit tries ==================================================

#include<bits/stdc++.h> 
using namespace std;

// question link: https://leetcode.com/problems/maximum-genetic-difference-query/description/

/* Explanation: dfs + tries + backtracking 
   on backtracking erase the occurrrence of the number in the trie so we can answer the queries correctly 
   optimization step => since each number <= 2*10^5 so only store 18 bits in the bit trie 
   To include the functionality of removal numbers from the bit trie use the cntPrefix logic and add erase method 

   Time Complexity = O(18*(N + Q)) which is effectively O(N + Q)
*/

class BitTrie {
private:
    struct TrieNode {
        TrieNode* children[2];
        int cntPrefix;    // count of active numbers passing through

        TrieNode() : cntPrefix(0) {
            children[0] = children[1] = nullptr;
        }
    };

    TrieNode* root;

public:
    BitTrie() : root(new TrieNode()) {}

    void insert(int num) {
        TrieNode* node = root;

        for(int i = 17; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
            node->cntPrefix++;   // update the cnt as the number passes through this node 
        }
    }

    void erase(int num) {
        TrieNode* node = root;

        for(int i = 17; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // path will always be present the number was inserted
            node = node->children[bit];
            node->cntPrefix--;
        }
    }

    /* find the max xor of num with all elements in the trie with cntPrefix > 0 */
    int findMaxXOR(int num) {
        TrieNode* node = root;

        int max_xor = 0;

        // maximize the number of set bits (xor = 1) and note whether number exists or not 
        for(int i = 17; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite_bit = 1-bit;

            // only proceed with any choice if cntPrefix > 0
            if(node->children[opposite_bit] != nullptr && node->children[opposite_bit]->cntPrefix > 0) {
                // set the ith bit in max_xor 
                max_xor = max_xor | (1 << i);
                node = node->children[opposite_bit];
            }
            else if(node->children[bit] != nullptr && node->children[bit]->cntPrefix > 0) {
                node = node->children[bit];
            }
            else {  // no valid paths => this case will not be encountered 
                break;
            }
        }

        return max_xor;
    }
};

class Solution {
private:
    int n, root, q;
    vector<vector<int>> adj;
    BitTrie* trie;
    vector<int> res;
    vector<vector<pair<int,int>>> node_q;  
    // q[node] = vector of {value, original_idx}  => same node can have multiple queries 

    void dfs(int node) {
        // insert the current node into the trie 
        trie->insert(node);

        // answer all the queries related to this node 
        for(auto [val, original_idx]: node_q[node]) {
            int max_xor = trie->findMaxXOR(val);
            res[original_idx] = max_xor;
        }

        // recurse to all the children of the current node 
        for(int nbg: adj[node]) {
            dfs(nbg);
        }

        // backtrack => delete the insertion of node 
        trie->erase(node);
    }

public:
    vector<int> maxGeneticDifference(vector<int>& parent, vector<vector<int>>& queries) {
        n = parent.size(), q = queries.size();  
        // nodes are 0-n-1

        adj.resize(n);
        node_q.resize(n);
        res.resize(q);

        for(int i = 0; i < n; i++) {
            // parent[i] -> i
            if(parent[i] == -1) root = i;
            else adj[parent[i]].push_back(i);
        }

        // now we must store the queries such that we can access them by their nodes 
        for(int i = 0; i < q; i++) {
            int node = queries[i][0], val = queries[i][1];
            node_q[node].push_back({val, i});
        }

        trie = new BitTrie();

        // call the dfs to answer all the queries and backtrack to handle insertion and deletion of numbers in trie
        dfs(root);

        return res;
    }
};

/*
   could also use recursive lamda function => can slow down the code (not asymptotically)

   function<void(int)> dfs = [&](int node) {
   
   }

   this effectively translates to a lamda function whose return type is void and takes one input 
   same as void dfs(int node)
*/