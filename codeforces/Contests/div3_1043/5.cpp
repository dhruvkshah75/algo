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
    ll k;
    cin >> k;
    if(k <= 9){
        cout << k*(k+1)/2 << endl;
        return;
    }

    ll p10[16];
    p10[1] = 9;
    for (int i = 2; i <= 15; i++) {
        p10[i] = p10[i-1] * 10;
    }

    ll temp = 9;
    int i = 1;
    while(temp <= k){
        i++;
        temp += p10[i]*i;
    }

    int f = 1;
    ll ans = 0;
    while(f < i){
        ans += 45*(f-1)*1LL*9*pow(10, f-2) + 45*1LL*pow(10, f-1);
        f++;
    }

    ll digits_counted = 0;
    for(int j=1; j<i; j++){
        digits_counted += p10[j]*j;
    }

    ll left = k - digits_counted;
    cout << left << endl;
    if(left == 0){
        cout << ans << endl;
    }
    else{
        ll num_to_take = left/i;
        cout << ans << endl;
    }

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