// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define ff(i, n, a, freq) for(int i=0; i<n; i++){cin >> a[i]; freq[a[i]]++;}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    f(i, n){
        cin >> a[i];
    }
    int ct = 0;
    for(int i=0; i<n; i++){
        if(a[i]==a[0]) ct++;
    }
    if(ct==n){
        cout << 0 << endl;
        return;
    }
    int l=0, r=0;
    while(l<n && a[l]==a[0]) l++;
    while(r<n && a[n-1]==a[n-r-1]) r++;
    int res = n;
    if(a[0] == a[n-1]){
        res -= l;
        res -= r;
    }
    else{ 
        res -= max(l, r);
    }
    cout << max(0, res) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 */

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}