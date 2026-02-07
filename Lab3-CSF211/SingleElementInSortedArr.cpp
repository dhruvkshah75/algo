#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// MEDIUM Leetcode Question

/*  
    ALGORITHM:  Binary Search
        We check what is the length on the left of the pair of mid, 
        if left part is odd then the ans must be in the left side of the array 
        What do i mean by pair?  mid could be equal to mid - 1 or mid + 1 
        Depending on what forms pair with mid we shorten our search space 

        But IMP Note: we must take care that we should completely eleminate this 
        (mid and mid+1) OR (mid-1 and mid) pair if not then we can get wrong answers 
        
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();  // the size will be odd 
        // depending on how many elements are there on left and right 
        // if there odd then the ans will be on the left otherwise on the right  
        int l = 0, r = n - 1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1])
                return nums[mid];
            if(nums[mid-1] == nums[mid]){
                // mid - 1 and mid are the same elements 
                if((mid - 1 - l) & 1) r = mid;
                else l = mid + 1;  // skip mid-1 and mid+1 as they are a pair 
            }
            else {
                // mid, mid + 1 are the same elements 
                if((mid - l) & 1) r = mid - 1;  // skip elements mid, mid + 1 as they are a pair
                else l = mid;
            }
        }
        // now we have l and r now we have to check if the ans is l or r
        // if they are the endpoints => then they are the ans 
        if(l == 0) return nums[l];
        else if(r == n - 1) return nums[r];

        if(nums[l] == nums[l-1]) return nums[r];
        else return nums[l];
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
    cout << s.singleNonDuplicate(nums) << endl;
}