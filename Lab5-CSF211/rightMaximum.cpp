#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/contest/2204/problem/B

void solve(vector<int> &a) {
    int n = a.size();

    // nge using a monotonically decreasing stack 
    // => the elements left out in the stack at the end are ones for whom the operation must be carried out 
    stack<int> st;

    // the stack will contain all the elements which are the last nges => the maxs 
    for(int i = n - 1; i >= 0; i--) {
        int curr = a[i];
        while(!st.empty() && curr > a[st.top()]) {
            st.pop();
        }
        st.push(i);
    }

    cout << st.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n; 

        vector<int> a(n);

        for(int i = 0; i < n; i++) 
            cin >> a[i];

        solve(a);
    }
}