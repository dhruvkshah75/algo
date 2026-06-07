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

// ================================================= Imporant Question ===========================================

// question link: https://leetcode.com/problems/diameter-of-binary-tree/description/

/* Explaination: Daimeter of tree => longest path bewteen two nodes 
   => If this were a graph then usinf 2 bfs method could be solved
   Here at each node we have the left and right subtree height => left, right 
   So at each node => the longest path including the current node would be left + right 
   Diameter would simply max of all such cases 
*/

class Solution {
private:
    int diameter;

    int dfs(TreeNode* root) {
        // base case: the root node is null 
        if(root == nullptr) return 0;

        // left and right indicates the height of left ans right subtrees 
        int left = dfs(root->left);
        int right = dfs(root->right);

        diameter = max(diameter, left + right);

        // height of the subtree rooted at root will be 1 + max of left and right subtree heights 
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        this->diameter = 0;

        int temp = dfs(root);

        return diameter;
    }
};