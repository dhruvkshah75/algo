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
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[1] << endl;
        return;
    }
    vector<ll> pmin(n+1);
    pmin[1] = a[1];
    for(int i=2; i<=n; i++){
        pmin[i] = min(pmin[i-1], a[i]);
    }
    ll sum_pmin = 0;
    for(int i=1; i<=n; i++){
        sum_pmin += pmin[i];
    }
    vector<ll> suffix(n+2);
    suffix[n+1]=0;
    for(int i=n; i>=1; i++){
        suffix[i] = pmin[i]+suffix[i+1];
    }
    int index = n+1;
    for(int i=2; i<=n; i++){
        if(pmin[i] == pmin[i-1]){
            index = i;
            break;
        }
    }
    vector<ll> cost(n+1);
    for(int i=2; i<=n; i++){
        cost[i] = pmin[i-1] - pmin[i];
    }
    ll val = 0, maxi = LLONG_MAX;
    for(int i=2; i<=n; i++){
        ll x;
        if(i <= index){
            if(i==2) x = suffix[i]-a[i];
            else{
                maxi = min(maxi, cost[i-1]);
                x = suffix[i] - min(a[i], maxi);
            }
        }
        else{
            x = suffix[i];
        }
        val = max(val, x);
    }
    cout << sum_pmin - val << endl;
    
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