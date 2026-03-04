#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/recover-binary-search-tree/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    When non adjacent nodes in the inorder traversal are swapped then there are 2 disruptions in the  
    sorted order of the array 
    [1, 2, 3, 4, 5, 6, 7] => this is the inorder traversal form 
    when two non adjacent nodes in the array are swapped then 
    eg. 2 and 6 
    [1, 6, 3, 4, 5, 2, 7] 
    => so we find both the nodes and then swap them out 
    when adjacent nodes are swapped then => only one diruption occurs 
    eg. swap 3, 4
    [1, 2, 4, 3, 5, 6, 7]
*/
class Solution {
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if(root == nullptr)
            return;

        inorder(root->left);
        // we found the first swap error 
        if(prev != nullptr && prev->val > root->val) {
            // the prev points the bigger and the root points the dip after the prev
            // first catches the bigger element 
            if(first == nullptr) {
                // if this is the first disruption then 
                first = prev;
            }
            // store the second as the curr => if there are two disruptions then this will overwrite 
            // second represents the smaller element after the bigger (disruption)
            second = root;
        }
        // update the previous pointer and then call the right subtree
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // the inorder traversal returns a sorted order of values 
        // => swapping elements causes disruptions in the order they are printed  
        inorder(root);

        /*  
            NON_ADJACENT NODES SWAPPED
            after the inorder traversal it store the first = bigger element of the first disruption 
            and second = smaller element after the second disruption => this is what we must swap 

            ADJACENT NODES SWAPPED 
            only one disruption then bigger and then a smaller element after this 
            first denotes the bigger element of the disruption and second points the smaller after the 
            bigger that must be swapped
        */
        swap(first->val, second->val);
    }
};