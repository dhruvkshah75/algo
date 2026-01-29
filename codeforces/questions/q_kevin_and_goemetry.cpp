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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && a[j] == a[i]) j++;
        int cnt = j - i;
        if (cnt >= 4) {
            cout << a[i] << ' ' << a[i] << ' ' << a[i] << ' ' << a[i] << endl;
            return;
        }
        i = j;
    }

    vector<int> pairs;
    int i=0;
    while(i < n){
        int j = i + 1;
        while (j < n && a[j] == a[i]) ++j;
        if (j - i >= 2) pairs.push_back(a[i]);
        i = j;
    }

    if (pairs.size() >= 2) {
        cout << pairs[0] << ' ' << pairs[0] << ' ' << pairs[1] << ' ' << pairs[1] << endl;
        return;
    }

    if (pairs.empty()) {
        cout << -1 << endl;
        return;
    }

    int c = pairs[0];
    vector<int> v;
    int removed = 0;
    for(int x : a){
        if(x == c && removed < 2){ 
            removed++; 
            continue; 
        }
        v.pb(x);
    }

    for (int i = 0; i + 1 < (int)v.size(); ++i) {
        // check the base difference condition: |b1 - b2| < 2*c
        if ((long long)v[i+1] - v[i] < 2LL * c) {
            cout << c << ' ' << c << ' ' << v[i] << ' ' << v[i+1] << endl;
            return;
        }
    }
    cout << -1 << endl;
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