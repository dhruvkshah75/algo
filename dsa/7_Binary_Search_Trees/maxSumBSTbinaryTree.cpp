#include<bits/stdc++.h>
using namespace std;

// question link: 
// LEETCODE HARD: VERY IMPORTANT Question on BSTs 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    We use postorder => which means for a root i will have traversed its left and right subtrees
    so with the given information whether it is bst then only we do it for the parent 

    If we do inorder or preorder Treversal then validate the bst 
    inorder => get the knowledge of all the left children we do 
    N + N-1 + N-2 + ..... + 1 = (N * (N + 1)) / 2; ==> O(N^2)

    To prevent this we use postorder where we already know all about its left and right child 
    so we just do postorder traversal 
*/

// Time Complexity: O(N)

// we store this for all the nodes to prevent O(N^2)
struct NodeInfo {
    bool isBST;
    int sum;
    int minVal;    // store the minVal and maxVal in that bst 
    int maxVal;
};

class Solution {
    int maxSum = 0;

    NodeInfo validateAndGetInfo(TreeNode* root) {
        // base case [] => a valid bst with sum = 0
        // VERY IMPORTANT BASE CASE STEP
        // we check if root > left tree maxval (should be intMin) and for right subtree (should be intmax)
        if(root == nullptr) 
            return {true, 0, INT_MAX, INT_MIN};

        // we use postorder traversal as we only check for the those nodes if its children are 
        // valid BSTs => not by traversing through it => we compare it with only its left and right childs

        // get all the info for the left and right subtrees 
        NodeInfo leftTree = validateAndGetInfo(root->left);
        NodeInfo rightTree = validateAndGetInfo(root->right);

        // now we know that the left and right subtree are valid bst or not 
        if(leftTree.isBST && rightTree.isBST) {
            // now we check if including the root is the entire thing a valid BST
            // the root must lie in (left.maxVal, right.minVal)
            if(root->val > leftTree.maxVal && root->val < rightTree.minVal) {
                int curSum = root->val + leftTree.sum + rightTree.sum;
                maxSum = max(curSum, maxSum);

                return {
                    true, 
                    curSum, 
                    // the entire bst will have the min value as leftTree.minVal
                    min(root->val, leftTree.minVal),
                    max(root->val, rightTree.maxVal)
                };
            }
        }

        // the code reaches here then the entire tree with the current root is not valid 
        // if that is invalid then no bigger part of it will be a valid BST ever 
        return {false, 0, 0, 0};  
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;

        NodeInfo ans = validateAndGetInfo(root);

        return maxSum;
    }
};