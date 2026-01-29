#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string str = " "+s;
    int ct0 = 0; int ct1 = 0;
    for(int i=1; i<=n; i++){
        if(str[i] == '0') ct0++;
        if(str[i] == '1') ct1++;
    }

    if(ct1 == n){
        no;
        return;
    }
    yes;
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