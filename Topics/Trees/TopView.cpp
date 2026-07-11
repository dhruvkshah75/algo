// ==================================================== Binary Trees ===========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://takeuforward.org/plus/dsa/problems/top-view-of-bt

/* Explanation: bfs => level order traversals 
   we use level order traversal and by marking each node with its horizontal distance HD 
   if node = HD => then left child has HD-1 and right child has HD+1
   and we can use a map to store the [key = HD, val = node value] so the map arranges the view in correct order

   We add the first occurrence of some node at a newer horizontal distance => top view of the binary tree 
   when we add the last occurrence (latest occurence) of some node at horizontal distance => bottom view of the binary tree 
*/

struct TreeNode {
	int val;
	TreeNode* left, right;
	TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution{
public:
    vector<int> topView(TreeNode *root){
        
        vector<int> res;

        map<int,int> mp;
        // mp[horizontal distance] = node 

        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        // start with the root with hd = 0

        while(!q.empty()) {
        	auto [node, hd] = q.front();
        	q.pop();

        	if(mp.find(hd) == mp.end())
        		mp[hd] = node->val;

        	if(node->left != nullptr) q.push({node->left, hd-1});
        	if(node->right != nullptr) q.push({node->right, hd+1});
        }

        for(auto [hd, node]: mp) res.push_back(node);
    }
};

