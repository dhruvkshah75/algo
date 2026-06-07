// ======================================================== Binary Trees ========================================================

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// question link: https://leetcode.com/problems/balanced-binary-tree/description/

/* Very Important Logic: 
   apply dfs return the height and check if the the height diff of left child and right child is not more than 1
   If not then return -1 => if either child returns -1 then the tree is not height balanced then send this -1 above 
*/

// ================================ Important Question ==============================================================
// solved using the height calculation 

class Solution {
private: 
    int dfs(TreeNode* root) {
        // base case: when null root is reached 
        if(root == nullptr) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // left and right subtrees could be height balanced 
        if(left != -1 && right != -1) {
            // check if this subtree is height balanced => if yes then return the height for future calculations 
            if(abs(left - right) <= 1) return 1 + max(left, right);
            else return -1;
        }
            
        // either of node returns -1 
        return ((left == -1) ? left : right); 
    }

public:
    bool isBalanced(TreeNode* root) {
        int temp = dfs(root);

        return (temp == -1) ? false : true;
    }
};