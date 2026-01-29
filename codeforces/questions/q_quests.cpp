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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<ll> pf(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    pf[0] = a[0]*1LL;
    for(int i=1; i<n; i++){
        pf[i] = pf[i-1] + a[i]*1LL;
    }

    ll ans = 0;
    set<int> to_find;
    for(int i=0; i<n; i++){
        ll temp = pf[i];
        to_find.insert(b[i]);
        auto it = to_find.end();
        it--;
        int to_add = *it;
        temp += (k - i - 1)*1LL*(to_add);
        if(temp >= pf[i]) ans = max(ans, temp);
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