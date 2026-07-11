// ============================================ binary trees -> bfs ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/* Explanation: bfs to build the the graph and bfs to get all the nodes at a distance of k 
   when we talk about all the nodes at a distance of k from the target node 
   it means that when we apply bfs from the target node to reach all other nodes such that level <= k
   distance in bfs = level 
   Note: all the nodes.val are unique so they can be marked as the node value
*/

class Solution {
private:
    vector<vector<int>> adj;

    void buildGraph(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left != nullptr) {
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                // add the edge in adj 

                q.push(node->left);
            }

            if(node->right != nullptr) {
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);

                q.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // since we dont know how many nodes in the tree assign the adj with a size of 500
        adj.resize(501);

        buildGraph(root);

        // apply bfs from target node till the level of the traversal = k and maintain a vis array to prevent infinte loop 
        vector<bool> vis(501, false);
        queue<int> q;
        vector<int> res;

        q.push(target->val);
        vis[target->val] = true;

        int level = 0;

        while(!q.empty()) {
            int qSize = q.size();

            while(qSize--) {
                int node = q.front();
                q.pop();

                if(level == k) res.push_back(node);

                for(int nbg: adj[node]) {
                    if(vis[nbg]) continue;

                    q.push(nbg);
                    vis[nbg] = true;
                }
            }
            level++;
        }

        return res;
    }   
};