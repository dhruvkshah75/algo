// ================================ greedy =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/construct-k-palindrome-strings/description/

/**
 * A palindromic substring can have at most character with odd freq 
 * so if there are more than k characters whose freq is odd then we cannot form K palindromic substrings 
 * if the odd number of characters are <= K then we can always rearrange the string to get k palindromic strings 
 * within the given string  
 * */

class Solution {
public:
    bool canConstruct(string &s, int k) {
        int n = s.length();

        // base case: invalid number of palindromes needed 
        if(k > n) return false;

        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++) 
        	freq[s[i] - 'a']++;

       	int odd_cnt = 0;
       	for(int cnt: freq) 
       		if(cnt & 1) odd_cnt++;

       	// if odd_count characters are more than k then false otherwise we can always form k palindromic strings 
        return odd_cnt <= k;
    }
};