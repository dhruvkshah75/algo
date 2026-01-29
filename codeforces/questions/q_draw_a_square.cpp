#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        if (l == r && r == u && u == d && l == d)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}