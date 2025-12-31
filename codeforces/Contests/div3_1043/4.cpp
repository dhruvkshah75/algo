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

ll sumBase3(ll n){
    ll s = 0;
    while (n > 0) {
        s += n % 3;
        n /= 3;
    }
    return s;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<ull> pow3(40, 1);
    for (int i = 1; i < 40; i++) pow3[i] = pow3[i-1]*3ull;

    ll s = sumBase3(n);
    ll mn = min(k, n);
    ll check;
    if(mn % 2 == n % 2) check = mn;
    else check = mn-1;

    if(check < s){
        cout << -1 << endl;
        return;
    }
    ll ctr = (n - check) / 2;
    vector<ull> cnt;
    cnt.pb((ull)n);
    ull ans = 0;
    int x = 0;
    while(ctr > 0){
        if (x >= (int)cnt.size()) cnt.push_back(0);
        ull avail = cnt[x] / 3ull;
        if (avail == 0){
            ++x; continue;
        }
        ull ctr1 = (ull)min<ll>(avail, ctr);
        ans += ctr1*pow3[x];
        cnt[x] -= ctr1*3ull;

        if (x + 1 >= (int)cnt.size()) cnt.push_back(0);
        cnt[x + 1] += ctr1;
        ctr -= (ll)ctr1;
    }
    cout << (3ull*(ull)n + ans) << endl;
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