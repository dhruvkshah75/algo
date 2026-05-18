#include<bits/stdc++.h>
using namespace std;

// question link: 

class Solution {
    // VERY IMPORTANT QUESTION
public:
    /*
        We try to built left and right halves and then work is done 
        we try to make left half by putting n/2 elements in it 

        we try combinations by picking x elements from the nums1, and y elements from nums2 and then check 
        the sortness based on the the two arrays 
        Example 
        arr1 => 1 3 4 7 10 12 => n = 6
        arr2 => 2 3 6 15 => m = 4
        combined size is 10 so we have to place 5 elements on the left and 5 on the right
              1 3 4 7 | 10 12   we check if 2 < 10 and 7 < 3 not true means take more elements from nums2
                    2 | 3 6 15  

            The correct configuration for this array would be 
              1 3 4->l1 | 7->r1 10 12
                2 3->l2 | 6-> r2 15
                this will work as nums1[l1] < nums2[r2] and nums2[l2] < nums1[r1] 
                median = (max(l1, l2) + min(r1, r2)) / 2;
        We can use the min(nums1.size(), nums2.size()) to use binary search on it 

        if l1 > r2 then high element in nums2 needs to be eleminated : high = mid - 1
        if l2 > r1 then lower element in nums1 needs to be eleminated : low = mid + 1

        Time Complexity = O(Log(min(m, n)))
    
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we keep the nums1 as the smaller array 
        if(nums2.size() == min(nums1.size(), nums2.size())) swap(nums1, nums2);
        int n1 = nums1.size(), n2 = nums2.size();
        int len = n1+n2;

        // low is min i pick up from the array, high means i take all the elements from nums1 and place it in the left array
        // we need (n+m+1)/2 elements on the left part of the array 
        int low = 0, high = nums1.size();
        while(low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = (len + 1)/2 - mid1;
            // mid1 is the no of elements we can pick from array 1 and mid2 is the no we pick from array 2
            int l1 = INT_MIN, l2 = INT_MIN;  // this is done because when mid1 or mid2 = 0 it can cause out of bounds 
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1) {
                if(len & 1) return (double)max(l1, l2);
                else return ((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
            }
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0.0;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);

    for(int i=0; i<n; i++) {
        cin >> nums1[i];
    }

    for(int i=0; i<m; i++) {
        cin >> nums2[i];
    }

    Solution s = Solution();
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}