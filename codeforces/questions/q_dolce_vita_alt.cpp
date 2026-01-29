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

bool isTrue(ll pf, int i, int x, int mid){
    if(pf + (1LL*(i+1)*(mid-1)) <= x) return true;
    else return false;
}

int binSearch(ll pf, int i, int x){
    int l = 1, r = 1e9+5, mid;
    int ans = 0;
    while(l<=r){
        mid = (l+r)/2;
        if(isTrue(pf, i, x, mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    fc(i, n, a);
    sort(all(a));
    vector<ll> pf(n);
    pf[0] = a[0];
    for(int i=1; i<n; i++){
        pf[i] = pf[i-1] + a[i]*1LL;
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += 1LL*binSearch(pf[i], i, x);   // for each value of i calculate the no of days u can buy them
    }
    cout << ans << endl;
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