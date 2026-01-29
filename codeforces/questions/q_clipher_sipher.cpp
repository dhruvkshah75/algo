#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.141592653589793238462643383279

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<char> ans;
    for(int i=0; i<n;){
        char l = str[i];
        ans.push_back(l);
        for(int j=i+1; j<n; j++){
            if(str[j] == l){
                i = j+1;
                break;
            }
        }
    }
    for(auto &c: ans){
        cout << c;
    }
    cout << endl;
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