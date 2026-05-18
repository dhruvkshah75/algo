// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    string str;
    cin >> str;
    int cnt0 = 0, cnt1 = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '0') cnt0++;
        else cnt1++;
    }
    if(cnt0 == cnt1){
        cout << 0 << endl;
        return;
    }


    vector<int> ans;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '1'){
            if(cnt0 > 0){
                ans.pb(0);
                cnt0--;
            }
            else break;
        }
        else if(str[i] == '0'){
            if(cnt1 > 0){
                ans.pb(1);
                cnt1--;
            }
            else break;
        }
    }
    cout << str.size() - ans.size() << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}