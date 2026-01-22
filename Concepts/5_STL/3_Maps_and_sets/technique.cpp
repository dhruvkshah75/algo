#include<bits/stdc++.h>
using namespace std;

// restore the location of vector that was sorted 

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>>a(n);             // storing a as a pair a[i].first are inputs and a[i].second = i is idetentifier
        vector<int>b(n);
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        for(auto &i : b) cin >> i;
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++){
            ans[a[i].second] = b[i];
        }
        for(auto &i : ans) cout << i << ' ';
        cout << endl;
    };
}