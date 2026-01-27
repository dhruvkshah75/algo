// quick select aka Kth largest Element in the Array

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// this question will become if the array is already sorted then the time complexity will become O(n^2)


class Solution {
// return kth largest distinct element 
// Quick Select Algorithm - Average time complexity is O(n)
// This actually goes on doing it with half of the array instead of doing with the entire array
// O(n + n/2 + n/4 + ... ) => Average time complexity
public:
    int partition(vector<int>&nums, int left, int right) {
        if (left == right) return left;
        int pivot = nums[left];
        int i = left, j = right;  // the two pointers that we will use to shift elements wrt to pivot 

        while (i < j) {
            // i: Now we have element strictly greater than the pivot 
            while (nums[i] <= pivot && i <= right - 1) i++;
            // j: we have the element smaller than or equall the pivot 
            while (nums[j] > pivot && j >= left + 1) j--;  
            // If i and j haven't crossed, swap them
            if (i < j) swap(nums[i], nums[j]);
        }

        // Place pivot in its correct sorted position (swap with j)
        // if the pivot was nums[right] then we do swap(nums[i], nums[right] = pivot)
        swap(nums[left], nums[j]);
        
        // Return j, because that's where the pivot is now
        return j;
    }

    void quickSelect(vector<int> &nums, int k, int left, int right, int &ans) {
        // n - k is the target index in ascending order 
        int n = nums.size();
        int part = partition(nums, left, right);  // the partition element 

        if(n - k > part) { // target index is in the right half of the array
            quickSelect(nums, k, part + 1, right, ans);
        }
        else if(n - k < part) { // target index is in the left half of array
            quickSelect(nums, k ,left, part - 1, ans);
        }
        else {
            ans = nums[part];  // when the target index is the partition index itself so we return it 
            return;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // target index is n - k
        int n = nums.size();
        int ans = -1;
        quickSelect(nums, k, 0, n-1, ans);

        return ans;
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
    int KthLargestElement = s.findKthLargest(nums, k);
    cout << KthLargestElement << endl;
}