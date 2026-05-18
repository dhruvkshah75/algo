#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
// IMPORTANT Question on divide and conquer, linked list and binary search tree 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // similar to building a height balanced bst from a sorted array 
    TreeNode* buildBST(ListNode* left, ListNode* right) {
        // base case when range is empty
        if(left == right) 
            return nullptr;

        // now we calculate the mid pointer 
        ListNode* slow = left;
        ListNode* fast = left;

        while(fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow points to the mid in the linked list

        TreeNode* root = new TreeNode(slow->val);

        // we do this so we didnt skip out the last element 
        if(fast != right) 
            fast = fast->next;

        // recursively connect the root's left to and right
        root->left = buildBST(left, slow);
        root->right = buildBST(slow->next, right);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        // we call the function for start to nullptr
        return buildBST(head, nullptr);
    }
};
