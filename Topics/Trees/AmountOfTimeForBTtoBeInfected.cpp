// ================================================== Binary Tree ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* Explanation: bfs
   convert the given tree into a undirected graph and then apply bfs from the 
   solve using parent mapping and bfs instead of building the entire adjacency list

   Important Question => concept of using parent mapping to apply bfs
*/

class Solution {
private:
    unordered_map<TreeNode*,TreeNode*> parent;
    TreeNode* startNode;

    void dfs(TreeNode* node, int start) {
        if(node == nullptr) return;

        // connect the leftm right child to thier parent that is node

        if(node->val == start) startNode = node;

        if(node->left) {
            parent[node->left] = node;
            dfs(node->left, start);
        }

        if(node->right) {
            parent[node->right] = node;
            dfs(node->right, start);
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {

        // build the undirected graph from the given binary tree
        parent[root] = nullptr;
        dfs(root, start);

        unordered_set<TreeNode*> vis;

        // now apply bfs from the start node and using the parent mapping
        queue<TreeNode*> q;
        q.push(startNode);
        vis.insert(startNode);

        // each node can have exacly 3 neighbours => node->left, node->right and parent[node]
        int time = -1;

        while(!q.empty()) {
            int qSize = q.size();

            while(qSize--) {
                TreeNode* node = q.front();
                q.pop();    

                // try moving to all its 3 neighbours

                if(node->left && !vis.count(node->left)) {
                    q.push(node->left);
                    vis.insert(node->left);
                }

                if(node->right && !vis.count(node->right)) {
                    q.push(node->right);
                    vis.insert(node->right);
                }

                if(parent[node] && !vis.count(parent[node])) {
                    q.push(parent[node]);
                    vis.insert(parent[node]);
                }
            }
            time++;
        }

        return time;
    }
};