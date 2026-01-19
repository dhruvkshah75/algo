#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

class Solution {
public:
    void merge(vector<pair<int,int>>&numPair, vector<int>&count, int left, int mid, int right) {
        vector<pair<int,int>> temp(right-left+1);
        int i = left, j = mid+1;
        int k = 0;
        while(i <= mid && j <= right) {
            if(numPair[j].first < numPair[i].first) { // if left > right we do count++
                count[numPair[i].second] += right - j + 1;  
                // if nums[i] is larger than nums[j] then nums[i] is bigger than 
                // all the elements after nums[j] that is right-j+1
                temp[k] = numPair[i];
                i++; k++;
            }
            else {
                temp[k] = numPair[j];
                j++; k++;
            }
        } 
        //add the left out portion 
        while (i <= mid) temp[k++] = numPair[i++];
        while(j <= right) temp[k++] = numPair[j++];
        // sort the numPair as it is going to be used further for merge func 
        // in the next iiteration of mergeSort 
        for(int i=left; i<=right; i++) numPair[i] = temp[i-left];
    }

    // sort in the descending order 
    void mergeSort(vector<pair<int,int>>&numPair, vector<int> &count, int left, int right) {
        if(left >= right) return;
        int mid = left + (right-left)/2;  // good pratice to solve like this 
        mergeSort(numPair, count, left, mid);
        mergeSort(numPair, count, mid+1, right);
        merge(numPair, count, left, mid, right);
        // since we dont have diff arrays we sent the ptrs that is the left, mid, right 
        // as we sort the array based on left->mid and mid+1->right
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> numPair;
        for(int i=0; i<n; i++){
            numPair.push_back({nums[i], i});
        }

        vector<int> count(n, 0);
        mergeSort(numPair, count, 0, n-1);
        return count;
    }
};

// Hard Question based on merge Sort 
