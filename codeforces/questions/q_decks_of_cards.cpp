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
    string s;
    cin >> n >> k >> s;
    int a = count(s.begin(), s.end(), '0');
    int b = count(s.begin(), s.end(), '1');
    int c = count(s.begin(), s.end(), '2');

    string ans(n, '+');
    for(int i = 0; i < n; ++i){
      if (i < a + c || i >= n - b - c) ans[i] = '?';
      if (i < a || i >= n - b || k == n) ans[i] = '-';
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