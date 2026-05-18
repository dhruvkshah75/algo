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
    int n;
    ll q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<ll> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }
    bool all_A = true;
    for(char &c : s){
        if(c == 'B'){
            all_A = false;
            break;
        }
    }

    for (int i = 0; i < q; ++i) {
        ll a = queries[i];
        if (all_A) {
            cout << a << endl;
            continue;
        }
        ll ans = 0;
        ll current_a = a;
        int idx = 0; 
        while (current_a > 0) {
            if (s[idx] == 'A') current_a--;
            else current_a /= 2;
            ans++;
            if (current_a == 0) break;
            idx = (idx + 1) % n;
        }
        cout << ans << endl;
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