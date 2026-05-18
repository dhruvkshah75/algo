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

pair<int, int> mergeIntervals(pair<int, int> a, pair<int, int> b) {
    // first interval starts before the second
    if(a.first > b.first) swap(a, b);
    if(a.second >= b.first){  // check for overlap
        int start = min(a.first, b.first);
        int end = max(a.second, b.second);
        return {start, end};
    }
    else{
        // No overlap
        return {-1, -1}; 
    }
}

void solve(){
    int n, x, m;
    cin >> n >> x >> m;
    vector<pair<int,int>> a(m);
    for(int i=0; i<m; i++){
        cin >> a[i].first >> a[i].second;
    }

    int idx = -1;
    for(int i=0; i<m; i++){
        if(x <= a[i].second && x >= a[i].first){  // find the first interval in which x belongs
            idx = i;
            break;
        }
    }
    if(idx == -1) {
        cout << 1 << endl;
        return;
    }
    // now just increasing the size of final interval
    pair<int,int> ans = a[idx];
    for(int i=idx+1; i<m; i++){
        pair<int,int> check = mergeIntervals(ans, a[i]);
        if(check.first != -1 && check.second != -1) {
            ans = check;
        }
    }
    cout << ans.second - ans.first + 1 << endl;
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