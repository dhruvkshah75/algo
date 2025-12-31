#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<char,int> symbols ={{'[', -1}, {'(', -2}, {'{', -3}, {']', 1}, {')', 2}, {'}', 3}};
// every opening bracket has a negative value and on closing the bracket the sum of those brackets is 0;

void solve(){
    string str;
    cin >> str;
    stack<char> st;
    for(int i=0; i<str.size(); i++){
        if(symbols[str[i]] < 0) st.push(str[i]);
        else{
            if(st.empty()){
                cout << "NO" << endl;
                return;
            }
            else{
                char top = st.top();
                st.pop();
                if(symbols[top] + symbols[str[i]] != 0){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    if(st.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}