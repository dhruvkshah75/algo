// =============================================== dp LIS ===============================================================

#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/


// ====================================== Very Important Question =======================================================

// how to get the intuition to solve this question => simulate the lis tabulation code 

/* Explaination: LIS variant 
   code for lis is pretty straightforward 
   here the length matters so directly cannot apply the logic of counting dp 
   we must only return for those lis whose length is the maximum 
   Maintain two arrays => dp (length of lis) and cnt (number of lis) 

   cnt => how does this work 
   when similar ways to reach to length of l to it are encountered 
*/

#define all(x) x.begin(), x.end()

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1), cnt(n, 1);
        // dp and cnt are initialiased to 1 => single element lis is of length 1 and 1 such lis 

        for(int ind = 0; ind < n; ind++) {
            // try out all possible numbers in prefix [0...ind-1]
            int maxi = 1;

            for(int j = 0; j < ind; j++) {
                if(nums[j] >= nums[ind]) continue;

                // nums[j] < nums[ind]
                if(maxi < 1 + dp[j]) {
                    maxi = 1 + dp[j];
                    cnt[ind] = cnt[j];   
                    // cnt[i] = no of lis till jth 
                }       
                else if(maxi == 1 + dp[j]) { 
                    cnt[ind] += cnt[j];
                    // found one more lis of the same max length
                }
            }
            
            dp[ind] = maxi;
        }

        // dp contains the lis with max length and cnt[i] contains count of lis with dp[i] length ending in the ith element 
        int lis = *max_element(all(dp));

        // all those dp entries with length = lis must be summed up to get the final total number of lis
        int res = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == lis) res += cnt[i];
        }

        return res;
    }
};