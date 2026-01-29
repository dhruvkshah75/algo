#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int ct = 0;
    for(int i=1; i<=n; i++){
        int val = a[i];
        if(i!=n){
            if(a[i+1] == (val+1)){
                ct++;
            }
        }
    }
    if(ct >= 1){
        int ct1 = 0;
        for(int i=1; i<=n; i++){
            int val = a[i];
            if(i!=n){
                if(a[i+1] == (val+1)){
                    ct1++;
                    if(ct1 == ct){
                        cout << i << " " << i+1 << endl;
                        return;
                    }
                }
            }
       }
    }
    else{
        cout << 1 << " " << 1 << endl;
    }
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