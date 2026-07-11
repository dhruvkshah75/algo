// ===================================== binary lifting ====================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/description

/** 
 * Explanation: binary jumping 
 * Here we cannot form the entire graph => resulting graph cannot be formed 
 * we need to use binary jumping to reach every single node =>
 * Using a sparse dp table we can jump in powers of 2  
 * this jumping in powers of 2 helps in reaching to ans in logN instead of making singular jumps 
 * 
 * Now how do we store the parent of each node in the binary lifting spare table 
 * up[i][0] = fursthest reachable node in one jump (in that window)
 * 
 * Now binary lift the node u until it reaches v 
 * and each 2 ^ j th jump adds 2 ^ j edges in between so in this way we get the edges in the shortest path
 * */

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries) {
        int q = queries.size();

        vector<pair<int,int>> a(n);
        // store the nums with original node index => for sorting to work 
        for(int i = 0; i < n; i++) 
        	a[i] = {nums[i], i};

        sort(a.begin(), a.end());

        // create a mapping for the original index to sorted position 
        vector<int> get_idx(n);

        for(int i = 0; i < n; i++) 
        	get_idx[a[i].second] = i;


       	// using sliding window get the same component correctly togethor 
       	// extend the window till abs(a[left]-a[right]) <= diff => shrink the invalid window 

        vector<vector<int>> up(n+1, vector<int>(18, -1));
        // sparse table for binary lifting => here LOG = 18 (n <= 1e5)
        	
        int r = 0;
        for(int l = 0; l < n; l++) {
        	// expand completely on the right and while shrinking update the parent value
        	while(r < n && a[r].first - a[l].first <= maxDiff) r++;

        	// current valid window = [l...r-1]
        	up[l][0] = r-1;
        }

        for(int j = 1; j < 18; j++) {
        	for(int i = 0; i < n; i++) {
        		// 2 ^ j th jump = 2 jumps of 2 ^ j-1 
        		int node = up[i][j-1];
        		if(node != -1) {
        			up[i][j] = up[node][j-1];
        		}
        	}
        }

        vector<int> ans(q, -1);

        // for each query calculate how many 2^j jumps are needed 
        // we can apply jumps in powers of 2 as each number can be represented as powers of 2 
        for(int i = 0; i < q; i++) {
        	int u = get_idx[queries[i][0]], v = get_idx[queries[i][1]];

        	if(u > v) swap(v, u);

        	// u and v are the same nodes => same position
        	if(u == v) {
        		ans[i] = 0;
        		continue;
        	}

        	int jumps = 0;
        	// we want a path from node u to node v => binary lift u until it reaches v 
        	// first try all bigger jumps and jump if < node v
        	for(int j = 17; j >= 0; j--) {
        		if(u != -1 && up[u][j] < v) {
        			u = up[u][j];
        			jumps += (1 << j);  // 2 ^ j edges are there 
        		}
        	}

        	// if final jump of 1 makes u == v then u is reached 
        	if(up[u][0] >= v) ans[i] = jumps+1;
        }
        // O(Q * LogN)

        return ans;
    }
};