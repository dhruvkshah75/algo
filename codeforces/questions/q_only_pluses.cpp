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
    vector<int> a(3);
    f(i, 3){
        cin >> a[i];
    }
    sort(all(a));
    for(int i=0; i<5; i++){
        a[0]++;
        sort(all(a));
    }
    cout << a[0]*a[1]*a[2] << endl;
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