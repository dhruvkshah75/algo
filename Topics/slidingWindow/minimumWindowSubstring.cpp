// ========================================= sliding window ===================================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-window-substring/

/* Explanation: sliding window (4th pattern)
   Here we expand the window and shrink till the window is valid 
   we never shrink to make the window invalid 

   For maximum sliding window => we expand and shrink when the window becomes 
   invalid to make the window valid

   Use the concept of match (using hash maps) to check if the window is valid or not 
   concept to check the window is valid or not:
   prefill the map with frequences (positive) of the target string t 
   and then while traversing the window => reduce the frequences once we encounter a char
   when the count of a prefilled char becomes zero => match++;

   Very Important Note: 
   1. For longest sliding window pattern => expand always and then shrink when the window is 
      invalid until the window becomes valid
   2. for Minimum sliding Window OR shortest subarray: expand always (for(r = 0 to n)) and shrink when the current window 
      is valid and shrink only till it remains valid not more than that 
*/

class Solution {
public:
    string minWindow(string &s, string &t) {
        int m = s.length(), n = t.length();

        // base case: when t is bigger than s
        if(m < n) return "";

        unordered_map<char,int> mp;
        for(char c: t) mp[c]++;

        int distinct = mp.size();

        int l = 0, minLen = 1e6, startIdx = -1, match = 0;
        
        for(int r = 0; r < m; r++) {
            // expand the window => reduce the freq of s[r]
            mp[s[r]]--;
            if(mp[s[r]] == 0) match++;

            // shrink the window till it remains valid => we increase the freq of char 
            while(l < m && match == distinct) {
                char c = s[l];
                // if freq is already 0 => then we remove it from window means it is a needed character  
                if(mp[c] == 0) break;

                mp[c]++;
                l++;
            }

            if(match == distinct && r-l+1 < minLen) {
                minLen = r-l+1;
                startIdx = l;
            } 
        }

        if(startIdx == -1) 
            return "";
        else 
            return s.substr(startIdx, minLen);
    }   
};