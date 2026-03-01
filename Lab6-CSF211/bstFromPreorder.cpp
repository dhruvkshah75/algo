#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
// Important question => based on how does the preorder sequence look like 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    // using divide and conquer method to make the bst 
    TreeNode* bstBuilder(vector<int>&nums, int l, int r) {
        if(l > r)
            return nullptr;

        // first element in the preorder sequence is the root
        int root = nums[l];
        TreeNode* node = new TreeNode(root);

        // find the index after with the right subtree starts 
        int j = l + 1;
        while(j <= r && nums[j] < root) j++;

        // now j points at the first element of the right subtree 

        // recursively call the for left and right subtrees  
        node->left = bstBuilder(nums, l+1, j-1);
        node->right = bstBuilder(nums, j, r);

        return node;
    }   

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // preorder seq => first element is root and left subtree and then the right subtree 
        int n = preorder.size();

        return bstBuilder(preorder, 0, n-1);
    }
};


