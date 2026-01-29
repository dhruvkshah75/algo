// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    fx(i, 2*n, 0){
        int x;
        cin >> x;
        if(x == 1) cnt1++;
        else cnt0++;
    }
    if(cnt1 == 2*n){
        cout << 0 << " " << 0 << endl;
    }
    else{
        if(cnt1 & 1){ // cnt1 is odd 
            cout << 1 << " " << ((cnt1 <= n) ? cnt1 : cnt0) << endl;
        }
        else{
            cout << 0 << " " << ((cnt1 <= n) ? cnt1 : cnt0) << endl;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug_code
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}