#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sliding-window-median/description/

// VERY IMPORTANR QUESTION ==> LEETCODE HARD (Confidence Breaker) 

// Based on median using max heap and min heap and Lazy deletion (sliding window using priority queues)
/*
    The order of the stuff happening for each window 
    1. Mark the element to be deleted (out of window) in the map 
    2. the element that leaves the window => check in which heap it belongs and adjust its that heaps size
    3. after this change in heap size => rebalance the heaps => the allowed config are 
       maxHeapSize = minHeapSize or maxHeapSize = minHeapSize + 1 => adjusting this is important 
    4. Add the new element into whatever heap that needs to added and place it where it needs to go 
       and after adding we must balance out the heaps again 
    5. we must prune out those top elements in both the heaps that do not belong to the current window 
       but we dont update their size vars as they were already updated in the step 2   
    6, finally get the median => total window is odd then median => maxheap.top 
       and if k is even then the average of both the tops 
*/
// Time Complexity: O(N*LogK) Space Complexity: O(K)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // to calculate mdeian we use two heaps => minHeap and maxHeap

        priority_queue<int> maxHeap;                               // lower half 
        priority_queue<int, vector<int>, greater<int>> minHeap;    // upper half 

        // to take care of the elements out of the window => we can maintain a deleted_map 
        unordered_map<int,int> deleted_mp; 

        // we maintain maxHeap.top() <= minHeap.top()
        // for the first k elements we prepoulate the queues
        for(int i=0; i < k; i++) {
            // first we push elements in the maxHeap 
            maxHeap.push(nums[i]);       // pushing the element first in the lower half 

            minHeap.push(maxHeap.top());
            maxHeap.pop();

            if(minHeap.size() > maxHeap.size()) {
                // we must keep the maxHeap size bigger than minHeap 
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        
        // ==============================================================================
        // ========================== helper lamda functions ============================

        // lamda function to calculate the median
        auto findMedian = [&]() {
            int n = minHeapSize + maxHeapSize;
            // if we odd number of elements in the window then median is the top 
            if(n & 1) 
                return (double)maxHeap.top();
            else 
                return ((double)maxHeap.top() + minHeap.top())/2.0;
        };

        // after every edition and size changes in heap we must rebalance the heaps 
        auto rebalanceHeaps = [&]() {
            // depending on their current sizes we rebalance them 
            if(maxHeapSize > minHeapSize + 1) {
                // maxHeap is bit much bigger 
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeapSize--; minHeapSize++;
            }
            else if(minHeapSize > maxHeapSize) {
                // min heap is a bit much bigger 
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeapSize--; maxHeapSize++;
            }
        };
        
        // add the number into the heaps based on their current heap sizes and rebalance
        auto addNum = [&](int val) {
            // Decide which heap to push into based on value, not just size
            if(maxHeap.empty() || val <= maxHeap.top()) {
                // element should go in the lower half
                maxHeap.push(val);
                maxHeapSize++;
            } 
            else {
                // element must go into the upper half
                minHeap.push(val);
                minHeapSize++;
            }

            // Rebalance: Ensure maxHeapSize is equal to minHeapSize or + 1 => adjust the sizes accordingly
            // call the function 
            rebalanceHeaps();
        };

        // we must remove out the top elements from the heaps to maintain the current window 
        // top elements are important for comparing 
        auto prune = [&]() {
            // remove all the top elements which are not a part of the cuurent window
            // the size of the heap gets adjusted later 
            while(!maxHeap.empty() && deleted_mp.count(maxHeap.top()) && deleted_mp[maxHeap.top()] > 0) {
                deleted_mp[maxHeap.top()] -= 1;
                maxHeap.pop();
            }

            while(!minHeap.empty() && deleted_mp.count(minHeap.top()) && deleted_mp[minHeap.top()] > 0) {
                deleted_mp[minHeap.top()]--;
                minHeap.pop();
            }
        };
        // ==================================================================
        // ==================================================================

        vector<double> medians;
        // first we call the find median for the first window
        medians.push_back(findMedian());

        // now we process all the other elements and keep a track of deleted elements using map 
        for(int i = k; i < n; i++) {
            // as we move forward we throw out (i-k) from the window
            deleted_mp[nums[i-k]]++;

            // the element that is to be removed from window => acc update the heap sizes 
            if(nums[i-k] <= maxHeap.top()) 
                maxHeapSize--;
            else 
                minHeapSize--;

            // after this size update we must rebalance the heaps 
            rebalanceHeaps();

            // now add the new element into the heaps on the basis of their respective heap sizes 
            addNum(nums[i]);

            // after adding the nums[i] call the prune to adjust the heaps accordingly 
            prune();
            
            medians.push_back(findMedian());
        }

        return medians;
    }
};