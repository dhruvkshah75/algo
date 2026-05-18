#include<bits/stdc++.h>
using namespace std;

// question link: https://cses.fi/alon/task/1645

// This is a simple implementation of previous smaller element (PSE)
// solution using monotonic stack 

// USING MONOTONIC INCREASING STACK 
// VERY IMPORTANT IMPLEMENTATION 

vector<int> prevSmallerElement(vector<int>&nums) {
    int n = nums.size();
    // using a monotonic increasing (bottom to top) stack 
    stack<int> st; 
    vector<int> pse(n, 0);

    for(int i=0; i<n; i++) {
        int curr = nums[i];
        // pop the elements in the stack untill curr <= st.top
        while(!st.empty() && curr <= nums[st.top()]) {
            st.pop();
        }

        if(!st.empty()) {
            int prevIndex = st.top();
            pse[i] = prevIndex + 1;
        }
        st.push(i);
    }

    return pse;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];

    vector<int> pse = prevSmallerElement(nums);
    
    // Printing the answer array 
    for(int idx: pse) {
        cout << idx << " ";
    }
    cout << endl;
}