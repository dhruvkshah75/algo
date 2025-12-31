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
    ll p1, p2, q1, q2;
    cin >> p1 >> p2 >> q1 >> q2;
    vector<int> a(n);
    fc(i, n, a);
    ll sum = 0;
    ll maxi = 0;
    f(i, n){
        sum += a[i]*1LL;
        maxi = max(maxi, a[i]*1LL);
    }
    ll l = max(0LL, 2*maxi-sum);
    ll d1 = p1-q1;
    ll d2 = p2-q2;
    ll dist_sq = d1*d1 + d2*d2;
    if((dist_sq <= sum*sum) && (dist_sq >= l*l)){
        yes;
        return;
    }
    no;
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