#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/minimum-window-substring/description/

// Think of a better approach O(M + N) 
// My approach is O(N*K) where K = 26 in the worst case 

class Solution {
    bool validWindow(unordered_map<char,int>&freq, unordered_map<char,int>&window) {
        // the cnts of window should be more than freqs 
        for(auto &[c, cnt]: freq) {
            if(window.find(c) == window.end())
                return false;
            else if(window[c] < cnt)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) 
            return "";

        unordered_map<char,int> freq;
        // populate the frequency 
        for(char c : t) 
            freq[c]++;

        int l = 0, r = 0, minLen = INT_MAX; 
        int startIdx = 0;

        unordered_map<char,int> window;

        while(r < s.length()) {
            window[s[r]]++; // Add right char
            
            // While the current window is valid, try to shrink it
            while(validWindow(freq, window)) {
                // Now we know that this window is valid and with smaller window size update the length
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }
                // remove the left most cnt from the window 
                window[s[l]]--; 
                l++;
            }
            r++;
        }
        
        // Only return a string if minLen was actually updated
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};