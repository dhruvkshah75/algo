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
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    f(i, n) cin >> a[i];
    f(i, n) cin >> b[i];

    int m = 0;
    int s = 0;
    f(i, n){
        if(i!= n-1){
            if(a[i] > b[i+1]){
                m += a[i];
                s += b[i+1];
            }
        }
        else{
            m += a[i];
        }
    }
    cout << m-s << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
    
}