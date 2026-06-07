// ======================================================== Binary Trees ========================================================

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// question link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

/* Returning the max depth of the BT => number of nodes in a path from the root 
   use recursion to solve this 
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // null is reached => means no node is left so return 0
        if(root == nullptr) return 0;

        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);

        return max(left, right);
    }
};