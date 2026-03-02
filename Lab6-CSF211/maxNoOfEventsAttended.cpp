#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/
// VERY IMPORTANT QUESTION ON HEAPS 

/*
    The maximum number of events attended would be attending one event at the current date that has 
    started and end date > current date and to attend the max no of events we attend the event with the 
    smallest end date to maximize the output 
    So we sort on the basis of start dates then maintain a current date counter and run it till 1e5 
    (max date case) 
    We push all the events that have started or will start at the current date 
    we attend a single event for that current date which is at the top of min heap 
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size(); 

        sort(events.begin(), events.end());
        // sort on the basis of the first day 

        priority_queue<int, vector<int>, greater<int>> min_heap;
        // we store all the end dates that are there for the event that starts at that curr date 
        // we iterate through all the days one by one as day <= 1e5 

        int ans = 0, i = 0;           
        int curr_date = events[0][0];    
        // run the outer loop until all the events are processed 
        while(curr_date <= 1e5) {
            // If heap is empty, jump to the next available event's start day
            if(min_heap.empty() && i < n) {
                curr_date = events[i][0];
            }

            // Add all events starting on or before curr_day to the heap
            while(i < n && events[i][0] <= curr_date) {
                // for the same start date push the end day into the minHeap
                min_heap.push(events[i][1]);
                i++;
            }
            // Remove events that have already ended
            while(!min_heap.empty() && min_heap.top() < curr_date) {
                min_heap.pop();
            }

            // if there are events left then attend one on the curr_date with the smallest end date 
            if(!min_heap.empty()) {
                ans++;
                min_heap.pop();
            }

            curr_date++;
        }

        return ans;
    }
};