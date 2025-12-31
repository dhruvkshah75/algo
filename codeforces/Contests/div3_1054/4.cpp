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

ll minMoves(vector<int>& pos){
    if (pos.empty()) return 0;
    int k = pos.size();
    vector<ll> target(k);
    for (int i = 0; i < k; i++) {
        target[i] = i;  
    }
    
    vector<ll> diff(k);
    for (int i = 0; i < k; i++){ 
        diff[i] = pos[i] - target[i];
    }
    nth_element(diff.begin(), diff.begin() + k/2, diff.end());
    ll median = diff[k/2];
    ll cost = 0;
    for (int i = 0; i < k; i++) {
        cost += llabs(diff[i] - median);
    }
    return cost;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> apos, bpos;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') apos.push_back(i);
        else bpos.push_back(i);
    }
    ll ans = min(minMoves(apos), minMoves(bpos));
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