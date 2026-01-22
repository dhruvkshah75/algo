#include <bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/count-of-range-sum/

class Solution {
    // sum calculation and checking in O(N) -->> directly think about prefix sum array 
public:
    // we only sort the pf 
    // inside the merge function only think of the case when we check the pairs (i, j) with i in left array and j in the right array 
    // This is because when we call the merge function the first time the left is only 1 element and right is also only 1 element 
    void merge(vector<long long> &pf, int &ans, int lower, int upper, int left, int mid, int right) {
        // here we count the no of pairs (i, j) where lower <= pf[j] - pf[i] <= upper 
        int j1 = mid + 1, j2 = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j1 <= right && pf[j1] < pf[i] + lower) j1++; // Move j1 to first j where pf[j] >= pf[i] + lower
            while (j2 <= right && pf[j2] <= pf[i] + upper) j2++; // Move j2 to first j where pf[j] > pf[i] + upper
            ans += (j2 - j1); 
        }
        // merging
        vector<long long> temp(right - left + 1);
        int i = left, j = mid+1;
        int k = 0;
        while(i <= mid && j <= right) {
            if(pf[i] > pf[j]) temp[k++] = pf[j++];
            else temp[k++] = pf[i++];
        }
        // merge the reamining part 
        while(i <= mid) temp[k++] = pf[i++];
        while(j <= right) temp[k++] = pf[j++];

        for(int i=left; i<=right; i++) pf[i] = temp[i-left];
    }

    void mergeSort(vector<long long> &pf, int &ans, int lower, int upper, int left, int right) {
        if(left >= right) return; // base case of merge sort 
        int mid = left + (right-left)/2;
        mergeSort(pf, ans, lower, upper, left, mid);
        mergeSort(pf, ans, lower, upper, mid+1, right);
        merge(pf, ans, lower, upper, left, mid, right);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if(n == 1) { // case when only 1 
            if(nums[0] <= upper && lower <= nums[0]) return 1;
            else return 0;
        }
        int ans = 0;
        vector<long long> pf(n+1);
        pf[0] = 0; // so that we also consider the first element
        for(int i=0; i<n; i++) {
            pf[i+1] = pf[i] + nums[i]*1LL;
        }
        mergeSort(pf, ans, lower, upper, 0, n);
        return ans;
    }
};

