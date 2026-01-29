#include<bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    int cs_l = min(r, R) - max(l, L) + 1;   // length of the common segemnt
    int ans = cs_l-1;      // no of doors in the common segment 
    if (cs_l <= 0){
      ans = 1;
    } 
    else{
      ans += (l != L);            
      ans += (r != R);
    }
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}
