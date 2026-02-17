#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/valid-parentheses/description/

/*
    Algorithm: 
        We simply push in any left parenthesis => (, {, [
        as soon as a right parenthesis appears we check if the left parenthesis exists or not 
*/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        string chk = "({[";
        stack<char> st;
        for(int i=0; i<n; i++){
            if(chk.find(s[i]) != string::npos){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(s[i] == ')'){
                    if(st.top() == '(') st.pop();
                    else return false;
                }
                else if(s[i] == '}'){
                    if(st.top() == '{') st.pop();
                    else return false;
                }
                else if(s[i] == ']'){
                    if(st.top() == '[') st.pop();
                    else return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};