// ===================================== greedy + sorting ====================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/cinema-seat-allocation/description/

/**
 * in the same row we can allot at most 2 groups (as 3 * 4 = 12 seats => not possible)
 * we must also account for the missing rows => not a single reserved seat in those rows 
 * use the prev row and curr row to get the count of missing rows 
 * each missing row can acomodate 2 groups 
 * */

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &seats) {
        // 1....n rows in the cinema 
    	int m = seats.size();

        sort(seats.begin(), seats.end());

    	int ans = 0;
    	int prev_row = 0, ind = 0;

    	while(ind < m) {
    		int curr_row = seats[ind][0];

    		// add the groups in the missing rows => 2 groups can sit in a missing row 
    		ans += (curr_row - prev_row - 1) * 2;

            vector<bool> free(10, true); 
            // free stores which all seats are not reserved in the curr row 

    		int j = ind;
    		while(j < m && seats[j][0] == curr_row) {
                free[seats[j][1]] = false;
                j++;
    		}

            bool left = free[2] && free[3] && free[4] && free[5];
            bool mid = free[4] && free[5] && free[6] && free[7];
            bool right = free[6] && free[7] && free[8] && free[9];

            if(left && right) ans += 2;
            else if(left || right || mid) ans++;

    		prev_row = curr_row;
    		ind = j;
    	}

    	// also add the missing rows in the range of (prev_row, n+1)
    	ans += (n+1 - prev_row - 1) * 2;

    	return ans;
    }
};