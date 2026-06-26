// =========================================================== Sliding Window ======================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

/* Explanation: sliding window => window of variable size 
   here we cant choose to extend window by using the op to convert to some random char 
   So try using the op to swap the chars to all letters c = A to Z
   and then for each char it becomes easy variable size sliding window to get the longest substring 

   deal with the case of k = 0 separately => as it is simply just the max length of consecutive repeated char

   Time Complexity = O(26 * N) 
   this method can be optimised in which we only use the ops to change the next letter into the one that has maxfreq
*/

class Solution {
public:
    int characterReplacement(string &s, int k) {
        int n = s.length();
        
        // base case: no ops allowed so simply return the max length of consecutive chars
        if(k == 0) {
            int maxi = 1, i = 0;

            while(i < n) {
                int j = i;
                while(j < n && s[j] == s[i]) j++;

                maxi = max(maxi, j-i);
                i = j;
            }

            return maxi;
        }

        int res = 1;

        for(char c = 'A'; c <= 'Z'; c++) {
            // start with a window of size 1 
            int l = 0, r = 0, ops = 0;

            if(s[0] != c) ops++;

            while(r+1 < n) {
                // expand the sliding window to include r+1
                if(s[r+1] == c) {
                    r++;
                }
                else {
                    // either use of the ops (if < k) or shrink the window 
                    if(ops == k) {
                        while(s[l] == c) l++;
        
                        l++;
                        ops--;
                    }
                    
                    // ops < k so now extend the window by using the op
                    r++;
                    ops++;
                }

                res = max(res, r-l+1);
            }
        }

        return res;
    }
};


// ====================================================== Optimised Solution ====================================================
