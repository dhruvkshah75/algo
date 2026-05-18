// leetcode q: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

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
            left = 0; 
            right = l;
        }
        else{
            left = r;
            right = nums.size() - 1;
        }

        while(right-left > 1){
            int mid = (left+right)/2;
            if(nums[mid] > target) right = mid-1;
            else left = mid;
        }
        if(nums[left] == target){
            return left;
        }
        else if(nums[right] == target){
            return right;
        }
        else {
            return -1;
        }

    }
};

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution s = Solution();
    int ans = s.search(nums, target);
    cout << "The ans is: " << ans << endl;
}