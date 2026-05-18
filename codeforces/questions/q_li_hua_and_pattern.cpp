// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }
    int ctr = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] != v[n-i-1][n-j-1]) ctr++;
        }
    }
    int cnt = (ctr+1)/2;
    if(cnt > k){
        no;
    }
    else{
        k -= cnt;
        if(k%2==0){
            yes;
        }
        else{
            if(n&1){
                yes;
            }
            else{
                no;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}