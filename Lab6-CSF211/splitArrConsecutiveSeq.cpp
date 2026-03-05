#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/description

// Very Imporant Question on heaps 
/*
    We use a priority queue for storing a pair = {last element of the sequence, length of the sequence}
    Greedy approach => it is better to add a element to a sequence which has a smaller length to make sure all the 
    sequences have at least length = 3 
    so if top has {num - 1, len} => then num can extend this sequence and the one with a smaller length will pop 
    we must also pop out all the dead sequences (the one whose last element < num - 1) as the current element 
    num cannot extend these so no element can beacuse the array is sorted
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();

        // we store the last number and len of the sequence as a pair 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        // we must approach greedily by making smaller sequences 

        // pair<int,int> = {last number filled, length of the sequence} 
        min_heap.push({nums[0], 1});

        for(int i = 1; i < n; i++) {
            int curr = nums[i];

            // since array is sorted so if there are sequences which can be extended by curr then pop
            while(!min_heap.empty() && min_heap.top().first < curr - 1) {
                // if the dead sequence has less than 3 elements then return false
                if(min_heap.top().second < 3)
                    return false;
                min_heap.pop();
            }

            // now the top sequence in the heap is the one which can be extended by curr 
            // since it is a min heap => it will be better to put curr in the top as it is a smaller sequence 
            pair<int,int> curr_seq;
            if(!min_heap.empty() && min_heap.top().first == curr - 1) {
                // there is a existing sequence which this element can extend 
                curr_seq = min_heap.top();
                min_heap.pop();
                curr_seq.first = curr;
                curr_seq.second++;
            }
            else {
                // if no sequence here then we must make a sequence with curr 
                cout << curr << endl;
                curr_seq.first = curr;
                curr_seq.second = 1;
            }


            min_heap.push(curr_seq); 
        }
        // check if the remaining sequences in the heap are valid or not 
        while(!min_heap.empty()) {
            if(min_heap.top().second < 3) 
                return false;
            min_heap.pop();
        }

        return true;
    }
};