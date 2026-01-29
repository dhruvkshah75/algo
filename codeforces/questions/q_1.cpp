#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, P, l, t;
    cin >> n >> P >> l >> t;

    ll tasks = (n + 6) / 7;  // Total number of tasks

    ll low = 1, high = n, ans = n;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_points = mid * l + min(2 * mid, tasks)*t;

        if (total_points >= P) {
            ans = mid;
            high = mid - 1;  // Try to find smaller k
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
