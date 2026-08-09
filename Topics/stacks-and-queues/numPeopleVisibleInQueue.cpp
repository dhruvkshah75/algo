// ===================================== monotonic stack =======================================

#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/description

/**
 * use monotonic decreasing stack + reverse traversal 
 * when current person is to be added to the stack => we remove all the smaller elements in the stack 
 * so we remove all smaller people than curr from the stack (these ones can be always seen by curr)
 * and if stack is not empty then the top of the stack will be the last person that blocks the 
 * view of the current person and so add to the count 
 * */

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &heights) {
        int n = heights.size();
        vector<int> res(n);

        stack<int> st;
        // monotonically decreasing stack to store all the mx elements on the right 

        for(int i = n-1; i >= 0; i--) {
            int curr = heights[i];
            
            int count = 0;
            // remove all the people who curr shadows over 
            while(!st.empty() && curr > heights[st.top()]) {
                st.pop();
                count++;  // we pop the ones with shorter height (so curr can see them)
            }   

            // if stack is not empty then curr can see the st.top() person 
            if(!st.empty()) count++;

            res[i] = count;
            st.push(i);
        }

        return res;
    }
};