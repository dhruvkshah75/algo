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

ll lcm(ll x, ll y){
    return (x*y)/__gcd(x, y);
}

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    ll ans = 0;
    ll fact_x = n/x;
    ll fact_y = n/y;
    ll fact_lcm = n/lcm(x, y);
    fact_x -= fact_lcm;
    fact_y -= fact_lcm;
    ans += ((n*(n+1))/2 - ((n-fact_x)*(n-fact_x+1))/2);
    ans -= (fact_y*(fact_y+1))/2;

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