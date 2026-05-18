#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/parallel-courses-iii/description/

/*
    Initially i thought of calculating the max Time for a course in the same level => but this is wrong as 
    we can multiple courses at the same time so if we complete the course early we can start taking the next course 
    just after that 

    CORRECT LOGIC AND INTUITION 
    so we maintain a array of completionTime[i] = time to complete the ith course from the start 
    completionTime[i] = time[i-1] for starting courses 
    otherwise for non starting points 
    for the current node we calculate the completion time for the nbg 
    completionTime[nbg] = max(completionTime[nbg], time[nbg-1] + completionTime[node])
    We take the max of the two values as there are multiple ways to reach this nbg node 
    completionTime for nbg would be time taken by this course + time taken by the parent node course  
*/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        // Kahn's algorithm => modified level wise bfs => each level is when i is added indegree[i] = 0
        int m = relations.size();

        vector<vector<int>> adjL(n+1); 
        vector<int> indegree(n+1, 0);

        for(int i = 0; i < m; i++) {
            // [a, b] => here a unlocks b 
            int a = relations[i][0], b = relations[i][1];
            adjL[a].push_back(b);
            indegree[b]++;
        }

        // we can take multiple courses at the same time so level wise calculation is wrong 

        vector<int> completionTime(n+1);  // stores the time taken to complete the ith course 
        queue<int> q; 

        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                completionTime[i] = time[i-1];
                // time taken to complete the courses with no prereq is their time itself 
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nbg: adjL[node]) {
                // now we must update the time taken to complete the course nbg
                completionTime[nbg] = max(completionTime[nbg], time[nbg-1] + completionTime[node]);
                // we take the max with the current value as the value may have been calculated before 

                indegree[nbg]--;

                if(indegree[nbg] == 0) {
                    q.push(nbg);
                }
            }
        }

        return *max_element(completionTime.begin(), completionTime.end());
    }
};