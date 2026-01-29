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

int upperbound(vector<ll> &pf, int x, int day) {
    int l = 1, r = pf.size() - 1; // pf[n] is valid
    int ans = -1;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (pf[mid]+day*1LL*mid > x) {
            ans = mid;
            r = mid-1;
        } 
        else l = mid+1; 
    }
    return ans; 
}


void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    f1(i, n){
        cin >> a[i];
    }
    sort(a.begin()+1, a.end());
    vector<ll> pf(n+1);
    f1(i, n){
        pf[i] = pf[i-1] + a[i]*1LL;
    }
    int d = x - a[1];
    if(d < 0){
        cout << 0 << endl;
        return;
    }
    ll total_packs = 0;
    for(int i=0; i<=d; i++){
        int value = upperbound(pf, x, i);
        if(value == -1) total_packs += n;
        else total_packs += value-1;
    }
    cout << total_packs << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}