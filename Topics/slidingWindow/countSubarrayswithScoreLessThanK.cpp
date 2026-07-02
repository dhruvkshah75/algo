// ================================================= sliding window ===================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

/* Explanation: sliding window + count number of subarrays
   If there is a valid window => [l...r] then the number of subarrays ending in r within the 
   given window all subarrays would be the answer => [l...r], [l+1...r],...,[r]

   Note: it is possible that a single element nums[i] * 1 >= k so there will be no subarrays ending in r 
   so shrink the window only until it becomes a window of size 1 
   and adding a valid subarray within [l...r] is only possible if (sum * len < K)
*/

typedef long long ll;

class Solution {
public:
    ll countSubarrays(vector<int>& nums, ll k) {
        int n = nums.size();

        int l = 0;
        ll cnt = 0, sum = 0;

        for(int r = 0; r < n; r++) {
            sum += nums[r];

            // shrink the window if it is not valid
            while(l <= r && sum * (r-l+1) >= k) {
                sum -= nums[l];
                l++;
            }

            // if [l...r] is a valid window then add the subarrays 
            if(sum*(r-l+1) < k) 
                cnt += (r-l+1);
        }

        return cnt;
    }
};