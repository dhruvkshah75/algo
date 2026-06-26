// ====================================================== state machine dp ==============================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/

/* Explanation: multi state dp => similar logic to best time to buy and sell stock II
   use two states => pos (what position on the line we are), rem (how many more segments are there)
   There is issue with only these 2 states how to determine when the segment is started and when it has ended 
   use anathor state => flag = 0 or 1 ===> similar to hold state in buy and sell stocks II

   recurrence f(pos, rem, flag) => number of segments in [pos....n] with rem no of segments remaining 
   flag = 0 => currently no segment and we are allowed to start the segment by placing startpoint of segment 
   and then make flag = 1 
   flag = 1 => current segment has already started so we can end the segment at any point and then make flag = 0

   Note for this question: when a segment ends a new segment can start exactly at this point (must have at least 2 points)
   Valid points are 0..N-1 
*/

typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;

    int f(int pos, int rem, int flag, int n) {
        // base case: all segments are placed 
        if(rem == 0) return 1;

        // base case: when pos becomes invalid 
        if(pos >= n) return 0;

        if(dp[pos][rem][flag] != -1) return dp[pos][rem][flag];

        // try both cases for flag = 0 and flag = 1
        ll res = 0;

        if(flag == 0) {
            // option 1: skip this point (dont start the segment yet)
            res = (res + f(pos+1, rem, 0, n)) % MOD;
            // option 2: start the segment here 
            res = (res + f(pos+1, rem, 1, n)) % MOD;

        }
        else {
            // option 1: End the current segment here (rem-1 segments left)
            res = (res + f(pos, rem-1, 0, n)) % MOD;
            // option 2: Continue the current segment
            res = (res + f(pos+1, rem, 1, n)) % MOD;
        }

        return dp[pos][rem][flag] = res % MOD;
    }

public:
    int numberOfSets(int n, int k) {
        
        dp.resize(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));

        // start from the 0th position index and we can start our segment 
        return f(0, k, 0, n);
    }
};