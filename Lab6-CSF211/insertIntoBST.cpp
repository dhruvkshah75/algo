#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void insertKey(TreeNode* root, int val) {
        // no base case as insertion always occurs 
        int rootVal = root->val;

        if(val < rootVal) {
            // must go into the left subtree or insert the val 
            if(root->left == nullptr) {
                root->left = new TreeNode(val);
                return;
            }
            // if there are more nodes then traverse there 
            insertKey(root->left, val);
        }
        else {
            // the val must go into the right subtree 
            if(root->right == nullptr) {
                root->right = new TreeNode(val);
                return;
            }

            insertKey(root->right, val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // base case when the bst is empty 
        if(root == nullptr) 
            return new TreeNode(val);
        
        // insertion always occurs at the end 
        insertKey(root, val);

        return root;
    }
};