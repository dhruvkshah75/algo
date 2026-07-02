// ============================================================ sliding window =============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

/* Explanation: sliding window + minimum window logic (4th pattern)
   to get the minimum window => expand the window and shrink the valid window untill the window remains valid 
   this ensures we get the smallest window 

   For each index r => get the valid window => [l...r]
   then all the subarrays [0...r], [1...r], .... [l,...,r] => will contain the max element at least k times 
   such subarrays will be (l+1)

   using sliding window => get the minimum window => which means the window with max element coming at least k times 
*/

typedef long long ll;

class Solution {
public:
    ll countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        // sliding window to get the minimum window such that there are at least k occurrences of the max element 
        int l = 0, cnt = 0;
        ll res = 0;

        for(int r = 0; r < n; r++) {
            // expand the window on right => when nums[r] is max element
            if(nums[r] == mx) cnt++;

            // shrink the valid window until the window remains valid 
            while(l < n && cnt >= k) {
                if(nums[l] == mx) {
                    // cannot further shrink 
                    if(cnt == k) break;

                    cnt--;
                }
                l++;
            }

            if(cnt >= k) res += (l+1);
        }

        return res;
    }
};