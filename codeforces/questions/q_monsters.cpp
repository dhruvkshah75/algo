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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }

    for(int i=0; i<n; i++){
        if(a[i].first > k){
            if(a[i].first % k == 0){ // important step 
                a[i].first = k;
            }
            else{
                a[i].first = (a[i].first % k);
            }
        }
    }
    sort(all(a));

    map<int,int> mp;
    vector<int> ans;
    for(int i = 0; i<n; i++){
        mp[a[i].first]++;
    }

    for(int i=0; i<n; ){
        if(mp[a[i].first] == 1){
            ans.push_back(a[i].second);
            i++;
        } 
        else{
            int j = i + mp[a[i].first] - 1;
            int k = j;
            while(j >= i){
                ans.push_back(a[j].second);
                j--;
            }
            i = k+1;
        }
    }
    reverse(all(ans));

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