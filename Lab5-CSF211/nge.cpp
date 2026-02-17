#include<bits/stdc++.h>
using namespace std;

// Implementation code of NEXT GREATER ELEMENT 

vector<int> nextGreaterElement(vector<int>&nums) {
    // find the next greater element 
    int n = nums.size();
    vector<int> nge(n, -1);         
    stack<int> st;         // we push only the indexes in the stack

    for(int i=0; i<n; i++) {
        // the current element is greater than the elements of the top of stack that means it is the the nge 
        while(!st.empty() && nums[i] > nums[st.top()]) {
            int prevIndex = st.top();
            nge[prevIndex] = nums[prevIndex];
            st.pop();
        }
        // now put the current element's index in the "waiting room => stack"
        st.push(i);
    }

    return nge;
}