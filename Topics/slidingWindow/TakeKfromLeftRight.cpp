// ================================================= sliding window ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/

/* Explanation: sliding window => window of variable size 
   we are supposed to take characters from left and right such that we get at least k occurrences of 'a', 'b' and 'c'
   to make this question into a sliding window question => consider the reverse 
   the part that we are not taking => sliding window 

   we need at least k characters of each char outside of window => inside window we can have 
   at most mp[c] - k occurrences of character c 
   So get the maximum sliding window 

   So expand the window always (for all r) and then shrink if the window becomes invalid 
*/

class Solution {
public:
    int takeCharacters(string &s, int k) {
        int n = s.length();

        int cntA = 0, cntB = 0, cntC = 0;

        for(char c: s) {
            if(c == 'a') cntA++;
            else if(c == 'b') cntB++;
            else cntC++;
        }

        // get the longest substring such that we have at most mp[c]-k
        vector<int> window(3, 0);

        int l = 0, maxi = -1;
        int allowed_A = cntA-k, allowed_B = cntB-k, allowed_C = cntC-k;

        // base case: when allowed of any of a, b, c is negative 
        if(allowed_A < 0 || allowed_B < 0 || allowed_C < 0) return -1;

        for(int r = 0; r < n; r++) {
            window[s[r]-'a']++;

            // shrink if the window becomes invalid (that is the freq of a, b or c is more than allowed freq)
            while(window[0] > allowed_A || window[1] > allowed_B || window[2] > allowed_C) {
                window[s[l]-'a']--;
                l++;
            } 

            maxi = max(maxi, r-l+1);
        }

        return n - maxi;
    }
};