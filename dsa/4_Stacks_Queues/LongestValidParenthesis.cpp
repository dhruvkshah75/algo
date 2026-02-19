#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/longest-valid-parentheses/description/

// In this stack we store the indexes of all those elements which cant form a pair 
// so the valid parenthesis that are in the middle of those unmatched indexes

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;      // we push the indexes in the stack 
        // at the end stack will contain the indices of the s that cannot be matched 
        int max_len = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {   // right parenthesis encountered 
                if(!st.empty()) {
                    if(s[st.top()] == '(') st.pop();
                    else st.push(i);   // matching pair not found then push this index 
                }
                else st.push(i);
            }
        }
        // now the stack contains some indices that cant be matched, so the indices in between form valid parenthesis
        int a = n;
        while(!st.empty()) {
            int b = st.top();
            st.pop();
            max_len = max(max_len, a-b-1);
            a = b;   // update the a to the next element 
        }
        // at the end => a = x, b = 0 (comparing with the 0 index)
        max_len = max(max_len, a - 0);
        
        return max_len;
    }
};