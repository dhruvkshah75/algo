// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()

void solve(){
    int n; 
    ll x, y;
    cin >> n >> x >> y;
    vector<int> a(n+1);
    ll total = 0;
    f1(i, n){
        cin >> a[i];
        total += 1LL*(a[i]);
    }
    sort(a.begin()+1, a.end());
    int ct = 0;
    int l = 1, r = n;
    while(l<n){
        int temp_r = r;
        while(temp_r > l && total-a[l]-a[temp_r] > y){
            temp_r--;
        }
        ll sum = total - a[l] - a[temp_r];
        if(sum >=x && sum<=y) ct++;
        l++;
    }
    cout << ct << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
    
}