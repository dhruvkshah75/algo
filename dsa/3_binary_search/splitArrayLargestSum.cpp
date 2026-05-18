#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer array nums and an integer k,
    split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
    Return the minimized largest sum of the split.

    Algorithm: 
        We apply binary Search on the the minimum largest sum that we can have a predicate function 
        Since we want the minimum of something we have a predicate function like FFFFTTTTT 
        We find the first occurrence of T

*/


class Solution {
public:
    // return FFFFFTTTTT 
    // this function tells whether that can max sum of all the subarrays be less than mid 
    bool predicate(vector<int> &nums, int k, int mid) {
        int ctr = 0;
        // we traverse through the array and 
        // we keep increasing the len of subarray until the sum is less than mid
        int curr_sum = 0; 
        for(int i=0; i<nums.size(); i++) {
            curr_sum += nums[i];
            if(curr_sum > mid) {  // now start with a new subarray with nums[i] as iits first element 
                curr_sum = nums[i];  
                ctr++;
            }

            if(ctr > k) return false;  
        }
        ctr++;
        if(ctr > k) return false;
        else return true;
    }

    int splitArray(vector<int>&nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());  // the case when k = n, every element is a subarray
        int r = accumulate(nums.begin(), nums.end(), 0);  // when k = 1, then the entire array is the subarray

        while(r-l>1) {
            int mid = l + (r - l) / 2;
            if(predicate(nums, k, mid)) r = mid;
            else l = mid + 1;
        }
        if(predicate(nums, k, l)) return l;
        else return r;
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution s = Solution();
    // cout << s.predicate(nums, 2, 18) << endl;
    cout << s.splitArray(nums, k) << endl;
}