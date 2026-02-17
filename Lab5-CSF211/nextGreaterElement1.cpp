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
};
