// ======================================================== Binary Trees ========================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// question link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

// ================================================= Very Imporant Question ===========================================

/* Explaination: Solve using dfs 
   Very important Note in the followed path is that => we have two options at each step 
   1. path at the curr node is such that it can be extended to the curr nodes parent 
   2. path extends from left child to the right child and cannot be extended to its parent 
   Example 2 => resultant path is example of 2nd type of path => V shaped paths 

*/

class Solution {
private: 
    int maxSum = INT_MIN;

    int dfs(TreeNode* curr) {
        // base case: null node reached then return 0
        if(curr == nullptr) return 0;

        // if the subtree sum is neg then discard it start a new path
        int left = max(0, dfs(curr->left));
        int right = max(0, dfs(curr->right));

        // curr + left + right => path of 2nd type => V shaped paths 
        maxSum = max(maxSum, curr->val + left + right);

        // return the path sum of path type 1 
        return curr->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);

        return maxSum;
    }
};