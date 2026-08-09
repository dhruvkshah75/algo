// =================================== greedy + heaps ====================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/ipo/description

/**
 * Explanation: greedy + heaps 
 * we can only begin with those projects whose capital requirment is <= w_initial
 * Use a max heap for this to store the projects with max profit whose capital requiremtns <= w_initial 
 * And use the other heap (min heap) with having the smallest capital requirement 
 * and whenever a project is taken up (max_heap.pop()) then capital that we have also increases so now add the tasks from the 
 * min heap to max heap (max heap = allowed tasks to be taken)
 **/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    	int n = profits.size();
        // w = starting capital and k = number of tasks to do 

        auto cmp_maxheap = [&](const int &a, const int &b) {
        	// return true if a has less priority than b 
        	return profits[a] < profits[b];
        };

        auto cmp_minheap = [&](const int &a, const int &b) { 
        	// store the projects with minimum capital to start at the top 
        	return capital[a] > capital[b];
        };

        // maxHeap stores all the tasks that i can take up at the moment
        // minHeap stores the rest of tasks that cannot be taken with the top having the minimum capital 
        priority_queue<int, vector<int>, decltype(cmp_maxheap)> maxHeap(cmp_maxheap);
        priority_queue<int, vector<int>, decltype(cmp_minheap)> minHeap(cmp_minheap);
        	
        // prefill the heaps 
        for(int i = 0; i < n; i++) {
        	if(capital[i] <= w) maxHeap.push(i);
        	else  minHeap.push(i);
        }

        int total_capital = w;

        while(!maxHeap.empty() && k--) {
        	int idx = maxHeap.top();
        	maxHeap.pop();

        	// we gain the most profit and capital in doing this task
        	total_capital += profits[idx];

        	// reshuffle the tasks (put valid ones now in maxHeap)
        	while(!minHeap.empty() && capital[minHeap.top()] <= total_capital) {
        		int ind = minHeap.top();
        		minHeap.pop();

        		maxHeap.push(ind);
        	} 
        }

        return total_capital;
    }
};