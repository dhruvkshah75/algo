#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
// MEDIUM Leetcode 

/*
    Algorithm: 
        We apply binary Search on the ans i.e. the fractions 
        now the problem is that we have to check how many fractions exist that are <= x (x is the mid of binaray search 
        that we apply) 
        for that we use a 2 pointer approach to get the fractions that are less than x (double)
        1. **Two-Pointer Scan:** Iterate numerator index `i`. For each `i`, 
            advance denominator index `j` until `arr[i] / arr[j] <= x`. 
            All indices from `j` to `n-1` are valid denominators for `i`. Add `n - j` to `count`.
        2. **Track Best Candidate:** *Crucial Step* — Inside the loop, 
            track the **largest** fraction `p/q` encountered that is still ` <= x`. 
            This handles the fact that we are searching on floats but need to return integers.
        3. **Adjust Bounds:**
            * If `count == k`: Return `{p, q}` immediately.
            * If `count < k`: `low = mid` (We need more fractions).
            * If `count > k`: `high = mid` (We have too many, squeeze down).
            * 
        
        The most important part of this question is to keep the track of the curr_max_fraction as this is the final ans 
*/


class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, r = 1.0;
        
        // keep on applying until we get total == k 
        while (l < r) {
            double mid = l + (r - l) / 2;
            // this vars store the ans fraction 
            int max_num = 0, max_den = 1;
            int total = 0;
            int j = 1;
            
            // Find count of fractions <= mid
            for (int i = 0; i + 1 < n; i++) {
                // Determine the valid window of denominators for numerator arr[i]
                // We need arr[i] / arr[j] <= mid  =>  arr[j] >= arr[i] / mid
                while (j < n && arr[i] > mid * arr[j]) {
                    j++;
                }
                
                if (j == n) break; 

                total += (n - j);   
                // we track the maximum fraction that we found in the valid set 
                if (total > 0) { 
                    double curr_val = (double)arr[i] / arr[j];
                    double max_val = (double)max_num / max_den;
                    if (curr_val > max_val) {
                        max_num = arr[i];
                        max_den = arr[j];
                    }
                }
            }
            // We found exactly k fractions <= mid when total == k
            if (total == k) return {max_num, max_den};
            else if (total > k) r = mid;
            else l = mid;
        }
        return {};
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i=0; i<n; i++) 
        cin >> arr[i];

    Solution s = Solution();

    vector<int> ans = s.kthSmallestPrimeFraction(arr, k) ;

    for(int a: ans) {
        cout << a << " ";
    }
    cout << endl;
}