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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }

    ll ans = 0;
    int cur_side = 0;
    int cur_time = 0;
    for(int i=0; i<n; i++){
        int time_diff = a[i].first - cur_time;
        if(a[i].second == cur_side){
            if(time_diff & 1) ans += (time_diff - 1)*1LL;
            else ans += time_diff*1LL;
        }
        else{
            if(time_diff & 1) ans += time_diff*1LL;
            else ans += (time_diff - 1)*1LL;
        }

        cur_time = a[i].first;
        cur_side = a[i].second;
    }
    
    if(a[n-1].first != m){
        cerr << "cur_time: " << cur_time << endl;
        int time_diff = m - cur_time;
        ans += time_diff;
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