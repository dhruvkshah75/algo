#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// MEDIUM Leetcode => VERY IMPORTANT QUESTION


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1; 
        // using binary search to find the element where rotation happened, like a peak l is 7 then r is 1 
        while(r-l > 1){
            int mid = (l+r)/2;
            if(nums[mid] > nums[l]) l = mid;
            else r = mid;
        }

        int left, right;
        if(target >= nums[0] && target <= nums[l]){
            left = 0;  right = l;
        }
        else{
            left = r; right = nums.size() - 1;
        }
        // this binary search will check for the element with l and r depending on where the element is
        while(right-left > 1){
            int mid = (left+right)/2;
            if(nums[mid] > target) right = mid-1;
            else left = mid;
        }
        if(nums[left] == target) return left;
        else if(nums[right] == target) return right;
        else return -1;
    }
};