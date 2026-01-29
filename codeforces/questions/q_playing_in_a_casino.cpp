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
    vector<vector<int>> v(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }

    if(n == 1){
        cout << 0 << endl;
        return;
    }


    ll ans = 0;
    for(int i=0; i<m; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            temp.pb(v[j][i]);
        }
        sort(all(temp));
        vector<ll> pf(temp.size());
        pf[0] = temp[0]*1LL;
        for(int k = 1; k<temp.size(); k++){
            pf[k] = pf[k-1] + temp[k]*1LL;
        }

        for(int s=temp.size()-1; s>0; s--){
            ans += s*1LL*(pf[s]-pf[s-1]) - pf[s-1]*1LL;
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