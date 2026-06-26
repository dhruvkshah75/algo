#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// question link: https://leetcode.com/problems/rotate-function/

/* Explaination: 
   Not a traditional pattern dp => question is based on getting a recurrence relation to calculate the F(k) in O(1) time 
   Simply establish a connection between F(k) and F(k-1) => this gives us the recurrence  

   eg 1: nums = [4, 3, 2, 6]
   F(0) = 0 * 4 + 1 * 3 + 2 * 2 + 3 * 6 
   F(1) = 1 * 4 + 2 * 3 + 3 * 2 + 0 * 6

   From this F(1) - F(0) = 4 + 3 + 2 + 6 - 4 * 6
   similarly F(2) - F(1) = 4 + 3 + 2 + 6 - 4 * 2

   So the reccurence or the pattern figured out 
   F(k) - F(k-1) = sum(nums) - len * nums[len-k] for all k = 1...n
*/

// ================================================= Very Important Question ======================================================================

#define all(x) x.begin(), x.end()

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(all(nums), 0);

        vector<int> dp(n);
        // dp[i] => F(i) rotate function 

        for(int i = 0; i < n; i++) 
            dp[0] += (i * nums[i]);

        // using the recurrence calculate the other rotate functions (dp)
        int res = dp[0];

        for(int i = 1; i < n; i++) {
            dp[i] = dp[i-1] + total - n * nums[n-i];
            res = max(res, dp[i]);
        }

        // res => max of all rotate functions F(k) = dp[k]
        return res;
    }
};

// The above solution can be space optimised as each calc depends on dp[i-1]

// ================================================= Space Optimised Solution ==================================================================

#define all(x) x.begin(), x.end()

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(all(nums), 0);

        int prev = 0, curr = 0;
        // prev => dp[i-1] and curr => dp[i]
        // dp[i] => F(i) rotate function 

        for(int i = 0; i < n; i++) 
            prev += (i * nums[i]);

        // using the recurrence calculate the other rotate functions (dp)
        int res = prev;

        for(int i = 1; i < n; i++) {
            curr = prev + total - n * nums[n-i];
            res = max(res, curr);
            swap(prev, curr);
        }

        // res => max of all rotate functions F(k) = dp[k]
        return res;
    }
};