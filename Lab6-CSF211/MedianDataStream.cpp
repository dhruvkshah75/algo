#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-median-from-data-stream/description/
// LEETCODE HARD 

// Important => we maintain the lowe half in the max heap and upper half in the min heap 


// 5e4 calls can be made so we must get the ans in Log(K) complexity 
class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> min_heap; // upper half 
    priority_queue<int> max_heap;  // lower half 

    // if n is the size of the array => we keep the bigger n/2 elements in the min heap 
    // and the smaller n/2 elements in the max_heap so 

public:

    void addNum(int num) {
        // start by pushing into max heap 
        max_heap.push(num);

        // since we add a new number to the lower half then the biggest of the lower half must go into the upper half
        // we must maintain that diff of maxHeap.size() and minHeap.size() <= 1
        // and maxHeap.top() <= minHeap.top() 

        // Move the largest of the lower half(max_heap) to the upper half(min heap)
        min_heap.push(max_heap.top());
        max_heap.pop();

        // rebalance the sizes of the two heaps 
        // the max heap must hold the extra element in case of odd size 
        if(max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } 
        // the last step is important as the min heap might have gained one extra ele then throw it back into the max heap(lower half)
    }
    
    double findMedian() {
        // if total no of elements is odd then max heap.top is the median 
        // total no of elements is even then max heap and min heap top is even 
        int n = min_heap.size() + max_heap.size();

        double median;
        if(n & 1) {
            median = (double)max_heap.top();
        }
        else {
            median = ((double)max_heap.top() + (double)min_heap.top())/2.0;
        }

        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */