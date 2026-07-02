// ================================================== sliding window =============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/get-equal-substrings-within-budget/description/

/* Explanation: sliding window with window of variable size 
   Here we must convert one substring into anathor subtring and cost of conversion is abs diff 
   we must convert the same corresponding character => at index i 

   start with the sliding window of size 0 and then expand to the right every time 
   and shrink when the cost to make the window of both strings the same => shrink until the window becomes valid 
*/

class Solution {
public:
    int equalSubstring(string &s, string &t, int maxCost) {
        int n = s.length();

        int l = 0, cost = 0, res = 0;

        // [l..r] => l never crosses r as the when l = r while shrinking the cost = 0

        for(int r = 0; r < n; r++) {
            cost += abs(s[r] - t[r]);

            // shrink the window if the cost > maxCost
            while(cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }

            res = max(res, r-l+1);
        }

        return res;
    }
};