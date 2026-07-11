// =========================================== bfs + BT ======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/binary-tree-right-side-view/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// ===================== VERY IMPORTANT CONCEPT of how queues behave in the BT level order traversal =============

/* Explanation: bfs + BT
   here we want the right side view => i.e. the rightmost element in that level of the tree 
   so we can apply a level order traversal and move level by level and then 
   for each level we can just get the element in the back of the queue and add it to the result 
   as the back of the queue is the rightmost element in the queue 
*/


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // base case: empty tree 
        if(root == nullptr) return {};

        // each level or depth will have only one element in right view
        
        queue<TreeNode*> q;
        q.push(root);

        // res = right view of the queue 
        vector<int> res;

        while(!q.empty()) {
            int qSize = q.size();

            // rightmost element of the current level will be in the back of queue 
            int rightmost = q.back()->val;
            res.push_back(rightmost);

            while(qSize--) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr) q.push(node->left);

                if(node->right != nullptr) q.push(node->right);
            }
        }

        return res;
    }
};

