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


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> ad(n);
    for(int i=0; i<n; i++){
        cin >> ad[i];
    }
    sort(all(ad));
    int ads = 0;
    int l=0, r=n-1;
    while(l<=r){
        ll sum = 0;
        int ct=0;
        while(l<=r && sum+ad[l]<k && ct<2){
            sum += ad[l];
            l++;
            ct++;
        }
        sum += ad[r];
        ads++;
        r--;
    }
    cout << ads-1 << endl;
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
    while (tt--)
        solve();
}