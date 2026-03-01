#include<bits/stdc++.h>
using namespace std;

// question link: 
// IMPORTANT DESIGN Question 

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

/*
    Since we are supposed to have inorder Traversal we intially push all the left nodes of the root 
    into the stack and when we pop the stack we check if the top node has right child or not 
    if the node has right child then we push all its left nodes in the stack and we do the same thing 

    Average Time Complexity: O(1) for next() operatiion 
    Space Complexity: O(h) => h = height of the tree as at once and max the stack only contains 
                              h number of nodes in it 
*/

class BSTIterator {  
    stack<TreeNode*> st; 

    // push the current node and all its left children in the stack 
    void pushNodesLeft(TreeNode* node) {
        while(node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        st = stack<TreeNode*>();
        pushNodesLeft(root);
    }
    
    int next() {
        TreeNode* topNode = st.top();
        st.pop();

        // if topNode has right node we must push all left nodes of the right subtree in the stack 
        if(topNode->right != nullptr) {
            pushNodesLeft(topNode->right);
        }

        return topNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */