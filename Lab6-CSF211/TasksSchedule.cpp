#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/task-scheduler/description/

/*
    NOTE: 
        we will pop out n + 1 tasks and store them in waitlist place all of them and place one of each 
        and after placing one of each we update the freq and then re push in the maxHeap 
        we also maintain two variables lastPlaceFilled and length 
        length => stores no of cycles that cards were placed in 
        lastPlaceFilled => indicates the last card placed which would the no of tasks in the waitlist 
*/

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> cnt;

        for(int i = 0; i < tasks.size(); i++)
            cnt[tasks[i]]++;

        // we must define a custom priority based on the count of each task 
        auto cmp = [&](char a, char b) {
            // return true if a has lower priority then b 
            return cnt[a] < cnt[b];
        };

        priority_queue<char, vector<char>, decltype(cmp)> maxHeap(cmp);

        // populate the max heap with the unique tasks 
        for(auto &[task, count]: cnt) {
            maxHeap.push(task);
        }

        // the ans will be length * (n + 1) + lastPlaceFilled

        int lastPlaceFilled = 0;
        int length = -1;          // stores the factor of n + 1
        // if task1 is placed at i then task1 is again placed at i + n + 1 th position 
        while(!maxHeap.empty()) {
            vector<char> waitlist;
            // store the tasks in the wailist place one of each in the n + 1 gap 
            while(!maxHeap.empty() && waitlist.size() < n + 1) {
                waitlist.push_back(maxHeap.top());
                maxHeap.pop();
            }

            // after placing these elements we decrease their counts
            for(int i = 0; i < waitlist.size(); i++) {
                cnt[waitlist[i]]--;
            }
            // the factor of n + 1 to updated 
            length++;
            // last filled to be updated which will be the length of waitlist 
            lastPlaceFilled = waitlist.size();

            // re push the tasks if their count is greater than 0 
            for(int i=0; i < waitlist.size(); i++) {
                if(cnt[waitlist[i]] > 0) {
                    maxHeap.push(waitlist[i]);
                }
            }
        }
        return length * (n + 1) + lastPlaceFilled;
    }
};