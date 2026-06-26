// ========================================== dp on lis ===========================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

/* Explanation: LIS variant => question is similar to longest bitonic sequence 
   get the longest increasing subesequence ending in the ith element => dp1[i]
   lis => prefix [0...ind]
   and the longest decreasing subsequence starting from the ith element => dp2[i]
   lds = suffix[ind...n]
   and keep each element as the peak of the mountain 
*/

// =======================================================================================================
//                                      Bottom Up Approach Tabulation dp
// =======================================================================================================

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n, 1), dp2(n, 1);

        // lis 
        for(int ind = 0; ind < n; ind++) {
            int maxi = 1;
            // get the max length of lis ending at ind th index
            for(int j = 0; j < ind; j++) {
                if(nums[j] < nums[ind]) {
                    maxi = max(maxi, 1 + dp1[j]);
                }
            }
            dp1[ind] = maxi;
        }

        // lds 
        for(int ind = n-1; ind >= 0; ind--) {
            int maxi = 1;
            // get the max length of lds starting with ind th index 
            for(int j = ind+1; j < n; j++) {
                if(nums[j] < nums[ind]) {
                    maxi = max(maxi, 1 + dp2[j]);
                }
            }
            dp2[ind] = maxi;
        }

        int res = 0;

        for(int i = 0; i < n; i++) {
            // keep nums[i] as the peak element 
            int left = dp1[i], right = dp2[i];
            if(left >= 2 && right >= 2) 
                res = max(res, left+right-1);
        }

        return n - res;
    }
};