#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/validate-binary-search-tree/description/

// Time Complexity: O(N)
// VERY IMPORTANT QUESTION => for recursive calls for bst 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    // we must maintain a range that the current root must lie in 
    bool validate(TreeNode* root, long long min_val, long long max_val) {
        // base case when the root is null then it is a valid bst 
        if(root == nullptr)
            return true;

        if(root->val <= min_val || root->val >= max_val) 
            return false;

        // if we go into the left subtree => range = [min_val, root->val]
        // for the right subtree => range will be [root->val, max_val]
        // we return the && of the bool returned by right and left traversal => 
        // if any one recursive call gives false the entire ans becomes false
        return (
            validate(root->left, min_val, (long long)root->val) && 
            validate(root->right, (long long)root->val, max_val)
        );
    }

public:
    bool isValidBST(TreeNode* root) {
        // left subtree must be smaller than root and right subtree must be greater than the root 
        // so we maintain allowed value of range starting 
        // Long min and max as we can have the values as int min and int max 
        return validate(root, LONG_MIN, LONG_MAX);
    }
};