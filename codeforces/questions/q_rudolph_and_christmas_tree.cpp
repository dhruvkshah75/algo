#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> y(n);
    for (int i = 0; i < n; i++) cin >> y[i];

    double total_area = 0.0;

    for (int i = 0; i < n - 1; i++) {
        int height = y[i + 1] - y[i];
        if (height >= h) {
            // No overlap
            total_area += (1.0 * d * h) / 2.0;
        } else {
            // Overlap
            double overlap_height = h - height;
            double base = (1.0 * d * overlap_height) / h;
            double overlap_area = (1.0 * base * overlap_height) / 2.0;
            total_area += (1.0 * d * h) / 2.0 - overlap_area;
        }
    }

    // Add the last triangle
    total_area += (1.0 * d * h) / 2.0;

    cout << fixed << setprecision(12) << total_area << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
}
