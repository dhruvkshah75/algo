#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

// Here the heap acts like a window of top K tests scores => the min of this is the KthLargest element 
class KthLargest {
    // for kth largest something we maintain a min heap 
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int windowSize;
public:
    KthLargest(int k, vector<int>& nums) {
        // we maintain the min heap with k elements and the top represents the Kth largest 
        // Kth larget means smallest among the big k elements 
        int n = nums.size();
        windowSize = k;

        for(int i=0; i<n; i++) {
            // if the heap has less elements then push regardless
            if(min_heap.size() < k) {
                min_heap.push(nums[i]);
                continue;
            }
            
            // if the currrent nums[i] is greater than the top then it must lie in the top k
            // then pop the top and push the new element 
            if(nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        
        // if the heap has less than k elements then push regardless
        if(windowSize > min_heap.size()) {
            min_heap.push(val);
            return min_heap.top();
        }

        // now the heap has k elements and we must add the new val and then return the Kth largest
        if(val > min_heap.top()) {
            min_heap.pop();
            min_heap.push(val);
        }

        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */