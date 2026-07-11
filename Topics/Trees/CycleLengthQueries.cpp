#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/cycle-length-queries-in-a-tree/description

/* Explanation: trees 
 * This question can be solved using LCA 
 * finding the LCA => to get the length of thw cycle 
 * 
 * Given tree is a complete tree => 2^N - 1 nodes in it
 * Each node has 2 children => left child = 2 * val and right child 2 * val + 1 
 * parent of each node = floor(node_val / 2)
 * so the depth of each node is Log(N)
 *
 * depth[node] = Log(Val) 
 * 
 * length of the cycle when we connect two nodes a and b => 
 * cycle length = depth[a] + depth[b] - 2 * depth(lca(a, b)) + 1
 *  
 * to get the lca we can Binary Lifting logic => not using the direct usage of the up[node][j] 
 * since the values are marked by val, 2*val, 2*val+1 => using Binary Lifting logic gives lca in O(Log(N))
 * 
 * Similar to logic to getting the lca of two nodes using binary lifting 
 * bring both nodes to the same depth and then lift them togethor until their parent is not the same 
 */ 

class Solution {
private:
	int n;

	int depth(int node) {
		int ans = 0;

		while(node > 1) {
			ans++;
			node /= 2;
		}
		return ans;
	}

	int lca(int a, int b) {
        int db = depth(b), da = depth(a);

		// keep node a at a lower depth as compared to depth of b
		if(db > da) {
            swap(a, b);
            swap(da, db);
        }

		// bring a and b to the same depth 
		while(da > db) {
			a /= 2;
			da--;
		}
		// if a and b are now same then b = lca
		if(a == b) return b;

		// now lift both the nodes a and b at the same time 
		while(a != b) {
			a /= 2;
			b /= 2;
		}
		// after the while loop ends a = b => LCA 
		return a;
	}

public: 
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        this->n = n;

        // cycle length = depth(a) + depth(b) - 2 * depth(LCA(a, b)) + 1
        vector<int> res;

        for(auto &q: queries) {
        	int a = q[0], b = q[1];

        	int cycle_len = depth(a) + depth(b) - 2 * depth(lca(a, b)) + 1;
        	res.push_back(cycle_len);
        }

        return res;
    }
};
