// ================================================= sliding window =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

/* Explanation: Sliding Window + counting subarrays 
   A non intuitive trick to think about is => make all the even numbers 0 (as we dont care how many times 
   it comes into the subarray) => we only care the number of times a odd number comes 
   so make any odd number = 1 

   nums transforms into a binary array where k is number of odd numbers becomes K (sum)  
   Finally the question becomes => number of subarrays whose sum = k
   
   To solve this we find out number of subarrays ending at r (for all r) whose sum <= k
   final ans is (number of subarrays whose sum <= k) - (number of subarrays whose sum <= k-1)
*/

class Solution {
private:
    int n;

    int func(vector<int> &nums, int k) {
        // count the number of subarrays whose sum <= k
        int l = 0, sum = 0, cnt = 0;

        for(int r = 0; r < n; r++) {
            sum += nums[r];

            // shrink the window is the window becomes invalid 
            while(sum > k) {
                sum -= nums[l];
                l++;
            }
            // number of subarrays ending in r within [l...r] are (r-l+1) 
            // [l...r], [l+1...r],....,[r]
            cnt += (r-l+1);
        }

        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        n = nums.size();

        // replace odds => 1 and even => 0 (we dont care how many occurrences of even occur)
        for(int i = 0; i < n; i++) 
            nums[i] = (nums[i] & 1) ? 1 : 0;
        
        // (no of subarrays whose sum <= k) - (no of subarrays whose sum <= k-1) = no of subarrays whose sum = k
        return func(nums, k) - func(nums, k-1);
    }
};

