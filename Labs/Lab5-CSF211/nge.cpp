#include<bits/stdc++.h>
using namespace std;

// Implementation code of NEXT GREATER ELEMENT 

// ====== Using Normal STACK ========
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



// implementation of next greater element using Monotonic decreasing stack 
// ========= Using MONOTONIC DECREASING STACK ========

/*
    In this backward traversal => makes more sense as i want to find the nge on the right for the element => nums[i] 
    that means we must have traversed all the elements in the backward direction 
    eg 
    4 12 5 3 1 2 5 |3| 1 2 4 6 
    assume we want to get the nge of the marked 3 then what do we do ?
    we traverse back from 6 then maintain a montonic stack 
*/

vector<int> ngeBackward(vector<int> &nums) {
    int n = nums.size();
    // we traverse in the backward direction 
    vector<int> result(n, -1);
    stack<int> st;
    for(int i=n-1; i>=0; i--) {
        int curr = nums[i];
        // if curr >= st.top element then we must remove these elements and store curr at the correct location 
        while(!st.empty() && curr >= nums[st.top()]) {  
            st.pop();
        }
        // now the st.top is the nge of the current element 
        if(!st.empty()) {
            result[i] = nums[st.top()];
        }
        st.push(i);
    }

    return result;
}

/*
    NOTE:
    In a Forward Scan, you look for the "Next Greater" by having elements wait in a stack until a "boss" 
    (the current element) arrives to resolve them.

    In Backward Scan, you look for the "Next Greater" by looking into the "Future" (the stack) 
    and picking the best candidate.
*/