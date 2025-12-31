// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

template<typename T>
using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fc(i, n, a) for(int i=0; i<n; i++){cin >> a[i];}
#define fb(i, n) for(int i=n-1; i>=0; i--)
#define fx(i, n, a) for(int i=a; i<n; i++)
#define debug(x) cerr << #x << " = " << x << endl;
// #define debug_code

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here:


void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    fx(i, n+1, 1){
        cin >> p[i];
    }

    vector<int> rs(n+1), lg(n+1);
    OrderedSet<int> os;
    for(int i=n; i>=1; i--){
        rs[i] = os.order_of_key(p[i]);  // ele < p[i]
        os.insert(p[i]);
    }
    os.clear();

    fx(i, n+1, 1){
        lg[i] = i-1-os.order_of_key(p[i]); // ele > p[i]
        os.insert(p[i]);
    }

    ll tot_inv = 0;
    fx(i, n+1, 1){
        tot_inv += rs[i];
    }

    ll canc_inv = 0;
    fx(i, n+1, 1){
        ll delta = (n-i)-rs[i]-lg[i];
        if(delta < 0) canc_inv -= delta;
    }
    cout << tot_inv - canc_inv << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef debug_code
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}