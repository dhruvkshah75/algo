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
    int s;
    cin >> s;
    vector<int> pf(9);
    pf[0] = 9;
    int k = 8;
    for(int i=1; i<9; i++){
        pf[i] = pf[i-1] + k;
        k--;
    }
    int digits = 0;
    for(int i=0; i<9; i++){
        if(pf[i] >= s){
            digits = i+1;
            break;
        }
    }
    debug(digits);
    vector<int> ans;
    int x = 9;
    for(int i=0; i<digits-1; i++){
        ans.pb(x);
        x--;
    }
    int sum = 0;
    for(int i=0; i<ans.size(); i++){
        sum += ans[i];
    }
    ans.pb(s-sum);

    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i];
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

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}