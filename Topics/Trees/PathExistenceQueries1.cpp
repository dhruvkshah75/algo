// ================================== Union Find =================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description

/**
 * Explanation: Union Find to store the connected components 
 * we just compare adj nodes for their diff to be less than max diff 
 * since all the nums are sorted in non decreasing order 
 * So comparing all [i] and [i-1] nodes to check if edge can be created or not 
 * and use DSU to make connections 
 * 
 * */

class DSU {
private:
	vector<int> parent, size;

public:
	DSU(int n) : parent(n), size(n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int x) {
		if(parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}

	void unite(int x, int y) {
		int px = find(x), py = find(y);
		if(px == py) return;

		if(size[py] > size[px]) swap(px, py);
		parent[py] = px;
		size[px] += size[py];
	}
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries) {
        // nodes are 0 - n-1
        DSU d(n);

        for(int i = 1; i < n; i++) {
        	if(nums[i] - nums[i-1] <= maxDiff) 
        		d.unite(i-1, i);
        }

        // queries[i] = true if there is a path between node u and node v 
        // i.e. node u and node v are in the same component 
        vector<bool> res;
        for(auto &q: queries) {
        	if(d.find(q[0]) == d.find(q[1])) res.push_back(true);
        	else res.push_back(false);
        }

        return res;
    }
};

