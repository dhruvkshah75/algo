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

void solve(){
    int n;
    ll k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    sort(all(a));

    vector<ll> v;
    for(int i=0; i+1<n; i++){
        ll diff = a[i+1] - a[i];
        if(diff > x){
            ll val = (diff+x-1)/x - 1;
            v.pb(val);
        }
    }

    sort(all(v));  
    // no of independent groups = v.size() + 1;
    int ans = v.size() + 1;
    ll sum = 0;
    for(int i=0; i<v.size(); i++){
        if(sum + v[i] <= k){
            sum += v[i];
            ans--;
        } 
        else break;
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

    // int tt;
    // cin >> tt;
    // while (tt--)
        solve();
}