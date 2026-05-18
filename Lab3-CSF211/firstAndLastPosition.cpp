#include <bits/stdc++.h>
using namespace std;

// Question link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// MEDIUM Leetcode


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // we have to endpoint indexes of the target element in the array 
        vector<int> ans;
        if(nums.empty())
           return ans = {-1, -1};
        
        int n = nums.size();
        // apply binary search two times one to get the lower index and the other to get upper index
        // and adjust the conditions accordingly to get the indexes of lower and upper limit 
        int l = 0, r = n-1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) l = mid;
            else r = mid;
        }
        if(nums[l] == target) ans.push_back(l);
        else if(nums[r] == target) ans.push_back(r);
        else {
            return ans = {-1, -1};
        }

        l = 0; r = n-1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > target) r = mid;
            else l = mid;
        }
        if(nums[r] == target) ans.push_back(r);
        else ans.push_back(l);

        return ans;
    }
};

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution s = Solution();
    vector<int> ans= s.searchRange(nums, target);

    cout << ans[0] << " " << ans[1] << endl;
}