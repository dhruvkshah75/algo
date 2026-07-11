// ================================================== binary trees =========================================

#include<bits/stdc++.h>
using namespace std;

// ========================= build binary tree from preorder and inorder traversal ====================================

// question link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

/* Explanation: binary trees + divide and conquer
 * 
 * preoder => root (left substree) (right subtree)
 * inorder => (left subtree) (right subtree) 
 * We can recursively make calls to generate the binary tree by identifying the left and right subtree 
 * in each recursive call
 * 
 * Time Complexity = O(N) as we recursively divide the array into two halves => like building the tree so every single node is visited once 
 * in the worst case can become O(N) if the binary tree is skewed
 * 
 * prefill this inorder array into a map to get the indices  
 * store the indices of the inorder to get the location of the root of the current subtree in inorder in O(1) query 
 * this helps to get the number of elements in the left subtree and using this we can get the mid1 and mid2 indices 
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};


class Solution {
private:
	int n;
	unordered_map<int,int> mp;

	TreeNode* divNconq(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2) {
		// base case: invalid segment call 
		if(l1 > r1) return nullptr;

		// base case: when segment only contains 1 element 
		if(l1 == r1) return new TreeNode(preorder[l1]);
		
		// l1, r1 => block of preorder sequence and l2, r2 => block of inorder sequence 
		int root_val = preorder[l1];
		TreeNode* root = new TreeNode(root_val);

		int mid2 = mp[root_val];

		// using the number elements in the left subtree from the inorder seq => we get the mid1
		int sz_left = mid2 - l2;
		int mid1 = l1 + sz_left;

		// preorder => [l1+1...mid1] [mid1+1...r1] 
		// inorder => [l2...mid2-1] [mid2+1...r2] => mid2 = root of current subtree

		root->left = divNconq(preorder, inorder, l1+1, mid1, l2, mid2-1);
		root->right = divNconq(preorder, inorder, mid1+1, r1, mid2+1, r2);

		return root;
	}
	// Time Complexity = O(N)

public: 
	TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
		n = preorder.size();

		for(int i = 0; i < n; i++) 
			mp[inorder[i]] = i;

		return divNconq(preorder, inorder, 0, n-1, 0, n-1);
	}
};


// =================================================== build binary tree from inorder and post order traversal ==================================================

// question link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/* Explanation: binary trees 
 * postorder = (left subtree) (right subtree) root 
 * inorder = (left subtree) root (right subtree)
 *
 * store the value and index key, value pairs in a map to get the index of the root in the post order traversal 
 * so we can get the mid1 and mid2 => to get the number of elements in the left and right subtree 
 * int index = mp[root_val] => from this index we get the number of elements in the left subtree 
 */

class Solution {
private:
	int n;
	unordered_map<int,int> mp;

	TreeNode* divNconq(vector<int> &inorder, vector<int> &postorder, int l1, int r1, int l2, int r2) {
		// base case: invalid segment 
		if(l1 > r1) return nullptr;

		// segment contains only element 
		if(l1 == r1) return new TreeNode(inorder[l1]);

		int root_val = postorder[r2];
		TreeNode* root = new TreeNode(root_val);

		int mid1 = mp[root_val]; 

		int sz_right = r1 - mid1;
		int mid2 = r2 - sz_right;

		// inorder => [l1...mid1-1] [mid1+1...r1]
		// postorder => [l2...mid2-1] [mid2...r2-1]
		root->left = divNconq(inorder, postorder, l1, mid1-1, l2, mid2-1);
		root->right = divNconq(inorder, postorder, mid1+1, r1, mid2, r2-1);

		return root;
	}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();

        for(int i = 0; i < n; i++) 
        	mp[inorder[i]] = i;

       	return divNconq(inorder, postorder, 0, n-1, 0, n-1);
    }
};