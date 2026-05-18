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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<ll> res;
    res.reserve(n); 
    for(int i = 0; i < n; ++i) {
        ll prev_a = (i == 0) ? 0 : a[i - 1];
        ll diff = a[i] - prev_a;
        if(i - diff >= 0){
            res.pb(res[i - diff]);
        } 
        else{
            res.pb(i + 1);
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
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