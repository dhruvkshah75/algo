#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> ans(n);  // use 0-based indexing

        if (n % 2 == 0) {
            int count = 0;
            int high = n;
            int low = 1;

            // Fill from index 2 (i=2 means position 3 in 1-based)
            for (int i = 2; i < n; i += 2) {
                ans[i] = high--;
                count++;
            }

            ans[0] = low++;
            count++;

            for (int i = 1;; i += 2) {
                if (low >= high && count == n - 1) {
                    ans[i] = low;
                    break;
                } else if (low >= high && count == n) break;

                ans[n - i] = low++;
                count++;

                ans[i] = low++;
                count++;
            }

            for (int j = 0; j < n; j++) {
                cout << ans[j] << " ";
            }
            cout << endl;
        } else {
            int high = n;
            int low = 1;

            // Fill even indices (starting from 1 in 0-based)
            for (int i = 1; i < n; i += 2) {
                ans[i] = high--;
            }

            for (int i = 0;; i += 2) {
                ans[i] = low++;
                if (low > high) break;

                ans[n - i - 1] = low++;
                if (low > high) break;
            }

            for (int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}
