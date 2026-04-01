#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/course-schedule/description/

/*
    indegree[i] = number of courses that must be completed before course i
    indegree[i] = 0 → course is unlocked, ready to take
    Here instead of going and removing the taken course from each adjacency list of nodes just update the indegree
    We iteratively remove nodes with in-degree 0
*/

bool canFinish(int numCourses, vector<vector<int>>& prereq) {
    // prereqs are the edges [a, b] means we must take course b to complete a (b is a prereq of a)
    int m = prereq.size();
    // we can form a directed graph 

    vector<vector<int>> adjL(numCourses);
    vector<int> indegree(numCourses, 0);  
    // node n => store all the courses that are unlocked when this course is taken
    for(int i = 0; i < m; i++) {
        int a = prereq[i][0], b = prereq[i][1];
        adjL[b].push_back(a);    // if we complete course b then we can unlock course a (b -> a)
        indegree[a]++;
    }

    queue<int> q;  // queue only contains the courses that can be taken 

    // we start with all the courses with indegree 0
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    int courseTaken = 0;
    // BFS
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        courseTaken++;

        // now push all the neighbours 
        for(int neighbour: adjL[node]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    // true if all the courses are taken 
    return courseTaken == numCourses;
}
