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
    int n;
    cin >> n;
    vector<int> x(n+1);
    fx(i, n+1, 2){
        cin >> x[i];
    }
    vector<int> ans(n+1);
    ans[1] = x[2] + 1;
    for(int i=2; i<n; i++){
        // ans[i] = ans[i-1]*n+x[i];
        // ans[i] > x[i+1]
        // x[i+1] + 1 = ans[i-1]*n + x[i]
        // (x[i+1] - x[i] + 1)/ans[i-1] = n;
        if(x[i] < x[i+1]){
            int n = (x[i+1] - x[i] + 1)/ans[i-1];
            ans[i] = ans[i-1]*(n+1)+ x[i];
        }
        else{
            ans[i] = ans[i-1] + x[i];
        }
    }
    ans[n] = ans[n-1] + x[n];

    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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