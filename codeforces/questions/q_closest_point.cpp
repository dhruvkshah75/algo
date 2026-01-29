#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);       // will be sorted
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n-1; i++){
        if(a[i] == (a[i+1]-1)){
            no;
            return;
        }
    }
    if(n == 2){
        yes;
        return;
    }
    no;

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