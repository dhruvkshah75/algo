// ====================================== sliding window ==================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/binary-subarrays-with-sum/

/* Explanation: sliding window + counting number of subarrays (3rd pattern) 
   Similar to the logic of variable size window => expand the window until we get a valid subarry (window)
   and when the window becomes invalid and so shrink the window from the left 
   but shrinking and expanding will miss out sum subarrays 

   break the problem into => (number of subarrays with sum <= k) - (number of subarrays with sum <= k-1)
   this results in gettings number of subarrays with sum = k
   And calculate the subarrays ending in r whose sum <= k  =>>> this works as sum <= k as all nums are positive  
  
   if we have a valid windo [l...r] with sum <= k so the number of subarrays will [l...r], [l+1,...r], [l+2,...r], ...[r]
   so it is cnt = cnt + (r-l+1) [technically still the same concept of subarrays ending in r]
*/

class Solution {
private:
    int n;
    // f -> returns the no of subarrays with sum <= k

    int f(vector<int> &nums, int k) {
        int l = 0, sum = 0, cnt = 0;

        for(int r = 0; r < n; r++) {
            sum += nums[r];
            // now check if the window [l...r] is valid or not 
            while(sum > k) {
                sum -= nums[l];
                l++;
            }
            // add the number of subarrays ending in r 
            cnt += (r-l+1);
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        n = nums.size();

        int x = f(nums, goal);
        int y = ((goal >= 1) ? f(nums, goal-1) : 0);

        return x - y;
    }
};