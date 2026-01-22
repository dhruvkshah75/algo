#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


void solve () {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    for (int i = 0; i < n; i++) 
        cin >> b[i];
        
    // bubble sort on array a
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                ans.push_back({1, j});
            }
        }
    }
    // bubble sort on array b
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (b[j - 1] > b[j]) {
                swap(b[j - 1], b[j]);
                ans.push_back({2, j});
            }
        }
    }
    // now we want ai < bi if this is false then we sweap 
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            ans.push_back({3, i + 1});
        }
    }
    cout << ans.size() << endl;
    for (pair<int,int>&val : ans){
        cout << val.first << " " << val.second << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;
    cin >> tt;
    while(tt--)
        solve();
}