// ============================================== sliding window ===============================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/

/* Explanation: sliding window => minimum window 
   Very Important: Exactly same logic as Mimimum Window Substring 

   for each r find the minimum valid window and then calculate tge valid window 
   suppose the valid window is [l...r] => all possible substrings ending in r will be 
   [0...r], [1...r], ... [l...r] => cnt = (l+1)

   or the other way would be counting all the invalid substrings and subtract them from the total 
   substrings => total = n*n-1 / 2 => C(n, 2)

   Match concept to check if the window is valid => prefill the freq array with positive freq 
   and when we expand the array and then we reduce the freq 
   when freq[c] = 0 => then match++;
*/

typedef long long ll;

class Solution {
public:
    ll validSubstringCount(string &word1, string &word2) {
        int n1 = word1.length(), n2 = word2.length();

        // base case: target string is larger than the main string s 
        if(n2 > n1) return 0;

        // prefill the target string 
        vector<int> freq(26, 0);

        for(char c: word2) 
            freq[c-'a']++;

        // count the distinct chars in the string 
        int distinct = 0;

        for(int x: freq) 
            if(x > 0) distinct++;

        // sliding window => to get the minimum window 
        int l = 0, match = 0;
        ll res = 0;

        for(int r = 0; r < n1; r++) {
            // expand the window => subtract the freq of s[r]
            int ind = word1[r] - 'a';
            freq[ind]--;
            if(freq[ind] == 0) match++;

            // shrink the valid window until it remains valid
            while(l < n1 && match == distinct) {
                int idx = word1[l]-'a';
                // we cannot further shrink without making the window invalid 
                if(freq[idx] == 0) break;

                freq[idx]++;
                l++;
            }

            if(match == distinct) res += (l+1);
        }

        return res;
    }
};