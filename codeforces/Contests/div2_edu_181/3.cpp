// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define PI 3.14159265358979323846
#define pb push_back
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
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
ll L, R;

int lcm(int a, int b){
    return a*b/__gcd(a, b);
}

ll countMultiples(ll k){
    // Count how many are NOT divisible by k between L and R
    ll count = (R/k-(L-1)/k);
    return count;
}

void solve(){
    cin >> L >> R;
    int prime[4] = {2, 3, 5, 7};
    vector<vector<int>> subsets;
    for(int mask = 1; mask < (1 << 4); mask++){
        vector<int> subset;
        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                subset.push_back(prime[i]);
            }
        }
        subsets.push_back(subset);
    }
    vector<pair<int,ll>> ans;
    for(int i=0; i<subsets.size(); i++){
        int k = 1;
        for(int j=0; j<subsets[i].size(); j++){
            k = lcm(k, subsets[i][j]);
        }
        ans.push_back({subsets[i].size(), countMultiples(k)});
    }

    ll final = R-L+1;
    for(int i=0; i<ans.size(); i++){
        if(ans[i].first == 1 || ans[i].first == 3){
            final -= ans[i].second;
        }
        else if(ans[i].first == 2 || ans[i].first == 4){
            final += ans[i].second;
        }
    }

    cout << final << endl;
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