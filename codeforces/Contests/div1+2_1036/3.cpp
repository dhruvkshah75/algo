// Author: dks75 | https://mirror.codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}

void solve(){
    int n;
    cin >> n;
    vector<ll> b(n);
    fc(i, n, b);
    ll ans = 1;
    for(int i=0; i<n-1; i++){
        if(b[i+1]%b[i]!=0){
            ll gcd = __gcd(b[i], b[i+1]);
            ll c = b[i]/gcd;
            ll gcd1 = __gcd(ans, c);
            ans = ans/gcd1 * c;
        }
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
