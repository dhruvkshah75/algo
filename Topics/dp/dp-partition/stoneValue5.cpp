// ============================================================= partition dp ====================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/stone-game-v

/* Explanation: partition dp 
   here we must try out all the possible divisions and then check what max score can alice earn 
   The question is much simpler than it seems => alice will partition the stones into two sets 
   and the one with max score (sum of stones will be discarded) then solve the part that is left 
   Bob doesnt choose anything he will just help in discarding the stones 
   So using partition dp try out all the possible partitions to get the max points alice can get 

   recurrence f(int i, int j) => returns the max score alice can earn 
   start with the entire stone block (0, n-1)
*/

class Solution {
private:
    int n;
    int dp[501][501];
    vector<int> prefix;

    int f(int i, int j) {
        // base case: when only 1 element in the partition 
        if(j-i+1 == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int max_score = 0;

        for(int k = i; k < j; k++) {
            // partition is created => k | k+1
            int sum1 = prefix[k] - prefix[i-1];
            int sum2 = prefix[j] - prefix[k];

            if(sum1 > sum2) {
                // bob throws away the stones in [i...k]
                max_score = max(max_score, sum2 + f(k+1, j));
            }
            else if(sum1 < sum2) {
                // bob throws away the stones in [k+1...j] 
                max_score = max(max_score, sum1 + f(i, k));
            }
            else {
                // when sum1 = sum2 are max then we can must compare both their scores 
                int choice1 = f(k+1, j), choice2 = f(i, k);
                max_score = max(max_score, sum1 + max(choice1, choice2));
            }
        }

        return dp[i][j] = max_score;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();

        // keep the prefix sum 1 based indexing 
        prefix.resize(n+1);
        prefix[0] = 0;

        for(int i = 1; i <= n; i++) 
            prefix[i] = prefix[i-1] + stoneValue[i-1];

        // prefix sum to calculate the sum in O(1)

        memset(dp, -1, sizeof(dp));

        // the block is [1...n] (1 based indexing)
        return f(1, n);
    }
};