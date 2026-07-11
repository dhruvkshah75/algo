// ============================================================= Binary SearcH Trees =================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/serialize-and-deserialize-bst/description

/* Explanation: BST 
 * Serialising the BST is easy => preorder sequence of BST 
 * 
 * Deserisalize BST => more tougher part in here 
 * We could use the better approach that strictly uses O(N) approach to build the tree from the preorder
 * 
 * use the Bound stratergy => (lower_bound, upper_bound) 
 * starting with the root => call the next element with index+1 and in the left subtree (-inf, root)
 * and for the right subtree we can with the bound of (root, +inf)
 * And using this Bound logic no extra overhead in the recursive function => so the recursive function is called for 
 * each node exactly once 
 * */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {} 
};


class Codec {
private:
	TreeNode* buildTree(string &preorder, int lb, int ub, int &ind) {

		if(ind == preorder.length()) return nullptr;

		// extract the current number starting at preorder[ind]
		int j = ind;

		string curr = "";
		while(j < preorder.length() && preorder[j] != ' ') {
			curr += preorder[j];
			j++;
		}

		int num = std::stoi(curr);

		// base case: the current node does not lie in the current bound
		if(num <= lb || num >= ub) return nullptr;

		// skip the ' ' and move to the start of the next number 
		ind = j+1;

		TreeNode* root = new TreeNode(num);

		root->left = buildTree(preorder, lb, num, ind);
		root->right = buildTree(preorder, num, ub, ind);

		return root;
	}

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // base case: nullptr is reached 
        if(!root) return "";

        // add space between each node 
        string seq = "";
        seq += std::to_string(root->val) + " ";
        seq += serialize(root->left) + serialize(root->right);

        return seq;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data) {
    	int ind = 0;

        return buildTree(data, INT_MIN, INT_MAX, ind);
    }
};
