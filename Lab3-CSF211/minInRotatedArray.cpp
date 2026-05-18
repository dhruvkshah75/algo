#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

/*
    Algorithm:
        We binary search on the array, 
        if the mid is larger than l then we reduce the search space by l = mid
        else we reduce the search space by doing r = mid 
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(r-l>1) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[l]) l = mid;
            else r = mid;
        }
        // at the end the ans will be min(nums[l], nums[r])
        // but if the array is sorted then the ans can be nums[0] so we take the min of both the values 
        return min(nums[0], min(nums[l], nums[r]));
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution s = Solution();
    cout << s.findMin(nums) << endl;
}