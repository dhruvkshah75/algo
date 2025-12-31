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
const int N = 2*1e5+10;
int cnt[N];
int hsh[N];

void solve(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        hsh[x]++;
    }

    for(int i=1; i<N; i++){
        if(hsh[i]){
            for(int j=i; j<N; j+=i){
                if(hsh[j]) cnt[i] += hsh[j];
            }
        }
    }
    // O(NLog(N));

    int qe;
    cin >> qe;
    while(qe--){
        int p, q;
        cin >> p >> q;
        ll lcm = (p*1LL*q)/__gcd(p, q);
        ll ans = 0;
        ans += cnt[p]*1LL + cnt[q]*1LL;
        if(lcm < N) ans -= cnt[lcm]*1LL;
        cout << ans << endl;
    }
}

int main(){
    solve();
}