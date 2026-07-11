// ======================================== multiple states dp ============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/

/**
 * Explanation: multi state dp + prefix sum + counting 
 * 
 * use prefix sum to check if the cut creates two valid sections i.e. at least one A (prefix >= 1)
 * states needed are curr_row, curr_col, cuts_left 
 * for each recurrence call we can try all possible horizontal and vetical cuts 
 * go with the cut only if the cut creates valid sections 
 * 
 * Note: when we make a vertical cut, the left section will be gone 
 * and when we make horizontal cut then the section above will be given away 
 **/

typedef long long ll;

class Solution {
private:
	const int MOD = 1e9+7;
	int row, col;
	vector<vector<int>> prefix;
	vector<vector<vector<int>>> dp;

	int f(int r, int c, int cuts_left) {
		// when all cuts are made then 1 way found 
		if(cuts_left == 0) return 1;

		if(dp[r][c][cuts_left] != -1) return dp[r][c][cuts_left];

		// horizontal cuts from [r+1,...,row-1] and vertical cuts from [c+1,...,col-1]
		ll res = 0;

		// try all possible horizontal cuts 
		for(int j = r+1; j <= row; j++) {
			// cut is made between j-1 and j
			int pizza_down = prefix[row][col] - prefix[row][c-1] - prefix[j-1][col] + prefix[j-1][c-1];
			int pizza_up = prefix[j-1][col] - prefix[j-1][c-1] - prefix[r-1][col] + prefix[r-1][c-1];

			if(pizza_down > 0 && pizza_up > 0) {
				// this cut is valid and we can make this cut
				res = (res + f(j, c, cuts_left-1)) % MOD;
			}
		}

		// try all possible vertical cuts 
		for(int k = c+1; k <= col; k++) {
			// vertical cut is made => k-1 | k
			int pizza_right = prefix[row][col] - prefix[row][k-1] - prefix[r-1][col] + prefix[r-1][k-1];
			int pizza_left = prefix[row][k-1] - prefix[r-1][k-1] - prefix[row][c-1] + prefix[r-1][c-1];

			if(pizza_right > 0 && pizza_left > 0) {
				// this cur is valid and we can make this cut 
				res = (res + f(r, k, cuts_left-1)) % MOD;
			}
		}

		return dp[r][c][cuts_left] = res;
	}

public:
    int ways(vector<string> &pizza, int k) {
    	// make exactly k-1 cuts to get k pieces 
        row = pizza.size(), col = pizza[0].length();

        prefix.resize(row+1, vector<int>(col+1, 0));
        // keep the prefix matrix as 1 based indexing 

        dp.resize(row+1, vector<vector<int>>(col+1, vector<int>(k, -1)));

        for(int i = 1; i <= row; i++) {
        	for(int j = 1; j <= col; j++) {
        		prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + ((pizza[i-1][j-1] == 'A') ? 1 : 0);
        	}
        }

        // base case check => no A is in entire section 
        if(prefix[row][col] == 0) return 0;

        // call the recurrence from the first cell (1 based) and starting with k-1 cuts 
        return f(1, 1, k-1);
    }
};
