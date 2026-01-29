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
    unordered_map<int,int> ump;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        ump[x]++;
    }

    map<int,vector<int>> mp;

    for(auto &[val, cnt]: ump){
        mp[cnt].push_back(val);
    }


    ll ans = 0;
    unordered_set<int> seen;
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        int cnt = it->first;
        for(auto &val: it->second){
            while (cnt > 0 && seen.count(cnt)) cnt--; 
            if (cnt > 0){
                ans += cnt;
                seen.insert(cnt); 
                cnt--; 
            }
        }
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