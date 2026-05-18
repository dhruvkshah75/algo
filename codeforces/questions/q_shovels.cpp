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

bool checkPrime(int n) {
    for (int i=2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void solve(){
    int n, k;
    cin >> n >> k;
    if (k >= n){
        cout << 1 << endl;
        return;
    }

    if (n % k == 0) {
        cout << n/k << endl;
    } 
    else{
        if(checkPrime(n)){
            cout << n << endl;
        }
        else {
            int ans = n;
            for(int i=2; i*i<=n; i++){
                if(n % i == 0){
                    if(i <= k) ans = min(ans, n/i);
                    if(n/i <= k) ans = min(ans, i);
                }
            }
            cout << ans << endl;
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



