#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: 

void solve(string &str) {
    int n = str.length();

    // if we find ++ or -- then we cancel them out as they can be straightened out 
    // eg => +--+  so -- gets cancelled then stack contains + then gets cancelled with + 
    stack<char> st;

    for(int i=0; i<n; i++) {
        // if the stack is empty nothing to compare to so push 
        if(st.empty()) 
            st.push(str[i]);
        else {
            char c = st.top();
            if(c == str[i]) 
                st.pop();
            else 
                st.push(str[i]);
        }
    }

    if(st.empty()) {
        yes;
    }
    else {
        no;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    solve(str);
}