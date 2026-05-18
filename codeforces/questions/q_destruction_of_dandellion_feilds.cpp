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
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    ll ans = 0;

    vector<int> a_odd, a_even;
    for(int i=0; i<n; i++){
        if(a[i]&1) a_odd.pb(a[i]);
        else a_even.pb(a[i]);
    }
    sort(all(a_odd), greater<int>()); // sort in a reverse order 

    if(a_odd.size()){
        for(int i=0; i<a_even.size(); i++){
            ans += a_even[i]*1LL;
        }
        int m = a_odd.size();
        for(int i=0; i < (m+1)/2; i++){
            ans += a_odd[i]*1LL;
        }
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }
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