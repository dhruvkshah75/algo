#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/balance-a-binary-search-tree/description/
// IMPORTANT Question => build a tree using divide and conquer approach  

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Time Complexity => O(N) as we are building the tree from sorted array 

class Solution {
    vector<int> tree;

    void inorder(TreeNode* root) {
        if(root == nullptr) 
            return;
        
        inorder(root->left);
        tree.push_back(root->val);
        inorder(root->right);
    }

    // recursively we will form the tree => divide and conquer approach 
    TreeNode* buildBalanced(int l, int r) {
        // base case: stop when the range is invalid 
        if(l > r)
            return nullptr;

        int mid = l + (r - l) / 2;

        TreeNode* node = new TreeNode(tree[mid]);

        // recursivly call the left half of the array and the right half of the array 
        node->left = buildBalanced(l, mid - 1);
        node->right = buildBalanced(mid + 1, r);

        // Return the node so it can be attached to its parent
        return node;
        // at the end the main root is always returned as the last call stack remains 
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr)
            return root; 

        tree.clear();
        inorder(root);
        // now the vector tree is filled with the elements in sorted order using inorder traversal 

        int n = tree.size();
        // make the middle element as the root 
        return buildBalanced(0, n-1);
    }
};