#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/course-schedule-ii/description/
// Simple implementation of Kahn's algorithm

// Kahn's algorithm says => who gets unlocked when i finish this node


class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        // simple topological sort and return the topo sort order 
        // consider the edge to be directed => [a, b] to do course a we must do course b (a<-b)
        // b unlocks a 

        vector<vector<int>> adjL(n);
        vector<int> indegree(n, 0);
        // indegree = 0 means a course with no prereq from where we can start 

        for(int i = 0; i < prereq.size(); i++) {
            int u = prereq[i][0], v = prereq[i][1];
            adjL[v].push_back(u);
            indegree[u]++;
        }

        // starting points are all the courses with indegree = 0
        queue<int> q;
        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);  
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node);

            for(int nbg: adjL[node]) {
                indegree[nbg]--;
                if(indegree[nbg] == 0) q.push(nbg);
            }
        }

        if((int)result.size() == n) return result;
        else return {};
    }
};