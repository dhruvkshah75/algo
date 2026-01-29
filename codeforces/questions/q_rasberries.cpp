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
    int cnt = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) cnt++;
    }
    if(k == 2 || k == 3 || k == 5){
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int val = k - a[i] % k;
            if(val == k) val = 0;
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
    else{
        if(n == 1){
            cout << a[0] - a[0] % k << endl;
        }
        else{
            cout << max(0, 2-cnt) << endl;
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