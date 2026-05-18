#include<bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

/*
    VERY IMPORTANT QUESTION
    ALGORITHM: 
        We need to find it target exists in a rotated array, the problem is that if 
        mid, l and r all are the same, then all our comparision goes wrong so 
        we simply decrease the search space by 2 by doing l++ and r-- 

        For other cases: If mid lies in the left sorted half (before the rotating pivot) 
        then we check if the target is part of that half or not and accordingly reduce our search space 
        Similarly we do the same thing as above if the mid lies in the right side of the sorted part
        
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // do it in a binary seacrh 
        int n = nums.size();
        int l = 0, r = n - 1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(target == nums[mid]) return true;
            // when there duplicates, that is the mid, l and r all are the same 
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++; r--;
            }
            else if(nums[mid] >= nums[l]) { // mid is in the left sorted part 
                // check if the target is in the between mid and l
                if(target < nums[mid] && target >= nums[l]) r = mid;
                else l = mid;
            }
            else {  // the mid is in right sorted side 
                // check if the target belongs in the right sorted side or not 
                if(target > nums[mid] && target <= nums[r]) l = mid;
                else r = mid;
            }
        }
        if(nums[l] == target || nums[r] == target) return true;
        else return false;
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