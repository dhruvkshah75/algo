//******************************************** BALANCED PARENTHESIS **************************************//
/*
    given string ((())) string is balanced or not --> this one is a balnced 
    ((()))(() --> this one is not balanced parenthesis

    fill the opening parenthesis in the stack and then while there is a closed parenthesis in the input anc check for open parenthesis
    in the stack
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str;
    cin >> str;
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '(') s.push(str[i]);
        else if(str[i] == ')'){
            if(s.empty()){
                cout << "NO" << endl;
                return;
            }
            char check = s.top();
            s.pop();
            if(check != '('){
                cout << "NO" << endl;
                return;
            } 
        }
    }
    if(!s.empty()){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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