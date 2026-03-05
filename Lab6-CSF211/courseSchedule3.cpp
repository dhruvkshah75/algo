#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/course-schedule-iii/description/
// HEAPS and GREEDY combination were we try do to all the things on the way and then drop the one that caused the harm most among the prev attended 

/*
    We must use a maxHeap as [100, 100], [20, 101], [20, 102] => the ans should be 2 
    as we attend the ones with less duration as they will be completed easily before their last dates 

    Max Heap approach => take all the courses and store their duration in the heap 
    when a current course fails then pop out the max duration course if more than the current course 
    duration  
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        // we can only one course at a time 
        
        auto cmp = [&](const vector<int>&a, const vector<int> &b) {
            // sort on the basis of the last date 
            return a[1] < b[1];
        };

        // we must sort them on the basis of their last date to prevent missing out 
        sort(courses.begin(), courses.end(), cmp);

        // greedy => do courses with the smallest duration so pop out the ones with more duration  
        priority_queue<int> maxHeap;

        int lastDay = 0;

        for(int i = 0; i < n; i++) {
            // best greedy and heap approach => take up on all the courses and then drop which harm the most
            int duration = courses[i][0];
            // not possible to attend the course
            if(duration > courses[i][1]) continue;

            if(duration + lastDay <= courses[i][1]) {
                // the current course can be done so push the duration of the course 
                maxHeap.push(duration);
                lastDay += duration;
            }
            else {
                // pop out the max duration course 
                int maxDuration = maxHeap.top();  
                // now check if after removing the top can we take the curr course 
                if(duration < maxDuration && duration + lastDay - maxDuration <= courses[i][1]) {
                    maxHeap.pop();
                    maxHeap.push(duration);
                    lastDay += (duration - maxDuration);  // update the lastday tracker 
                }
            }
        }

        // the courses taken are the ones left in the heap 
        return maxHeap.size();
    }
};

