#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// Time Complexity = O(K + h)
// where h is the height of the tree 



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    int count = 0;
    int result = -1;
    // gives the numbers in sorted order 
    void inorderTraversal(TreeNode* root, int k) {
        // base case to stop recursive calls => i.e. if we reached the end then stop 
        if(root == nullptr)
            return;

        // call the right subtree 
        inorderTraversal(root->left, k);
        // the root->val encountered
        count++;
        if(count == k) {  // check if we found our element 
            result = root->val;
            return;
        }
        // call the right subtree 
        inorderTraversal(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // we use inorder traversal in bst 
        inorderTraversal(root, k);

        return result;
    }
};