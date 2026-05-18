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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> v;
    if (n > 0) {
        v.push_back(a[0]);
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] != v.back()) {
            v.push_back(a[i]);
        }
    }

    int m = v.size();
    if (m <= 2) {
        cout << m << endl;
        return;
    }

    int ans = 0;
    for (int i = 1; i < m - 1; ++i) {
        bool check1 = (v[i] > v[i-1] && v[i] > v[i+1]);
        bool check2 = (v[i] < v[i-1] && v[i] < v[i+1]);
        if (check1 || check2) {
            ans++;
        }
    }

    cout << 2 + ans << endl;
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