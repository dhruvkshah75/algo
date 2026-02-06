#include<bits/stdc++.h>
using namespace std;

class MountainArray {
private:
    vector<int> arr;
public:
    MountainArray(vector<int> data) : arr(data) {} // constructor 

    int get(int i) {
        if(i < 0 || i > arr.size()) throw out_of_range("Index out of Bounds");
        else return arr[i];
    }

    int length() {
        return arr.size();
    }
};

// question link : https://leetcode.com/problems/find-in-mountain-array/description/
// HARD QUESTION 

/*
    CONDITION: Max only 100 calls are allowed for get method of MountainArr  => therefore use BinarySearch

    Simply find the peak of the array by comparing the mid, mid - 1 and mid + 1,
    after finding the peak element we just apply two different binary search 
    1 => for the left part (till the peakIdx) => sorted in ascending order 
    2 => for the right part (after the peakIdx) => sorted in descemding order  
*/

class Solution {
public:
    // checks if the target is in the left part after the peak => descending order 
    int binarySearchRight(int target, MountainArray &mountainArr, int l, int r) {
        int n = mountainArr.length();
        int ans = -1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if(target > val) r = mid;
            else l = mid; 
        }
        if(mountainArr.get(l) == target) return l;
        else if(mountainArr.get(r) == target) return r;
        else return -1; 
    }

    // checks if the target is in the left part before of the peak  => ascending order 
    int binarySearchLeft(int target, MountainArray &mountainArr, int l, int r) {
        int n = mountainArr.length();
        int ans = -1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if(target < val) r = mid;
            else l = mid; 
        }
        if(mountainArr.get(l) == target) return l;
        else if(mountainArr.get(r) == target) return r;
        else return -1; 
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        // we have to apply binary search 
        // we need to find the peak by comparing mid-1, mid, mid+1 
        // after we get the peak then we simply apply binary search on both sides of the peak  
        int n = mountainArr.length();
        int peakIdx = -1;
        int l = 0, r = n - 1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            int val1 = mountainArr.get(mid-1), val2 = mountainArr.get(mid);
            int val3 = mountainArr.get(mid+1);
            if(val1 < val2 && val2 < val3) l = mid;
            else r = mid;
        }
        peakIdx = r;  // => after r-l=1 r will be the peakIndex 

        int ans1 = binarySearchLeft(target, mountainArr, 0, peakIdx);
        int ans2 = binarySearchRight(target, mountainArr, peakIdx+1, n-1);
        if(ans1 != -1) return ans1;
        else if(ans2 != -1) return ans2;
        else return -1;
    }
};



int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    MountainArray mountainArr = MountainArray(arr);

    Solution s = Solution();

    cout << s.findInMountainArray(target, mountainArr) << endl;
}