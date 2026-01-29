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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int days = n/(a+b+c);
    if(days < 1){
        if(a >= n) cout << 1 << endl;
        else if(a+b >= n) cout << 2 << endl;
        else cout << 3 << endl;
    }
    else{
        if(n%(a+b+c) == 0){
            cout << 3*days << endl;
        }
        else{
            if(days*(a+b+c)+a >= n) cout << 3*days + 1 << endl;
            else if(days*(a+b+c)+a+b >= n) cout << 3*days + 2 << endl;
            else cout << 3*days + 3 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();
    
}