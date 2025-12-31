// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
// template<typename T>
// ypedef tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

bool isPossible(ll c, ll m, ll x, ll k) {
    return c >= k && m >= k && (c+m+x) >= 3*k;
}
 
void solve(){
    ll c, m, x;
    cin >> c >> m >> x;
    ll n = (c+m+x)/3;
    ll l = 0, r = n+1, mid;
    // TTTTTTFFFF -->> find the last occurrence of T;
    while(r-l > 1){
        mid = (l+r)/2;
        if(isPossible(c, m, x, mid)) l = mid;
        else r = mid - 1;
    }
    if(isPossible(c, m, x, r)) cout << r << endl;
    else cout << l << endl;

} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int q;
    cin >> q;
    while (q--)
        solve();
}