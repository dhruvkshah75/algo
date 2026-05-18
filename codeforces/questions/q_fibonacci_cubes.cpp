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
vector<int> fibb(12);

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(all(v), greater<int>());
        if(v[0] >= fibb[n+1] && v[1] >= fibb[n] && v[2] >= fibb[n]) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fibb[1] = 1;
    fibb[2] = 2;
    for(int i=3; i<=11; i++){
        fibb[i] = fibb[i-1] + fibb[i-2];
    }

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}