#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
 * Syntax reference for binary tree nodes:
 *
 * Node* n = new Node(val);  // Create a new node
 * int x = n->data;          // Access the node's value
 * n->left = ...;            // Set left child
 * n->right = ...;           // Set right child
 */

Node* lca;

void findEdges(Node* node, int val, int &edges) {
    if(node->data == val)
        return;

    if(node->data > val) {
        // val must lie in the left subtree
        edges++;
        findEdges(node->left, val, edges);
    }
    else {
        // val must lie in the right subtree 
        edges++;
        findEdges(node->right, val, edges);
    }

    return;
}

void findLCA(Node* root, int p, int q) {
    // here we assume that the p is greater than q 
    if(root == nullptr)
        return;

    // now check if p and q go in different directions or not 
    int rootVal = root->data;

    // q lies in the left node and p lies in the right node 
    if(rootVal <= p && rootVal >= q) {
        lca = root;
        return;
    }
    // both lie in the left subtree
    if(rootVal > p && rootVal > q) 
        findLCA(root->left, p, q);
    else 
        findLCA(root->right, p, q);
    

}

int solve(Node *root, int p, int q) {
    // we must find the node from where they go in different directions 
    lca = nullptr;

    // we keep the first argument as greater and the second as the smaller 
    findLCA(root, max(p, q), min(p, q));

    // now we have the lca of the two p and q

    // now we find the no of edges between p and lca and q and lca 
    int edge1 = 0;
    int edge2 = 0;
    findEdges(lca, p, edge1);
    findEdges(lca, q, edge2);

    return edge1 + edge2;
}