#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/contest/2202/problem/C1

void solve(int n, vector<int> &arr) {
    // simple logic try poping from the stack if allowed 

    stack<int> st;  

    // in reverse direction pop the top if current + 1 = top => continue this and then push the current

    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && arr[i] + 1 == arr[st.top()]) {
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
        vector<int> arr(n);

        for(int i = 0; i < n; i++) 
            cin >> arr[i];

        solve(n, arr);
    }
}