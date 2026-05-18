#include<bits/stdc++.h>
using namespace std;

// a stack to be made to get the minimum element in the stack at any time 
// we use monotmic decreasing stack minE

// question link: https://leetcode.com/problems/min-stack/description/

class MinStack {
    stack<int> st, minE;  
    // minE this stack is a monotnic decreasing stack to maintain minimum elements 
public:
    MinStack() {
        st = stack<int>();  // initiliased the stack
        minE = stack<int>();
    }
    
    void push(int val) {
        st.push(val);
        if(minE.empty() || val <= minE.top()) {
            minE.push(val);
        }
    }
    
    void pop() {
        if(minE.top() == st.top()) {
            minE.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minE.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */