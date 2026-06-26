// ======================================================= dp - LIS ======================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// question link: https://takeuforward.org/plus/dsa/problems/longest-bitonic-subsequence?source=strivers-a2z-dsa-track

/* Explaination: 
   Forming sequences of mountain peaks => increasing for some numbers and then decreasing 
   This Question is a LIS variant => just instead of increasing the sequence the sequence needs to be a mountain 

    Consider each point as the peak in the mountain and then find the LIS ending at this element 
    and find LDS (longest decreasing subsequence) starting at this index 
*/

class Solution {
private:
    int lis(int ind, vector<int> &arr, vector<int> &dp) {
        // base case is implicit 
        if(dp[ind] != -1) return dp[ind];

        // calculate the max length of the lis ending in arr[ind]
        int maxi = 1;

        for(int j = 0; j < ind; j++) {
            if(arr[j] < arr[ind]) maxi = max(maxi, 1 + lis(j, arr, dp));
        }

        return dp[ind] = maxi;
    }

    int lds(int ind, vector<int> &arr, vector<int> &dp) {
        // base case is also implicit 
        // this gives the length of decreasing sequence starting from arr[ind]
        if(dp[ind] != -1) return dp[ind];

        int maxi = 1;

        for(int j = ind+1; j < (int)arr.size(); j++) {
            if(arr[ind] > arr[j]) maxi = max(maxi, 1 + lds(j, arr, dp));
        }

        return dp[ind] = maxi;
    }

public:
    int longestBitonicSequence(int n, vector<int> &arr) {
        vector<int> dp1(n, -1), dp2(n, -1);

        // consider each element as the peak element
        // find the len of lis ending in the ith element and len of lds starting with the ith element
        int res = 0;

        for(int ind = 0; ind < n; ind++) {
            // arr[ind] is counted twice in both the values 
            int left = lis(ind, arr, dp1);
            int right = lds(ind, arr, dp2);
            // both left and right values must be more than 1 to be valid 
            if(left > 1 && right > 1) 
                res = max(res, left + right - 1);
        }

        return res;
    }
};