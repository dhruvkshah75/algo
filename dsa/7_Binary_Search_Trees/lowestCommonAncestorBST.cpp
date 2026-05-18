#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
// IMPORTANT Question => based on the traversal 

/*
    The Lowest common ancestor is the node when p and q go in different subtrees of the current node 
    We simply traverse only to that side where both p and q lie rather than traversing through the entire BST 
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

// Time Complexity: O(h) => Height of the tree 

class Solution {
    TreeNode* lca;      // this is the lowest common ancestor 

    // p is smaller than q => for this traversal and check 
    void traverse(TreeNode* root, int p, int q) {
        if(root == nullptr)
            return;

        int rootVal = root->val;

        // if p and q lie on either subtrees  
        // if p or q is the root then lca is the root and return
        if(p <= rootVal && q >= rootVal) {
            lca = root;
            return;
        }
        else if(rootVal > p && rootVal > q) {
            // both lies in the left subtree
            traverse(root->left, p, q);
        }   
        else {
            // p and q lies in the right subtree => so only traverse in the right 
            traverse(root->right, p, q);
        } 
        return;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // the lowest common ancestor will the node where p goes left and q goes right 
        // knowing that p is smaller than q  
        lca = nullptr;

        // keep the p as smaller than q for checking purposes during traversal 
        // keep the min as second argument and max as the third argument 
        traverse(root, min(p->val, q->val), max(p->val, q->val));

        return lca;
    }
};




