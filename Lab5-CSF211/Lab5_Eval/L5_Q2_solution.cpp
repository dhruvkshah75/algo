#include <bits/stdc++.h>
using namespace std;

std::vector<int> solve(int n, std::vector<int> &position, std::vector<int> &speed) {
    // we calculate the nse => next smaller speed of each car 
    stack<int> st;   // maintain a monotonic increasing stack 

    vector<int> nse(n, -1);   // index of nse

    for(int i=n-1; i>=0; i--) {
        int curr = speed[i];
        while(!st.empty() && curr <= speed[st.top()]) {
            st.pop();
        }
        if(!st.empty()) {
            nse[i] = st.top();
        }

        st.push(i);
    }

    // return nse;

    // now since we have the nse we calculate which car catches up to who 
    // we traverse through the position array and check 
    for(int i=n-2; i>=0; i--) {
        // if they catch up if with the last then there is no problem 
        if(nse[i] == n-1) continue;
        int nse_idx = nse[i];
        // the ith one has nse as nse_idx 
        // so we check if i cacthes to its nse first or the nse of ith catches first to its nse 
        int pos_diff = position[nse_idx] - position[i];
        int speed1 = speed[i];
        long long time1 = speed1 * 1LL * pos_diff;
        // now get the the index for which the nse catches up to 
        int pos_nse_diff = position[nse[nse_idx]] - position[nse_idx];
        int speed2 = speed[nse_idx];
        long long time2 = speed2 * 1LL * pos_nse_diff;

        if(time2 < time1 && nse[nse_idx] != -1) {
            speed[i] = speed[nse_idx];
            nse[i] = nse[nse_idx];
        }
    }

    return nse;
}