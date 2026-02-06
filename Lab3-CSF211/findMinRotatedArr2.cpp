#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

/*  
    The problem occurs when nums[r] == nums[mid], we cant say where the rotation element is 
    so we simply decrement the array by 1 from the right r--
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // If the array is not rotated i.e sorted
        if (nums[l] < nums[r]) return nums[l];
        // we find the where the rotation is happening
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid; // Min must be in the right half
            else if (nums[mid] < nums[r]) r = mid; // Min is mid or to the left
            else { //nums[mid] == nums[r], we don't know where the min is. Just shrink the right boundary.
                r--;
            }
        }
        return min(nums[l], nums[r]);
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
    cout << s.findMin(nums) << endl;
}