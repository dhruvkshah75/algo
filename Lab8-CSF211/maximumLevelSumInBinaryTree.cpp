#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

// simple bfs traversal in binary tree


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // we apply bfs and a vector to store the level sum 

        unordered_map<int,int> levelSum;
        
        int level = 1;

        queue<TreeNode*> q;
        q.push(root);
        levelSum[1] += root->val;

        while(!q.empty()) {
            int qSize = q.size();
            while(qSize--) {
                TreeNode* curr = q.front();
                q.pop();

                // now push the nbgs 
                if(curr->left != nullptr) {
                    q.push(curr->left);
                    levelSum[level+1] += curr->left->val;
                }

                if(curr->right != nullptr) {
                    q.push(curr->right);
                    levelSum[level+1] += curr->right->val;
                }
            }
            level++;
        } 
        
        int result = 1, maxSum = INT_MIN;
        unordered_map<int,int>::iterator it = levelSum.begin();
        for(; it != levelSum.end(); it++) {
            auto [level, sum] = *it;
            if(sum >= maxSum) {
                maxSum = sum;
                result = level;
            }
        }

        return result;
    }
};