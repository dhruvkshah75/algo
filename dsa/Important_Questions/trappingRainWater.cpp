#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/trapping-rain-water/description/
// STACKS 

/*
    When is water trapped ?? => when a valley is formed i.e. right and left are bigger and middle elements are
    smaller 
    so for a particular element we calculate the previous Greater Element and next greater element 
    we do this by using monotonic decreasing stack and find the prev greater and next greater element 
    similar to maximum rectangle in a histogram
*/


int trap(vector<int>& height) {
    int n = height.size();
    // we find the valleys and then add water 
    // by finding prevGreater and next Greater 
    int water = 0;
    stack<int> st;   // monotonically decreasing stack 

    for(int i=0; i<n; i++) {
        int curr = height[i];
        while(!st.empty() && curr > height[st.top()]) {
            int top_index = st.top();
            st.pop();
            // we calculate the water trapped because of the valley formed by top element 
            // nge of st.top is curr and the pge of st.top is the next element in stack 
            if(st.empty()) 
                break;    // no wall on the left => so spills out on the left 
            
            int left_wall = st.top();
            int right_wall = i; 
            // this is the valley created by 
            // h is determined by right and left wall 
            int w = right_wall - left_wall - 1;
            int h =  min(height[right_wall], height[left_wall]) - height[top_index];

            water += w*h;
        }
        st.push(i);
    }

    return water;

}

