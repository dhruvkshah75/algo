// ============================================== dfs + backtracking ==========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/path-sum-ii/

/* Explanation dfs + backtracking 
 * Here we must select a path from root to leaf node 
 * Note about one thing is we cannot res.push_back() when curr == nullptr => as the issue is a leaf node has two children (nullptr)
 * so each valid path will be added twice to the result 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int target;
    vector<vector<int>> res;

    void f(vector<int> &path, int curr_sum, TreeNode* curr) {
        if (curr == nullptr)
            return;

        // add the current node to the path 
        path.push_back(curr->val);

        if(curr->left == nullptr && curr->right == nullptr) {
            // leaf node reached => add if sum = target
            if(curr_sum + curr->val == target) res.push_back(path);    
        }
        else {
            // try exploring the left and right paths to get the sum 
            f(path, curr_sum + curr->val, curr->left);
            f(path, curr_sum + curr->val, curr->right);
        }

        // backtrack 
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;

        vector<int> path = {};
        f(path, 0, root);

        return res;
    }
};