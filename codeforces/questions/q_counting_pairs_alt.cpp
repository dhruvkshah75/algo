#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    
    vector<ll> a(n);
    for (auto &val : a) cin >> val;
    
    sort(a.begin(), a.end());
    ll total = accumulate(a.begin(), a.end(), 0LL);
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll remain_sum_min = total - a[i] - y;
        ll remain_sum_max = total - a[i] - x;

        // Find j such that a[i] + a[j] in [total - y, total - x]
        // => a[j] in [remain_sum_min, remain_sum_max]
        int l = lower_bound(a.begin() + i + 1, a.end(), remain_sum_min) - a.begin();
        int r = upper_bound(a.begin() + i + 1, a.end(), remain_sum_max) - a.begin();
        ans += (r - l);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
