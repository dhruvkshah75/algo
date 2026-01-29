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
    string str;
    cin >> str;
    // we have to count the no of distinct characters till the ith index 
    // the catch in the question was to count the no of distinct elements till each index and then sum all of them 
    map<char,int> mp;
    int cnt = 0; 
    vector<ll> distinct(n, 0); // stores the no of distinct elements till the ith index
    for(int i=0; i<n; i++){
        mp[str[i]]++;
        if(mp[str[i]] == 1){
            cnt++;
        }
        distinct[i] = cnt*1LL;
    }
    ll ans = accumulate(all(distinct), 0LL);
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