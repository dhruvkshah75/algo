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
//#define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    int n, c, d;
    cin >> n >> c >> d;
    int arr[n+1][n+1];
    unordered_map<int, int> freq; 
    int mn = INT_MAX;
    for(int i=0; i<n*n; i++){
        int x; cin >> x;
        freq[x]++;
        mn = min(mn, x);
    }

    unordered_map<int,int> ans;
    arr[1][1] = mn;
    ans[mn]++;
    for(int i=1; i<=n; i++){
        if(i != n){
            arr[i+1][1] = arr[i][1] + c; 
            ans[arr[i+1][1]]++;
        } 
        for(int j=1; j<n; j++){
            arr[i][j+1] = arr[i][j] + d;
            ans[arr[i][j+1]]++;
        }
    }

    for(auto &x: freq){
        if(ans[x.first] != x.second){
            no; return;
        }
    }
    yes;
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