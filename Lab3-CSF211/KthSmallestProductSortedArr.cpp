#include<bits/stdc++.h>
using namespace std;


// question link: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/
// VERY IMPORTANT Question 

// CONFIDENCE BREAKER Leetcode HARD Question 

/*
    Algorithm: 
        Like all other Kth smallesr element questions we solve the question using Binary search on the ans 
        Here we apply binaray search on the product between the min product and max product 

        And the predicate function like usual finds the no of times the products less than x appear 
        This is achived in O(n*Log(n)) where we apply binary search to find the appropriate best index 
        using binary search for each element of nums1.
        This will result in 3 cases when a is +ve, -ve and 0, 
        Remember when a is negative then on multiplication with all the elements in the array the array 
        becomes sorted in descending order 
*/


class Solution {
public:
    // predicate function returns FFFFFTTTT => we find the first occurrence of T 
    // this function returns T when the no of pairs with product <= x is equal to or more than k
    bool predicate(vector<int>&nums1, vector<int>&nums2, long long k, long long x) {
        int n2 = nums2.size();
        long long ctr = 0;
        for(int a: nums1) {
            if(a > 0) {    // a is positive
                // Find max j where a * nums2[j] <= x  ==> find the upper limit value
                // all the elements till this element will be smaller than this 
                int l = 0, r = n2 -1, best = -1;
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    if(a * 1LL * nums2[mid] <= x) {
                        best = mid; 
                        l = mid + 1; 
                    }
                    else r = mid - 1;
                }
                ctr += (best + 1);
            }
            else if(a < 0) {  
                // the order of multiplication flips when we multiply with a negative number 
                // Find min j where a * nums2[j] <= x  => find the lower limit value 
                int l = 0, r = n2 - 1, best = n2;
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    if(a * 1LL * nums2[mid] <= x) { 
                        best = mid; 
                        r = mid - 1; 
                    }
                    else l = mid + 1;
                }
                ctr += (n2 - best);
            }
            else {   // when nums1[i] = a is 0 
                if(x >= 0) ctr += n2;
            }
        }
        if(ctr >= k) return true;
        else return false;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        // nums1 and nums2 are sorted arrays 
        int n1 = nums1.size(), n2 = nums2.size();
        // find the pointers that point the first positive element in the nums array
        // l will be miniumum of all the cases 
        long long l = min({
            nums1[0] * 1LL * nums2[0], 
            nums1[0] * 1LL * nums2[n2-1], 
            nums1[n1-1] * 1LL * nums2[0], 
            nums1[n1-1] * 1LL * nums2[n2-1]
        });
        // r will be the max of all the cases 
        long long r = max({
            nums1[0] * 1LL * nums2[0], 
            nums1[0] * 1LL * nums2[n2-1], 
            nums1[n1-1] * 1LL * nums2[0], 
            nums1[n1-1] * 1LL * nums2[n2-1]
        });

        // similar to all the kth smallest questions we apply binary search on the ans 
        long long ans = -1;
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            if(predicate(nums1, nums2, k, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        } 
        return ans;
    }
};


int main() {
    int n1, n2;
    long long k;
    cin >> n1 >> n2 >> k;

    vector<int> nums1(n1), nums2(n2);

    for(int i=0; i<n1; i++) 
        cin >> nums1[i];

    for(int i=0; i<n2; i++) 
        cin >> nums2[i];

    Solution s = Solution();
    cout << s.kthSmallestProduct(nums1, nums2, k) << endl;

}