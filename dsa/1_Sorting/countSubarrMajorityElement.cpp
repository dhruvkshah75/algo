#include<bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/

/*
    Algorithm:
        

*/


class Solution {
public:
    void merge(vector<long long> &prefix, int &ans, int left, int mid, int right) {
        // here we count pairs (i, j) such that prefix[j] - prefix[i] > 0
        // if sum is greater than 0 than target is the majority element 
        for(int i=left; i<=mid; i++){
            int j = mid+1;
            // find the j till which the sum is not getting is <= 0 
            // if it becomes greater than 0 than all the elements after j will be included in the ans
            while(j <= right && prefix[j] - prefix[i] <= 0) j++;
            ans += (right - j + 1);
        }

        // now we do the normal merging 
        vector<long long> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while(i <= mid && j <= right) {
            if(prefix[i] > prefix[j]) temp[k++] = prefix[j++];
            else temp[k++] = prefix[i++];
        }

        // now join the remaining part 
        while(i <= mid) temp[k++] = prefix[i++];

        while(j <= right) temp[k++] = prefix[j++];
        // now fill the prefix array
        for(int i=left; i <= right; i++) prefix[i] = temp[i-left];
    }

    void mergeSort(vector<long long> &prefix, int &ans, int left, int right) {
        if(left >= right) return;
        int mid = left + (right - left)/2;
        mergeSort(prefix, ans, left, mid);
        mergeSort(prefix, ans, mid+1, right);
        merge(prefix, ans, left, mid, right);
    }

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            nums[i] = (nums[i] == target) ? 1 : -1;
        }
        vector<long long> prefix(n+1);
        // while using prefix sums we use a base as 0 make the array of size n+1
        prefix[0] = 0;
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i]*1LL;
        }

        mergeSort(prefix, ans, 0, n);
        return ans;
    }
};


