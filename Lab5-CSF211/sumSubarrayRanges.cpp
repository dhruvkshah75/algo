#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sum-of-subarray-ranges/description/
// VERY IMPORTANT Stack Questions 

/*
    We calculate the no of times a[i] will be the max and min to a subarray 
    By calculating the pse and nse of a[i] we get the times a[i] acts as the min => solved in subarray minimums
    and similarly we find the a[i] acts max by calculating nse and nge 
    1 3 6 8 2 5 4 1 3 
    1 <= pse of 2 and nse of 2 => 1
    so no of subarrays we can form till pse and till nse that contains a[i] ? 
*/

// similar to sum of minimum of subarray 
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // we simply calculate how many times can any element a[i] become min and max 
        // then max - min will be the final ans 
        int n = nums.size();
        // min will range from pse and nse => use monotonic increasing stack 
        long long possible_min = 0;
        stack<int> st;       

        for(int i=0; i<=n; i++) {
            // at the dummy at the end as INT_MIN 
            int curr = (i == n) ? INT_MIN : nums[i];
            // monotonically increasing stack 
            while(!st.empty() && curr <= nums[st.top()]) {
                // this is the current element for which do the calculation 
                int top_index = st.top(); 
                st.pop();
                // curr i.e. nums[i] => this is the nse of nums[top_index]
                int right = i - top_index; 
                int left = top_index + 1;
                if(!st.empty()) {
                    int prevIdx = st.top();
                    left = top_index - prevIdx;
                } 
                // now the calculation of no of subarrays 
                possible_min += nums[top_index] * 1LL * left * right;
            }
            st.push(i);
        }
        
        // now we calculate the max on the basis of nge and pge 
        long long possible_max = 0;
        st = stack<int>();
        // monotonic decreasing stack 
        for(int i=0; i<=n; i++) {
            int curr = (i == n) ? INT_MAX : nums[i];
            while(!st.empty() && curr > nums[st.top()]) {
                // this is the element for which we get the nge and pge 
                int top_index = st.top();
                st.pop();
                // curr is the nge of the element 
                int right = i - top_index;
                int left = top_index + 1;
                if(!st.empty()) {
                    int prevIndex = st.top();
                    left = top_index - prevIndex;
                }
                // now we calculate
                possible_max += nums[top_index] * 1LL * left * right;
            }
            st.push(i);
        }

        return (possible_max - possible_min);
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++) 
        cin >> nums[i];

    Solution s = Solution();

    long long ans = s.subArrayRanges(nums);
    cout << ans << endl;
}