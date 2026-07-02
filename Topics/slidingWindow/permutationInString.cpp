// ============================================= sliding window ===================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/permutation-in-string/

/* Explanation: sliding window => window of fixed size 
   the window size that we must compare here is s2.length()
   so expansion and shrinking of the string is pretty much constant
   Now to check if the window is a valid permuatation of the string is easy => O(26) compare the freq arrays 

   But to solve it in O(1) time => we can do this easily by comparing the chars match in the window 
   and target string s1 
   While expanding the window to include => s[r] => if the freq match then we found a match => match++
   and if the freq exceeds by 1 => char count unmatches => match--
   and similarly for the case of shrinking when the size of the window exceeds n1 

   The other solution is obvious to check if the window is valid permutation compare the frequencies => O(26)
   Total Time Complexity = O(26 * N)
*/

class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        int n1 = s1.length(), n2 = s2.length();

        unordered_set<char> st(s1.begin(), s1.end());
        int distinct_chars = st.size();

        vector<int> target(26, 0), window(26, 0);

        // store the frequency count of the target => s1 string 
        for(int i = 0; i < n1; i++) 
            target[s1[i]-'a']++;

        int l = 0, match = 0;

        for(int r = 0; r < n2; r++) {
            // expand the window to include s2[r]
            int c = s2[r] - 'a';
            window[c]++;

            if(window[c] == target[c]) match++;
            else if(window[c] == target[c] + 1) match--;

            // shrink the window if size exceeds 
            if(r-l+1 > n1) {
                int c = s2[l]-'a';
                window[c]--;

                // now check after removing s2[l] did it create a match or unmatch
                if(window[c] == target[c]) match++;
                else if(window[c] == target[c] - 1) match--;
                l++;
            }

            // the current window is a permutation of s1 iff match = distinct_chars in s1
            if(r-l+1 == n1 && match == distinct_chars) return true;
        }

        return false;
    }
};

// The other solution is obvious to check if the window is valid permutation compare the frequencies => O(26)
// Total Time Complexity = O(26 * N)