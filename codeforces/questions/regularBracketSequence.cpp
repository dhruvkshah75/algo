#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;


void solve() {
    string str;
    cin >> str;

    stack<char> st;

    int maxLen = 0, len = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') 
            st.push(str[i]);
        else if(!st.empty()) {
            len += 2;
            st.pop();

            maxLen = max(len, maxLen);
        }
    }

    cout << maxLen << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}