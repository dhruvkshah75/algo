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
    int l = (n*(n-1))/2;
    vector<int> b(l);

    for(int i=0; i<l; i++){
        cin >> b[i];
    }

    sort(all(b));
    int ctr = n;
    vector<int> ans;
    int curr_pos = 0;
    
    for(int i = n-1; i > 0; i--) {
        ans.pb(b[curr_pos]);
        curr_pos += i;
    }

    ans.pb(b[l - 1]);
    
    for(int &x: ans){
        cout << x << " ";
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