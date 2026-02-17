#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/next-greater-element-i/description/
// Important Question => Next Greater Element 

/*
    We apply the next greater element algorithm 
    We keep elements in the stack and as soon as some element x bigger than the st.top() appears
    Then the nge of st.top is x 
    and the elements left in the stack have no next greater element 
*/

class Solution {
public:

    // ====== Using Normal STACK ========
    vector<int> ngeForward(vector<int>& nums1, vector<int>& nums2) {
        // nums1 is the only used for storing the ans at that index 
        
        unordered_map<int,int> mp;  // stores the index of each element of nums1 
        for(int i=0; i<nums1.size(); i++) {
            mp[nums1[i]] = i;
        }

        vector<int> ans(nums1.size(), -1);

        int n = nums2.size();
        stack<int> st;  
        for(int i=0; i<n; i++) {
            // While the nums2[i] > nums2[st.stop()]
            while(!st.empty() && nums2[i] > st.top()) {
                int prevElement = st.top();
                if(mp.count(prevElement))
                    ans[mp[prevElement]] = nums2[i];   // update the nge of that element if it exists in nums1
                st.pop();
            }
            // put the current element in the "waiting room"
            st.push(nums2[i]);
        }

        return ans;
    }


    // implementation of nect greater element using Monotonic decreasing stack 
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

};
