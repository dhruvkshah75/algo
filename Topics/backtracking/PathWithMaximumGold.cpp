// ===================================== backtracking =============================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/path-with-maximum-gold/description/

/* Explanation: dfs + backtracking 
   U can start collecting gold from any valid cell (cell != 0) => so try out all paths
   direction of the movement is all four adjacent cells to the cell containing gold 
   we can only move to a cell which contains gold not empty cell

   Here graph traversal is not used as we dont have the rule of visiting the cell 
   we can move in any of the 4 directions in any way if the cell is valid 
*/

class Solution {
private:
	int m, n;
	vector<pair<int,int>> dirs = {{1,0}, {0,1}, {0,-1}, {-1, 0}};

	int dfs(int i, int j, vector<vector<int>> &grid) {
		// base case: this current cell move is invalid or cell is already visited 
		if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0) {
			return 0;
		}

		int temp = grid[i][j];
		grid[i][j] = 0; // marking the node as visited 
		int best = 0;

		for(auto [dx, dy]: dirs) {
			best = max(best, temp + dfs(i+dx, j+dy, grid));
		}

		// backtrack to allow other paths to be explored
		grid[i][j] = temp;
		return best;
	}

public:
    int getMaximumGold(vector<vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();

        // try applying this dfs function on all nodes with gold and get the max gold
        int max_gold = 0;

        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(grid[i][j] == 0) continue;

        		max_gold = max(max_gold, dfs(i, j, grid));
        	}
        }

        return max_gold;
    }
};