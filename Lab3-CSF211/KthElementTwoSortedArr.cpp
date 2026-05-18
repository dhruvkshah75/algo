// Use the similar logic of median of two sorted arrays 
// like the median instead of searching for mid/2 element we will search for kth element 

// Time complexity is O(log(min(m,n)))


// Question is exactly same as median of two sorted arrays instead of taking elements x and y from nums1 and nums2 
//  with condition of x + y = (len+1) / 2 we take x + y = k elements 

#include<bits/stdc++.h>
using namespace std;

// question link: https://takeuforward.org/plus/dsa/problems/kth-element-of-2-sorted-arrays


class Solution {
public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();

        if (n > m)  // swap the arrays 
            return kthElement(nums2, nums1, k);
        
        // Choice of low and high is very important 
        // low: we must take at least this many from nums1 if k > m
        // high: we can take at most n elements or k elements
        int low = max(0, k - m), high = min(k, n);
        while (low <= high) {
            int mid1 = low + (high - low) / 2; // Elements taken from nums1
            int mid2 = k - mid1;               // Elements taken from nums2

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == m) ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) // We found the correct partition
                return max(l1, l2);
            else if (l1 > r2) // Too many elements from nums1, move left
                high = mid1 - 1;
            else // Too few elements from nums1, move right
                low = mid1 + 1;
        }
        return 0;
    }
};


int main() {
    int n1, n2, k;
    cin >> n1 >> n2 >> k;
    vector<int> a(n1), b(n2);

    for(int i=0; i<n1; i++) 
        cin >> a[i];

    for(int i=0; i<n2; i++)
        cin >> b[i];

    Solution s = Solution();
    cout << s.kthElement(a, b, k) << endl;
}