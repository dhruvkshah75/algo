#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sliding-window-maximum/description/
// VERY IMPORTANT Usage of deques => helps using queues like stacks and queues both at the same time  


// sliding window maximums 
// we only add elements in the back of the queue if the current element was smaller than back 
// if greater than we would poping out from the back 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        deque<int> dq; 

        // first we prepopulate the deque
        for(int i=0; i<k; i++) {
            // the new inserted element is greater than the back element then remove the smaller one 
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // store the first ans
        ans.push_back(nums[dq.front()]); 

        for(int i=k; i<n; i++) {
            // remove indices that are out of the window that <= i - k
            // this loop maintains if elements at the front are in the current window 
            while(!dq.empty() && dq.front() <= (i - k)) {
                dq.pop_front();
            }
            // instead of just pushing we push only elements smaller than the back element 
            // so pop those back elements smaller than the nums[i]
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // the front of the deque is the max of the current window 
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};