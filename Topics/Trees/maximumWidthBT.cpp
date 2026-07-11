// ================================================= bfs + Binary Trees ==========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/

// ====================================== VERY IMPORTANT LOGIC ===============================

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* Explanation: bfs on trees 
   Explore all the nodes depth by depth and consider the col of each parent as n 
   then the left child be regarded as 2n and right child will be 2n + 1
   (full binary tree concept)
   depeding on this in each level get the max_col and min_col for this 
   and then width = max_col - min_col + 1 => only check this if max_col and min_col
*/

typedef long long ll;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        // define cols for each node 
        // node->left = parent_col - 1 and node->right = parent_col + 1

        queue<pair<TreeNode*,ll>> q;
        q.push({root, 1});

        ll max_width = 0;

        while(!q.empty()) {
            int qSize = q.size();

            // since we travel level by level 
            // leftmost and rightmost node in this level will be the front of the queue and back of queue 
            ll start = q.front().second;
            ll end = q.back().second;

            // update the max width 
            max_width = max(max_width, end-start+1);

            while(qSize--) {
                auto [node, col] = q.front();
                q.pop();

                // make a shift in every index of the nodes in the current level 
                // make the left node = 0, rightmost node => end - start
                ll idx = col - start;

                if(node->left != nullptr) {
                    q.push({node->left, 2 * idx});
                } 

                if(node->right != nullptr) {
                    q.push({node->right,  2 * idx + 1});
                }
            }
        }

        return (int)max_width;
    }
};