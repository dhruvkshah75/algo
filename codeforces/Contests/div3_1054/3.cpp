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
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    int missing = 0;
    for(int i=0; i<k; i++){
        if(!mp.count(i)) missing++;
    }

    int freqk = 0;
    if(mp.count(k)) freqk = mp[k];
    else freqk = 0;

    cout << max(missing, freqk) << endl;
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