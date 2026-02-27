#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& temp) {
    int n = temp.size();
    // simply find next greate element using monotonic decreasing stack 
    vector<int> nge(n, 0); 
    stack<int> st;       // monotonic decreasing stack 

    for(int i=n-1; i>=0; i--) {
        int curr = temp[i];
        // pop elements untill curr >= temp[]
        while(!st.empty() && curr >= temp[st.top()]) {
            st.pop();
        }

        if(!st.empty()) {
            int idx = st.top();
            nge[i] = idx;
        }
        st.push(i);
    }

    for(int i=0; i<n; i++) {
        if(nge[i] == 0) 
            continue;
        nge[i] = nge[i] - i;
    }

    return nge;
}