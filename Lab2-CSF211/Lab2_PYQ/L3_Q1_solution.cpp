#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &nums, int left, int mid, int right, long long &ans, int k) {
    // count such pairs 
    int j1 = right;
    for(int i=left; i<=mid; i++) {
        while(j1 > mid && nums[i] + nums[j1] >= k) j1--;
        ans += j1 - mid;
    }

    // sort in the descending order 
    vector<int> temp(right - left + 1);
    int i = left, j = mid+1, x = 0;
    while(i <= mid && j <= right) {
        if(nums[i] < nums[j]) temp[x++] = nums[i++];
        else temp[x++] = nums[j++];
    }

    // add the remaining elements in temp
    while(i <= mid) temp[x++] = nums[i++];
    while(j <= right) temp[x++] = nums[j++];

    for(int i=left; i<=right; i++) nums[i] = temp[i-left];
}

void mergeSort(vector<int> &nums, int low, int high, long long &ans, int k) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid, ans, k);
        mergeSort(nums, mid+1, high, ans, k);
        merge(nums, low, mid, high, ans, k);
    }
}


long long solve(int n, int K, vector<int>& A) {
    // apply merge sort in descending order 
    long long ans = 0;
    mergeSort(A, 0, n-1, ans, K);
    return ans;
}