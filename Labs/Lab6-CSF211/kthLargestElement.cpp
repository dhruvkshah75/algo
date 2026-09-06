#include<bits/stdc++.h>
using namespace std;

/* 
    we need to maintain a heap to store the top k elements in it and the smallest of them will be 
    our answer => so we maintain a min heap as doing this it will keep the small elements at the top 
    so if the size exceeds k then we pop it out and then at the end only top k elements are left out 

    Time complexity: O(N*Log(k)) which is much less than sorting 
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // to find the kth largest element in the array we use priority queue 
        // define a min heap 
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int num: nums) {
            min_heap.push(num);
            // if the size exceeds k then pop the top (smallest)
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // at the end only the top k largest elements are present in the heap with 
        // kth largest element at the top
        return min_heap.top();
    }
};