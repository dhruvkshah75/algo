#include<bits/stdc++.h>
using namespace std;


/*
    QuickSort:  Here is the implementation of quickSort algorithm

    1. Pick up the pivot element and place it at its correct position in the sorted array
    2. Smaller elements are placed to the left of and larger on right 


    NOTE: WHAT ALTERATIONS WE CAN MAKE TO QUICK SORT 
        When we divide the array on the basis of left and right of the pivot, we can have our custom logic there to 
        do something in particular 


*/
class Solution {
public:
    // returns the partition index 
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


    void quickSort(vector<int> &nums, int left, int right) {
        if(left >= right) return; // same base case as mergeSort
        // instead of mid we get the partition element using partition function
        int part = partition(nums, left, right);
        // recursively call this step 
        quickSort(nums, left, part - 1);
        quickSort(nums, part+1, right);
    }

};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++ ) {
        cin >> nums[i];
    }

    Solution s = Solution();
    s.quickSort(nums, 0, n-1);

    //printing the array
    for(int &num: nums) cout << num << " ";
    cout << endl;
}

