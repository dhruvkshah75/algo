// ========================================== greedy + sorting ============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/

/**
 * sort the tasks based on diff of minimum energy to start the task and energy to finish the task 
 * sort in desc order for the diff and break ties with the one having more min energy to start the task with
 * Start with the tasks with max diff so we are left with more energy which is beneficial
 * 
 * Then we can compute what is the min health needed to complete tasks in O(N) => One pass of the array 
 * we try to reach bare minimum energy to start the next task => in doing so we get the optimal and most 
 * minimum energy to complete all 
 * */

class Solution {
public:
    int minimumEffort(vector<vector<int>> &tasks) {
        int n = tasks.size();

        sort(tasks.begin(), tasks.end(), [&](const vector<int> &a, const vector<int> &b) {
        	// dsc order on the diff 
        	if(a[1] - a[0] == b[1] - b[0]) return a[1] > b[1];

        	return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int start_health = tasks[0][1];
        int health_left = start_health - tasks[0][0];

        for(int i = 1; i < n; i++) {
        	if(health_left >= tasks[i][1]) {
        		// enough health left to complete this task 
        		health_left -= tasks[i][0];
        	}
        	else {
        		// health_left currently is not enough to start ith task so add bare min energy to start this task
        		start_health += tasks[i][1] - health_left;
        		health_left = tasks[i][1] - tasks[i][0];
        	}
        }

        return start_health;
    }
};
