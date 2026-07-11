// ============================================== bfs ==============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/* Explanation: bfs (level order traversal) 
   we must connect every node in the same level with its prev value 
   so use the property of the level order traversal which connects two nodes 
   eg1 => at depth = 2 => queue will look like [4, 5, 6, 7] 
   so make 4 as prev and then connect prev->next to curr_node which is 5
   in this way we can connect the nodes in the tree
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int qSize = q.size();
            // use the prev to connect prev to the curr node
            Node* prev = NULL;

            while(qSize--) {
                Node* node = q.front();
                q.pop();

                if(prev != NULL) prev->next = node;
                // make the current node as the prev for next iteration
                prev = node;

                // add the children to queue 
                if(node->left != NULL) q.push(node->left);

                if(node->right != NULL) q.push(node->right);
            }
        }

        return root;
    }
};