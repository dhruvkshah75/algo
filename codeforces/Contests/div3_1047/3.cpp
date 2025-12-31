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
int countZeroes(ll b){
    int ans = 0;
    while(!(b & 1)){
        b >>= 1;
        ans++;
    }
    return ans;
}


void solve(){
    ll a, b;
    cin >> a >> b;
    if(b & 1){
        if(a & 1) cout << a*b + 1 << endl;   // b = k 
        else cout << -1 << endl;
        return;
    }
    else{
        int zeros = countZeroes(b);
        if((a&1) && zeros == 1){
            cout << - 1 << endl;
            return;
        }

        if(a&1){
            ll ans1 = a*2 + b/2;   // k = 2
            ll ans2 = a*(b/2) + 2;   // k = b/2 
            cout << max(ans1, ans2) << endl;
            return;
        }
        else{
            ll ans2 = a*(b/2) + 2;  
            // a+b -->> k = 1
            cout << max(a+b, ans2) << endl;
            return;
        }
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