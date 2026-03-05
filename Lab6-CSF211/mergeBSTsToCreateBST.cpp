#include<bits/stdc++.h>
using namespace std;

// question link: 

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    // we traverse through the main tree and validate bst and keep merging the roots to it 
    bool traverseAndMerge(TreeNode* node, int min_val, int max_val, unordered_map<int,TreeNode*>&root) {
        // if we reach nullptr then there is no problem 
        if(node == nullptr)
            return true;

        if(!(node->val > min_val && node->val < max_val)) return false;

        // now if we are at the leaf node then we must attach the root to it => 
        // since roots are unique so we only have one option to connect 
        if(node->left == nullptr && node->right == nullptr) {
            if(root.count(node->val)) {
                // we found the root that connects to this leave 
                node->left = root[node->val]->left;
                node->right = root[node->val]->right;

                // now since the root is attached remove it from the map
                root.erase(node->val);
            }
        }

        // after connecting a root to the leaf of the main tree then we go 
        return (
            traverseAndMerge(node->left, min_val, node->val, root) && 
            traverseAndMerge(node->right, node->val, max_val, root)
        );
    }

public:
    Solution() {
        ios_base::sync_with_stdio(false);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();

        if(n == 1)
            return trees[0];

        // the root value of the final binary tree does not appear in the leaves 
        unordered_map<int,TreeNode*> root;
        // we only need to track the values of the leaves 
        unordered_map<int,int> leaves;

        // populate the maps 
        for(int i=0; i < trees.size(); i++) {
            root[trees[i]->val] = trees[i];
            // also push the leaves of the curr tree
            if(trees[i]->left != nullptr) 
                leaves[trees[i]->left->val]++;

            if(trees[i]->right != nullptr)
                leaves[trees[i]->right->val]++;
        }

        // now we will find the root of the main tree   
        // the main root is the one => no leaves exist for this root 

        TreeNode* main = nullptr;

        for(int i = 0; i < n; i++) {
            int curr_root = trees[i]->val;
            if(leaves.find(curr_root) == leaves.end()) {
                main = trees[i];
                break;
            } 
        }

        if(main == nullptr)
            return nullptr;

        // remove the main root from the map
        root.erase(main->val);

        // now we have the main root node now we must merge all the other roots to it 
        // by applying depth first search and then sttich them togethor 

        // we must also keep validating our BST
        if(traverseAndMerge(main, INT_MIN, INT_MAX, root) && root.empty()) {
            return main;
        }

        return nullptr;
    }
};