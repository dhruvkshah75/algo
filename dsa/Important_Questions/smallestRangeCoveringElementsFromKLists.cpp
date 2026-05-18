#include<bits/stdc++.h>
using namespace std;

// question link: 

/*
    Algorithm:
        Maintain a min heap which keeps one element from each liist among the k lists that we have 
        If we pop any element then we must push a new element from the same list into the heap ensuring that one element 
        from each list stays in the loop 
        we maintain a start and end variable and update if conditions are met  
        We also maintain a currentMax variable to hold the max of the elements read 
        
*/

// supposed to get the smallest interval where k elements exist in the it part of each list
class Solution {
    struct Range {
        int val;
        int listIndex;
        int ValIndex;
    };

public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        // the first and last elements of a list includes all the elements in that range 
        int k = nums.size();

        auto cmp = [&](const Range &a, const Range &b) {
            // return true if a has less priority than b
            return a.val > b.val;
        };

        priority_queue<Range, vector<Range>, decltype(cmp)> minHeap(cmp);
        // sonly one element from each list stays in the heap => smaller at the top 

        // prepopulate the heap with first of each list 
        int currentMax = INT_MIN;

        for(int i = 0; i < k; i++) {
            minHeap.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int start = -1e5, end = 1e5;

        // this loop is like merge k sorted lists + sliding window
        while(minHeap.size() == k) {
            auto [smallest, i, j] = minHeap.top();
            minHeap.pop();

            // now update the ans => range -> if the current range is smaller than the tracker 
            if((currentMax - smallest < end - start) || 
                    (currentMax - smallest == end - start && smallest < start)) {
                start = smallest;
                end = currentMax;
            } 

            // now push the next element if j + 1 exists => if not then the code stops 
            if(j + 1 < nums[i].size()) {
                // update the max value tracker as we are pushing a new element into the heap 
                currentMax = max(currentMax, nums[i][j+1]);
                minHeap.push({nums[i][j+1], i, j + 1});
            }
        }
        return {start, end};
    }
};