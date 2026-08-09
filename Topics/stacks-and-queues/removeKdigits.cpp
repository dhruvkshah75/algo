// =============================== monotonic stack ==========================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/remove-k-digits/description/

/**
 * use a monotonic increasing stack => as soon as we get a better digit (smaller) then 
 * pop from the stack i.e. use one of the k operations that we have 
 * Pop only when the current number currently is strictly smaller than the st.top()
 * 
 * edge case: when all the numbers are in increasing order => "12345" and k = 2 
 * then pop out 2 elements at the last 
 **/

class Solution {
public:
    string removeKdigits(string &s, int k) {
        int n = s.length();

        // base case: n = k => remove all n digits 
        if(n == k) return "0";

        stack<int> st;
        // monotonic increasing stack
        int pops = k; 

        for(int i = 0; i < n; i++) {
        	char curr = s[i];

        	while(!st.empty() && curr < s[st.top()] && pops > 0) {
        		// both current and top are 0 => dont pop as they are leading 0s
        		if(curr == '0' && s[st.top()] == '0') break;
        		st.pop();
        		pops--;
        	}

        	st.push(i);
        }

        // if some pops are left then remove from the end 
        while(pops > 0) {
        	st.pop();
        	pops--;
        }

        // now the stack contains the smallest string after all the k ops 
        string res = "";
        while(!st.empty()) {
        	res += s[st.top()];
        	st.pop();
        }

        reverse(res.begin(), res.end());

        // remove all the leading zeros from the string 
        int j = 0;
        while(j < res.length() && res[j] == '0') j++;

        if(j == res.length()) return "0";

        return res.substr(j);
    }
};