#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/
// LEETCODE HARD Question on MERGE SORT


class Solution {
    void merge(vector<int>&A, int diff, long long &ans, int left, int mid, int right) {
        // we calculate the calculation of pairs here
        int j1 = mid + 1;
        for(int i=left; i<=mid; i++) {
            while(j1 <= right && A[i] - A[j1] > diff) 
                j1++;
            ans += (right - j1 + 1) * 1LL;
        }

        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1;
        int k = 0;
        while(i <= mid && j <= right) {
            if(A[i] < A[j])     
                temp[k++] = A[i++];
            else 
                temp[k++] = A[j++];
        }

        while(i <= mid) temp[k++] = A[i++];
        while(j <= right) temp[k++] = A[j++];

        for(int i=left; i<=right; i++) 
            A[i] = temp[i-left];
    }

    void mergeSort(vector<int>&A, int diff, long long &ans, int left, int right) {
        if(left >= right)   
            return;
        int mid = left + (right - left) / 2;
        mergeSort(A, diff, ans, left, mid);
        mergeSort(A, diff, ans, mid+1, right);
        merge(A, diff, ans, left, mid, right);
    }

public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        // the transformed equation is (nums1[i] - nums2[i]) - (nums1[j] - nums2[j]) <= diff
        // since i and j are fixed for both nums1 and nums2
        // we get A[i] - A[j] <= diff ==> can be solved using merge sort

        int n = nums1.size();
        vector<int> A(n);
        for(int i=0; i<n; i++) {
            A[i] = nums1[i] - nums2[i];
        }

        long long ans = 0;
        mergeSort(A, diff, ans, 0, n-1);
        return ans;
    }
};

int main() {
    int n, diff;
    cin >> n >> diff;
    vector<int> nums1(n), nums2(n);

    for(int i=0; i<n; i++) 
        cin >> nums1[i];

    for(int i=0; i<n; i++)
        cin >> nums2[i];

    Solution s = Solution();    
    cout << s.numberOfPairs(nums1, nums2, diff) << endl;
}