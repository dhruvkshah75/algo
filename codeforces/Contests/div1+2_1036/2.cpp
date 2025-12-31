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
    vector<int> a(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> pmin(n);
    pmin[0] = a[0];
    for(int i=1; i<n; i++){
        pmin[i] = min(pmin[i-1], a[i]);
    }
    if(n==1 || a[1] == 0){
        cout << a[0] << endl;
        return;
    }
    if(n >= 3){
        cout << 2*min(a[0], a[1]+a[2]) << endl;
        return;
    }
    else{
        cout << pmin[n-1]*n << endl;
        return;
    }
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