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

// question link: https://leetcode.com/problems/same-tree/description/


class Solution {
    bool preorder(TreeNode* p, TreeNode* q) {
        // for each node check its nbg configuration and node value 
        if(p == nullptr && q != nullptr || p != nullptr && q == nullptr)
            return false;
        else if(p == nullptr && q == nullptr)
            return true;

        if(p->val != q->val) 
            return false;
        
        return (preorder(p->left, q->left) && preorder(p->right, q->right));
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // preorder traversal in both of them at the same time 
        return preorder(p, q);
    }
};