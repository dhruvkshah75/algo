#include<bits/stdc++.h>
using namespace std;

// Question Link: https://leetcode.com/problems/reverse-pairs/description/

class Solution {
public:
    void merge(vector<int>& nums, int& ans, int left, int mid, int right) {
        // 1. Count the reverse pairs first 
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            // All elements from (mid + 1) to (j - 1) satisfy the condition
            ans += (j - (mid + 1));
        }

        // 2. Standard Merge Sort merging (Ascending Order)
        vector<int> temp;
        int p1 = left, p2 = mid + 1;
        while (p1 <= mid && p2 <= right) {
            if (nums[p1] <= nums[p2]) {
                temp.push_back(nums[p1++]);
            } else {
                temp.push_back(nums[p2++]);
            }
        }
        while (p1 <= mid) temp.push_back(nums[p1++]);
        while (p2 <= right) temp.push_back(nums[p2++]);

        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }
    }

    void mergeSort(vector<int>& nums, int& ans, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, ans, left, mid);
        mergeSort(nums, ans, mid + 1, right);
        merge(nums, ans, left, mid, right);
    }

    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(nums, ans, 0, nums.size() - 1);
        return ans;
    }
};


/*
    Algorithm:
        While normally sorting the array using merge sort in ascending order.
        In the merge function before merging the two sorted arrays use 2 pointer approach 
        ptr1 -->> i = left and moves between i = left to i = mid 
        ptr2 -->> j = right and moves between j = mid+1 to j = right 
        and using this two pointer approach calculate the reverse pairs for every element in the left array 

*/
