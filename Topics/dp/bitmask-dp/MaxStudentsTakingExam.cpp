// ======================================== bitmask dp =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-students-taking-exam/description/

/**
 * For assigning students in a row we need to know the previous row configuration 
 * use the prev row = mask where set bit indicates that a student is sitting there 
 * Recursion is used to try all possible configurations (i.e. try out all possible paths)
 * so we must generate all valid masks for each row so that inside recursion it is not calculated 
 * again and again
 * 
 * Valid mask is the one where no students are adjacent to each other and no student is placed on 
 * grid[row][j] = '#' (blocked seat)
 **/

class Solution {
private:
	int m, n;
	vector<vector<int>> valid_masks;
	int dp[8][256];

	bool isValid(int mask, int r, vector<vector<char>> &seats) {
		// valid mask = two adjacent bits cannot be set and seats[r][j] = '#' then jth bit = 0
		int prev_bit = 0;

		for(int j = 0; j < n; j++) {
			int bit = mask & (1 << j);
			// adjacnet bits are set and jth set bit is blocked => invalid mask 
			if(bit && (prev_bit || seats[r][j] == '#')) return false;
			prev_bit = bit;
		}
		return true;
	}

	int f(int r, int prev_mask, vector<vector<char>> &seats) {
		// base case: all seats finished 
		if(r == m) return 0;

		if(dp[r][prev_mask] != -1) return dp[r][prev_mask];

		// try all valid masks for this row and check if it does not clash with prev_mask
		int best = -1e9;

		for(int mask: valid_masks[r]) {
			int students = __builtin_popcount(mask);

			bool flag = true;
			for(int j = 0; j < n; j++) {
				int bit = mask & (1 << j);

				if(!bit) continue;
				// check the j+1 and j-1 bits of prev_mask 
				int prev_bit1 = 0, prev_bit2 = 0;
				if(j-1 >= 0) prev_bit1 = prev_mask & (1 << (j-1));
				if(j+1 < n) prev_bit2 = prev_mask & (1 << (j+1));

				// cannot use this mask so try next one 
				if(bit && (prev_bit1 || prev_bit2)) {
					flag = false;
					break;
				}
			}

			if(flag) {
				best = max(best, students + f(r+1, mask, seats));
			}
		}

		return dp[r][prev_mask] = best;
	}

public:
    int maxStudents(vector<vector<char>> &seats) {
        m = seats.size();
        n = seats[0].size();
        // m rows and n cols 

        valid_masks.resize(m);
        // valid_mask[i] = denotes all valid mask for the ith row 

        // iteratively generate all the valid masks for each row 
        for(int row = 0; row < m; row++) {
        	for(int mask = 0; mask < (1 << n); mask++) {
        		if(isValid(mask, row, seats))
        			valid_masks[row].push_back(mask);
        	}
        }

        memset(dp, -1, sizeof(dp));

        return f(0, 0, seats);
    }
};