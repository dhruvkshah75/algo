#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int max1 = a[n - 1];
    int max2 = a[n - 2];
    int ans = 0;

    for (int k = 2; k < n; k++) {
        int t1 = 2 * a[k];
        int t2 = (k == n - 1) ? max1 : max2; 
        int T = max(t1, t2) - a[k];

        int l = 0, r = k - 1;
        while (l < r) {
            if (a[l] + a[r] > T) {
                ans += (r - l);
                r--;
            } else {
                l++;
            }
        }
    }

    cout << ans << '\n';
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
