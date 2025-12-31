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

ll deal_cost(int x, const vector<ll>& pow3){
    ll cost = 1LL*pow3[x+1];
    if (x >= 1) cost += x * 1LL*pow3[x-1];
    return cost;
}

void solve() {
    int n; cin >> n;

    vector<ll> pow3(21, 1);
    for (int i = 1; i <= 20; i++) pow3[i] = pow3[i-1] * 3;

    ll total_cost = 0;
    for (int i = 19; i >= 0; i--) {
        while (n >= pow3[i]) {
            n -= pow3[i];
            total_cost += deal_cost(i, pow3);
        }
    }

    cout << total_cost << endl;
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