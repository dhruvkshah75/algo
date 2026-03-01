#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

// Time Complexity: O(n)

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* buildBST(vector<int> &nums, int l, int r) { 
        // base case when the l and r range becomes invalid 
        if(l > r)   
            return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        // recursively call for left and right subarray of nums 
        node->left = buildBST(nums, l, mid-1);
        node->right = buildBST(nums, mid+1, r);

        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // convert the given sorted array into a hegiht balanced bst 
        // the mid will the root 
        int n = nums.size();

        return buildBST(nums, 0, n-1);
    }
};