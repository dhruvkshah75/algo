// ============================================ 2 pointers + greedy ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/interval-list-intersections/description/

/**
 * Simple 2 pointer approach will work 
 * two cases of intervals will come => non overlapping and overlapping 
 * non overlapping case => move the ptr whose end is smaller 
 * overlapping case => get the overlap of the two intervals and then return the intersection 
 * and move to the ptr of the one whose end is smaller 
 * */

class Solution {
private:
	bool isOverlapping(vector<int> &a, vector<int> &b) {
		// return !(no overlapp)
		return !(a[1] < b[0] || b[1] < a[0]);
	}

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        int n1 = firstList.size(), n2 = secondList.size();

        vector<vector<int>> res;
        
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
        	if(isOverlapping(firstList[i], secondList[j])) {
        		// insert the vector of intersection of two intervals 
        		res.push_back(
        			{max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])}
        		);
        	}

        	if(firstList[i][1] < secondList[j][1]) {
        		i++;
        	}
        	else if(firstList[i][1] > secondList[j][1]) {
        		j++;
        	}
        	else {
        		i++;
        		j++;
        	}
        }

        return res;
    }
};