// ==================================== greedy ===================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/non-overlapping-intervals/description/

/**
 * The best way to deal with this question is to sort the intervals based on their end time 
 * we only care about when does the interval end so that the next one is not overlapping 
 * so this also deals with the interval of bigger sizes => these type of intervals end later 
 * 
 * Keep a track of the last kept interval so that we can compare that this new interval is overlapping or not 
 * all the intervals before the last kept interval will be valid and not overlapp with the newer one 
 **/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b) {
        	// sort on the basis of their end times 
        	return a[1] < b[1];
        });

        int last_kept = -1, kept = 0;

        for(int ind = 0; ind < n; ind++) {
        	int start = intervals[ind][0], end = intervals[ind][1];

        	// only keep this one if last_kept does not overlap with this one 
        	if(last_kept == -1 || intervals[last_kept][1] <= start) {
        		last_kept = ind;
        		kept++;
        	}
        }

        // return the number of deleted intervals => total - kept 
        return n - kept;
    }
};
