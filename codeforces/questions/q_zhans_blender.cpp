#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int m = min(x, y);
    if(n%m == 0){
        cout << n/m << endl;
        return;
    }
    else{
        cout << (int)ceil((double)n/m) << endl;
        return;
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