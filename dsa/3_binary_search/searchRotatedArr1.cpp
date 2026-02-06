#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

/*
    Algorithm:
        We are given array with no duplicates 
        So first we find the index with where the rotation happens 
        then we apply normal search binary search in the left or right part of the array 
        depending on whether the target could lie in the left or right sorted part of the array 
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1; 
        // binary search to find the element where rotation happened 
        while(r-l > 1){
            int mid = (l+r)/2;
            if(nums[mid] > nums[l]) l = mid;
            else r = mid;
        }
        int left, right;
        if(target >= nums[0] && target <= nums[l]){
            left = 0; right = l;
        }
        else{
            left = r; right = nums.size() - 1;
        }
        // now search the ans in left or the right part of the array before or after the rotating index 
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

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution s = Solution();
    string str = (s.search(nums, target)) ? "true" : "false";
    cout << str << endl;
    
}

