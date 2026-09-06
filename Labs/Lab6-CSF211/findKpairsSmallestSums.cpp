#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

/*
    the rows are the nums1 and columns are nums2 and sum of num1 and nums2 is the value in the grid 
    We add all the elements of the first column that is the sum of num1 with the num2[i] => only the first k
    beacuse the rows k + 1 .. n1 are invalid => sum is already out of the best k 
    After storing them in the minHeap we pop out the top and put it in the result ans 
    
    Pop the Smallest: We extract the smallest sum from the heap. 
        That pair is guaranteed to be our next smallest pair. 
    We add it to our result.Push the Next Element: For the pair we just popped 
        (which was at row i, column j), 
        we push the next element in that same row into the heap: row i, column j + 1.
    Repeat this k times.
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // both the nums1 and num2 are sorted (ascending)
        int n1 = nums1.size(), n2 = nums2.size();

        // we think of the sums of the two arrays as a grid 

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;
        // use a min heap {sum, i, j}  => max sum is 2e9 < INT_MAX

        // to get the elements from the tuple => get<0>(minHeap.top()) 
        // first fill k elements in the heap for the column1 and all rows 

        // fill out the first k elements 
        for(int i = 0; i < n1 && i < k; i++) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>>result;

        while(k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});

            // now move to the next column of the smallest element => j + 1
            if(j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }
        return result;
    }
};