// ============================================ sliding window ========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

// The key is to think that for each ending index r how many valid substrings are possible 
// => so form the most minimum valid substring ending in r and then we can extend to the left to get multiple substrings 

/* Explanation: Sliding Window => counting number of suubarrays by using the concept of window of variable size 
   Like sliding window questions to get length of longest subarray we use the same concept of expansion and 
   shrinking of the window 

   When we get a valid substring (i.e. a valid window) and then when we add more characters our substring will always 
   be valid 

   With every character there is a substring that ends in it (this is very imporant part to think)
   count the number of substrings (by keeping one end fix) => here the ones that end in it 
   So in the sliding window => at each r find the minimal substring [l..r] that will be valid 
   and then for each such [l...r] => update the cnt = cnt + (l+1)

   To get the minimum possible window that is valid ending in r => use lastSeen index 
   bbacba => when we are at c then lastSeen = {a = 2, b = 1, c = 3} (min possible window will be min of lastSeen)
*/

class Solution {
public:
    int numberOfSubstrings(string &s) {
        int n = s.length();

        int cnt = 0;
        vector<int> lastSeen(3, -1);
        // 0 => a, 1 => b, 2 => c
        // cnt number of subarrays ending in the index in r

        for(int r = 0; r < n; r++) {
            // include the r element into the window 
            lastSeen[s[r] - 'a'] = r;

            // window is valid when none of the lastSeen is negative 
            int mn = min({lastSeen[0], lastSeen[1], lastSeen[2]});

            if(mn != -1) cnt += (mn + 1);
        }

        return cnt;
    }
};