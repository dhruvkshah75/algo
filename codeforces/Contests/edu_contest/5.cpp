#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int gmax = a[n - 1];
        int smax = a[n - 2];
        int ans = 0;

        for (int k = 2; k < n; k++) {
            int t1 = 2 * a[k];
            int t2 = (k == n - 1) ? smax : gmax;
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

        cout << ans << endl;
    }

    return 0;
}