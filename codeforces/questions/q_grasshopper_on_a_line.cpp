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
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
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
    int n, k;
    cin >> n >> k;
    if(n % k != 0 || n < k){
        cout << 1 << endl;
        cout << n << endl;
    }
    else{
        vector<int> multiples;;
        for(int i=k; i< 110; i += k){
            multiples.pb(i);
        }
        int idx = 0;
        bool flag = false;
        for(int i=0; i<multiples.size(); i++){
            if(multiples[i] >= n){
                idx = i; flag = true;
                break;
            }
        }
        if(flag && idx != 0){
            cout << 2 << endl;
            cout << multiples[idx-1] - 1 << " " << n - (multiples[idx-1] - 1) << endl;
        }
        else{
            cout << 2 << endl;
            cout << multiples[idx] - 1 << " " << n - (multiples[idx] - 1) << endl;
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