#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> freq;
    for(int i=0; i<n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    for(auto &val: freq){
        if(val.first < 0){
            cout << val.first << endl;
            return;
        }
    }

    int max_element = INT_MIN;
    for(auto &val: freq){
        if(val.first > max_element){
            max_element = val.first;
        }
    }
    cout << max_element << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}