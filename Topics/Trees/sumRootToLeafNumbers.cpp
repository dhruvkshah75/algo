// ========================================== binary trees + dfs + backtracking ==========================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* Explanation: dfs + backtracking
   Since the question mentions the max depth of the tree <= 10 so we can easily maintain a string and keep a track of the string 
   or the numbers followed and then we can easily convert the string into a number and then add it up into the result 
   note dont keep the base case as the node == nullptr as this counts a single string multiple times 
   keep the base case as the leaf node 
*/

class Solution {
private:
    int res;

    void dfs(string &curr, TreeNode* node) {

        // add the current node to the string and add the result
        curr.push_back(node->val + '0');

        // when the node is a leaf node => cant go further
        if(node->left == nullptr && node->right == nullptr) {
            int num = std::stoi(curr);
            res += num;
        }
        else {
            if(node->left != nullptr) dfs(curr, node->left);
            if(node->right != nullptr) dfs(curr, node->right);
        }

        // backtrack 
        curr.pop_back();
    }

public:
    int sumNumbers(TreeNode* root) {
        res = 0;      

        string curr = "";
        dfs(curr, root);

        return res;  
    }
};