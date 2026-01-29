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
    // boxes cant be rearranged 
    ll ans = -1;
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0) {
            ll mx = -1e18, mn = 1e18;
            for (int i = 0; i < n; i += d) {
                ll sm = 0;
                for (int j = i; j < i + d; ++j) {
                    sm += a[j];
                }
                mx = max(mx, sm);
                mn = min(mn, sm);
            }
            ans = max(ans, mx - mn);
        }
    }
    cout << ans << endl;
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