// Author: dks75 | https://codeforces.com/profile/dks75
// ----------------------------------------------------
#include <bits/stdc++.h>
#include<algorithm>
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

void solve(int tt){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(arr[i] >= k-1){
            mp.erase(arr[i]);
        }
        if(mp.count(arr[i])){
            if(mp[arr[i]] > 1) mp[arr[i]] = 1;
        }
    }

    int ans = 0;
    for(auto &[val, cnt]: mp){
        ans = max(ans, val);
    }

    cout << ans + 1 << endl;

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
        solve(tt);
}