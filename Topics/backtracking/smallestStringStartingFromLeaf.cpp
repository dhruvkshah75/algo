// ==================================================== dfs + backtracking ===================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/smallest-string-starting-from-leaf/description

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* Explanation: dfs + backtracking 
   using backtracking form all the possible strings and then when the leaf node is reached 
   then just compare the this current string with the resulting string for which one of them 
   is lexicographically smaller => note the string will be in reverse direction */

class Solution {
private:
    string res;

    void f(TreeNode* node, string &curr) {
        if(node == nullptr) return;

        // add the current node to the string 
        char c = node->val + 'a';
        curr.push_back(c);

        // case of exploring further or stopping if leaf node 
        if(node->right == nullptr && node->left == nullptr) {
            if(res.empty() || isSmaller(curr, res)) res = curr;
            return;
        }
        else {
            f(node->left, curr);
            f(node->right, curr);
        }

        // backtrack 
        curr.pop_back();
    } 

    bool isSmaller(string &a, string &b) {
        // return true if a is lexicographically than b => in reverse direction 
        int i = a.length()-1, j = b.length()-1;

        while(i >= 0 && j >= 0) {
            // first char where a and b differ 
            if(a[i] != b[j]) return a[i] < b[j];
            i--;
            j--;
        }

        // if one string runs out then shorter reverse string is lexicographically smaller 
        return a.length() < b.length();
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        res = "";

        string curr = "";
        f(root, curr);

        reverse(res.begin(), res.end());
        return res;
    }
};