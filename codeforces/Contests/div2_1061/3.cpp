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
    vector<int> a(n);
    vector<int> f(n+1, 0);  // stores the freq of each element
    for(int i=0; i<n; i++){
        cin >> a[i];
        f[a[i]]++;
    }

    vector<int> pf(n+1);
    pf[1] = f[1];
    for(int i=1; i<=n; i++){
        pf[i] = pf[i-1] + f[i];
    }

    int ans = 1e9;
    // here i indicates the temp gcd so 
    // "Bad" Numbers: These are numbers that cannot be converted and must be erased.
    for(int i=n; i>=1; i--){
        int uppBound = min(n, 4*i-1);
        int cnt = pf[uppBound];
        int cnt1 = 0;
        if(3*i <= n){
            cnt1 += f[i] + f[2*i] + f[3*i];
        }
        else if(2*i <= n){
            cnt1 += f[i] + f[2*i];
        }
        else if(i <= n){
            cnt1 += f[i];
        }

        if(cnt - cnt1 <= k){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
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