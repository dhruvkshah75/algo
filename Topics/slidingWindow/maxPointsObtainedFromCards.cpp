// ================================================ Sliding Window ================================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

/* Explanation: Sliding Window => constant window pattern 
   here we are supposed to take elements from the last or first element => we cant be greedy to select this 
   since we are suppose to take k cards => simply think in the reverse direction 
   consider a sliding window of n-k size which tracks the cards not taken 

   so maximise the remaining sum => max(total_sum - sliding_window_sum) */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        // maintain the size of sliding window = n-k
        int sz = n-k;

        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int l = 0, r = sz-1, sum = 0;
        // initialise the sliding window l = 0, r = sz-1;
        
        for(int i = l; i <= r; i++) 
            sum += cardPoints[i];

        int res = total - sum;

        while(r+1 < n) {
            sum = sum - cardPoints[l];
            l++;
            r++;
            sum = sum + cardPoints[r];
            // moved the sliding window by 1 
            res = max(res, total-sum);
        }

        return res;
    }
};