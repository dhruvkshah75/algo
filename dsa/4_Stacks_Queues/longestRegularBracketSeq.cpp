#include<bits/stdc++.h>
using namespace std;

// question link: https://codeforces.com/problemset/problem/5/C

// we solve the question to similar to the longest bracket sequence 
// we push ( in the stack and pop ( if ')' is encountered and if top doesnt contain '(' then push ')'  in the stack too
// similar to Longest Valid parenthesis 

void solve(string &str) {
    int n = str.length();

    unordered_map<int,int> cnt;   // used to store the count of valid sequences 

    stack<int> st;               // store indexes in the stack => of those indexes which cant form a pair 

    for(int i=0; i<n; i++) {
        if(str[i] == '(') 
            st.push(i);
        else {
            // str[i] = ')' 
            // we pop if we find a matching pair 
            if(!st.empty() && str[st.top()] == '(') 
                st.pop();  
            else                                    // pair doesnt match then push this in the stack 
                st.push(i);
        }
    }

    // elements between the the indexes of the stack are valid sequences 
    
    int max_len = 0;
    int a = n;
    while(!st.empty()) {
        int b = st.top();
        st.pop();

        int cur_len = a - b - 1;
        if(max_len <= cur_len) {
            max_len = cur_len;
            cnt[max_len]++;
        }
        a = b;
    }
    // the last case where a = x and b = 0;
    if(max_len <= a - 0) {
        max_len = a;
        cnt[max_len]++;
    }

    if(max_len == 0)
        cout << 0 << " " << 1 << endl;
    else 
        cout << max_len << " " << cnt[max_len] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    solve(str);

}