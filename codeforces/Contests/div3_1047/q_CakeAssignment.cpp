// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
// template<typename T>
// typedef tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 
vector<ll> pow2(62);

void solve(){
    int k;
    ll x;
    cin >> k >> x;

    ll cur_c = x;
    ll cur_v = pow2[k+1] - x;
    vector<int> ans;
    
    if(cur_c == cur_v){
        cout << 0 << endl;
        cout << endl;
        return;
    }

    while(true){
        if(cur_c < cur_v){
            cur_c *= 2;
            cur_v -= cur_c/2;
            ans.pb(1);
            if(cur_c == pow2[k] && cur_v == pow2[k]) break;
        }
        else if(cur_c > cur_v){
            cur_v *=2;
            cur_c -= cur_v/2;
            ans.pb(2);
            if(cur_c == pow2[k] && cur_v == pow2[k]) break;
        }
    }

    reverse(all(ans));
    cout << ans.size() << endl;
    for(auto &x: ans){
        cout << x << " ";
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

    pow2[0] = 1;
    for(int i=1; i<62; i++){
        pow2[i] = pow2[i-1]*2;
    }

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}