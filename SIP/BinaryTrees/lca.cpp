// ======================================================== Binary Trees ========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// =================================================== Very Important Question =================================================

/* Apply simple dfs traversal => as soon as the required node is reached => return that node 
   If p or q not found then simply return nullptr and in backtracking when both returned values are p and q then that is the lca 
   If p or q is found simply return that node => then the node whose both left and right child return non null values is the lca 
   If one child is not null then return that child
*/

class Solution {
private: 
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case: node is null then return null
        if(root == nullptr) return nullptr;

        // found the node we were searching for return that 
        if(root == p || root == q) return root;

        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        // if both left and right are not null then current root is the lca 
        if(left != nullptr && right != nullptr) 
            return root;

        // case: when either p or q itself is the lca => either child will return not-null
        if(left != nullptr) return left;
        else return right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};