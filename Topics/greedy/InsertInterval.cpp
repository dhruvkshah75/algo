// ================================================ greedy =========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/insert-interval/description/

/**
 * All the intervals are sorted on the basis of their start_i and all intervals are non overlapping 
 * so no two intervals have the same start_i 
 * Now simply check for every interval is overlapping or not with the interval to be inserted 
 * and then merge the interval if overlapping 
 * 
 * First find the first interval that overlaps with the new interval and start merging it from there 
 * */

class Solution {
private:
	bool isOverlapping(vector<int> &a, vector<int> &b) {
		// check whether these intervals overlap or not 
		if(a[0] > b[0]) return a[0] <= b[1];

		return b[0] <= a[1];
	}

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();

        vector<vector<int>> ans;
        int ind = 0;

        // reach the index till all the intervals are smaller and non overlapping 
        while (ind < n && intervals[ind][1] < newInterval[0]) {
            ans.push_back(intervals[ind]);
            ind++;
        }
        
        // now intervals[ind] is overlapping with newInterval
        vector<int> merged = newInterval;

        while (ind < n && isOverlapping(intervals[ind], merged)) {
            // merge the two intervals into merged array 
            merged[0] = min(merged[0], intervals[ind][0]);
            merged[1] = max(merged[1], intervals[ind][1]);

            ind++;
        }

        ans.push_back(merged);

        // now add the remaining intervals 
        while(ind < n) ans.push_back(intervals[ind++]);

       	return ans;
    }
};