#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int isPeak(vector<int>&nums, int k) {
        // returns 1 if the element on the right is bigger
        // returns -1 if the element on left is bigger 
        // returns 0 if nums[k] is the peak element 
        if(k == nums.size()-1) {
            if(nums[k] > nums[k-1]) return 0;
            else return -1;
        }
        else if(k == 0) {
            if(nums[k] > nums[k+1]) return 0;
            else return 1;
        }
        else {
            if(nums[k] > nums[k+1] && nums[k] > nums[k-1]) return 0;
            else return (nums[k+1] == max(nums[k+1], nums[k-1])) ? 1 : -1;
        }
    }

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {  // only 1 element in the array
            return 0;
        }
        // we apply binary search on the array 
        int l = 0, r = n-1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(isPeak(nums, mid) == 0) return mid;
            else if(isPeak(nums, mid) == 1) l = mid;
            else r = mid;
        }
        if(isPeak(nums, l) == 0) return l;
        else return r;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution s = Solution();
    cout << s.findPeakElement(nums) << endl;
}