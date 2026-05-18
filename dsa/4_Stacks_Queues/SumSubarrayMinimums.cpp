#include<bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/sum-of-subarray-minimums/description/
// VERY IMPORTANT Question

/*
    Algorithm: 
        what we do is for each element in the array we find out the contribution of each element in the array 
        i.e. in how many subarrays is arr[i] the min of that array 
        for this logic it is simply the permutations of all the subarrays of the part which extends from the 
        pse to the nse of arr[i] where we exclude pse and nse 
        eg 1 4 6 7 3 7 8 1 => for 3 the pse for 3 is 1 and nse is also 1 the indexes are 0 and 7 
        we can form (4 - 0) * (7 - 4) subarrays for 3 where 3 is the minimum 

        Simply do this while calculting the pse and nse at the same time using a monotonic increasing stack 
        (bottom is lower valued element) and traversing in the forward direction 
        also we end a dummy at the end so that if the stack is never popped it gets popped at the last 
        (when the array is sorted)

*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int mod = 1e9 + 7;

        stack<int> st;  // we monotonic increasing stack 
        // we find out arr[i] is a min to how many subarrays 
        for(int i=0; i<=n; i++) {
            int curr = (i == n) ? 0 : arr[i];
            // => standard for finding pse and nse at the same time 
            while(!st.empty() && curr <= arr[st.top()]) {
                int top_idx = st.top();
                // the top index is the element whose contribution we are trying to find out curr is the nse of the top index element 
                st.pop();
                int r = i - top_idx; // elements that can be taken on the right
                int l = top_idx + 1;     // if there is no pse then on the left we can take all the elements 
                if(!st.empty()) {
                    int prevIndex = st.top();
                    l = top_idx - prevIndex;
                }
                // the contribution of arr[top_idx] is till its pse and nse (exclusive)
                ans = (ans + (arr[top_idx] * 1LL * l * r) % mod) % mod; // => to prevent long long overflow 
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    Solution s = Solution();
    cout << s.sumSubarrayMins(arr) << endl;
}