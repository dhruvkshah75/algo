// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), pmin(n), pf(n);
    fc(i, n, a);
    pmin[0] = a[0]; pf[0] = pmin[0];
    for(int i=1; i<n; i++){
        pmin[i] = min(pmin[i-1], a[i]);
        pf[i] = pf[i-1] + pmin[i];
    }
    ll ans = pf[n-1];
    ll maxi = 4e18;
    for(int i=0; i<n-1; i++){
        ll prev_min, sum;
        if(i == 0){
            prev_min = maxi;
            sum = 0LL;
        }
        else{
            prev_min = pmin[i-1];
            sum = pf[i-1];
        }
        ll s = a[i]+a[i+1];
        ll is = min(prev_min, s);
        ans = min(ans, sum+is);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}