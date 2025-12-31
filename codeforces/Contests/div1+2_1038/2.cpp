// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

struct p{
    int a, b, c, d;
};

void solve(){
    int n;
    cin >> n;
    vector<p> v(n);
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
        if(v[i].b > v[i].d){
            ans += v[i].a + v[i].b - v[i].d;   // remove the upper zereos;
            continue;
        }
        if(v[i].a > v[i].c){
            ans += v[i].a - v[i].c;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug_code
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}