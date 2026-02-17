#include<bits/stdc++.h>
using namespace std;


// question link: https://www.geeksforgeeks.org/dsa/find-the-nearest-smaller-numbers-on-left-side-in-an-array/

/*
    In this question it makes sense for us to traverse in the forward direction as we want to check what element 
    appearing before it was so we traverse it => we use a monotonic increasing stack 

    Ex:
        arr = 1, 5, 0, 3, 4, 6, 2, 5
        the monotonic increasing stack must be used in forward direction
        -> the top of the stack will be the previous Smaller element 
        stack for
            5 =>  1  
            0 => empty  
            3 => 0
            4 => 0, 3 
            6 => 0, 3, 4  => here 4 is the prev smaller element => top of the stack
            2 => 0        => so in the previous step when the stack becomes 0, 3, 4, 6 we remove elements until curr <= top
            5 => 0, 2
*/



class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;  // a monotonic increasing stack 
        for(int i=0; i<n; i++) {
            int curr = arr[i];
            // if curr <= st.top() then we start poping and so the increasing bottom to up stack is maintained 
            while(!st.empty() && curr <= st.top()) {
                st.pop();
            }
            if(!st.empty()) {
                result[i] = st.top();
            }
            st.push(curr);
        }
        return result;
    }
};