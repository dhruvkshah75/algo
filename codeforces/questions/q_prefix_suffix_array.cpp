#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void check_palindrome(string &str){
    int len = str.size();
    for(int i=0; i<len; i++){
        if(str[i] != str[len-i-1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

void solve(){
    int n;
    cin >> n;
    map<int,vector<string>> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        m[-str.size()].push_back(str);         // storing it as negative so i can traverse easily
    }
    auto it = m.begin();
    

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