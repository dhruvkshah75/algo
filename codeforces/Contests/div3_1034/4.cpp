// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1000000007
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    fc(i, n, a);
    vector<int> pmin(n);
    vector<int> smax(n);
    pmin[0] = a[0];
    for (int i = 1; i < n; i++) {
        pmin[i] = min(pmin[i-1], a[i]);
    }
    smax[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        smax[i] = max(smax[i+1], a[i]);
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (pmin[i] == a[i] || smax[i] == a[i]) ans += '1';
        else ans += '0';
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
*/

    int tt;
    cin >> tt;
    while (tt--) solve();
}
