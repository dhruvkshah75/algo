#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/delete-node-in-a-bst/description/
// standard node deletion question 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
    // finds the minimum in the bst => keeps going into the left subtree
    TreeNode* find_min(TreeNode* root) {
        if(root->left == nullptr) 
            return root;

        return find_min(root->left);
    }

    TreeNode* delNode(TreeNode* root, int key) {
        // base case: key node not found 
        if(root == nullptr) 
            return nullptr;

        if(root->val > key) {
            // the key must be in the left subtree
            // reassign the left child to deletion result 
            root->left = delNode(root->left, key);
        }
        else if(root->val < key) {
            // the key node must be in the right subtree 
            // reassign the right child with the result of deletion 
            root-> right = delNode(root->right, key);
        }
        else {
            // we found the key 
            // case 1: The key node is the leaf node 
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // case 2: The key Node has 1 child 
            // case 2a: the key has left child 
            else if(root->right == nullptr) {
                TreeNode* temp = root->left;
                // delete the key nide
                delete root;
                // now return the child of the key node to connect it to its parent
                return temp;
            }

            // case 2b: the key has only right child 
            else if(root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                // return the child of the key node to connect to its parent 
                return temp;
            }

            // case3: has both children 
            else {
                // we find the successor to the key => which is the min in the right subtree
                TreeNode* curr = root;
                TreeNode* successor = find_min(root->right);

                curr->val = successor->val;
                // we delete the successor node by calling the same function 
                curr->right = delNode(curr->right, successor->val);
            }
        }
        // safety return for the case 3 => when key has both children 
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return delNode(root, key);
    }
};
