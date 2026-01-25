// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    // lets build a array with differences 
    // we choose the 
    vector<int> v;
    for(int i=0; i+1<n; i++) {
        v.push_back(a[i+1]-a[i]);
    }

    sort(v.begin(), v.end(), greater<int>());

    int ans = a[n-1] - a[0];
    for(int i=0; i<k-1; i++) ans -= v[i];

    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int tt;
    // cin >> tt;
    // while (tt--)
    solve();
}