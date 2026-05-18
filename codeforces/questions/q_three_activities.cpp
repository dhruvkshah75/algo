// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(x) cerr << #x << " = " << x << endl;

const int M = 1e9+7;
// Lower Bound - Greater than or Equal to
// Upper Bound - Greater than 

// Solution begins here: 

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n), b(n), c(n);   // using pair to store the the original index 
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i=0; i<n; i++){
        cin >> b[i].first;
        b[i].second = i;
    }
    for(int i=0; i<n; i++){
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(all(a));
    sort(all(b));
    sort(all(c));

    int ans = 0;
    // Iterate through all 3*3*3 = 27 combinations of the last 3 elements in each array 
    for(int i = n - 1; i >= n - 3; i--){
        for(int j = n - 1; j >= n - 3; j--){
            for(int k = n - 1; k >= n - 3; k--){
                if(a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second){ // Check if the original indices are all different
                    int cur_sum = a[i].first + b[j].first + c[k].first;
                    ans = max(ans, cur_sum);
                }
            }
        }
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

    int tt;
    cin >> tt;
    while (tt--)
        solve();
}