// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}
const int mod = 998244353;

ll lcm(ll a, ll b){
    return (a*b)/__gcd(a,b);
}

ll binExpo(ll a, ll b){  // iterative binary expo (calculate (a^b)%M )
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return ans;
}


// Solution begins here: 

void solve(){
    int n, m;
    cin >> n >> m;

    
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