// ===================================== greedy ===========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/two-city-scheduling/description/

/** 
 * Explanation: greedy + sorting 
 * sort on the basis of the abs difference of their costs to each city => abs(costA - costB) in descending order 
 * and then send the person to the city of min cost as sending them to the other city would cause maximum harm to the min cost 
 * send the person to their min city until city allows n people to accomodate (cant exceed n people in a city) 
 * */

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        int n = costs.size() / 2;

        sort(costs.begin(), costs.end(), [&](const vector<int> &a, const vector<int> &b){
        	// sort in descending order of abs diff
        	return abs(a[0]-a[1]) > abs(b[0]-b[1]);
        });

        int cntA = 0, cntB = 0;
        int min_cost = 0;

        for(int i = 0; i < 2*n; i++) {
        	int cost_a = costs[i][0], cost_b = costs[i][1];
        	if(cost_a < cost_b) {
        		if(cntA < n) {
        			min_cost += cost_a;
        			cntA++;
        		}
        		else {
        			min_cost += cost_b;
        			cntB++;
        		}
        	}
        	else {
        		if(cnt_B < n) {
        			min_cost += cost_b;
        			cntB++;
        		}
        		else {
        			min_cost += cost_a;
        			cntA++;
        		}
        	}
        }

        return min_cost;
    }
};