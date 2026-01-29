#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> freq(10);   // hash map
    for (char ch : s) {
        freq[ch - '0']++;
    }

    string ans = "";
    // For each position from left to right (0 to 9)
    for (int i = 1; i <= 10; i++) {
        // We need digit >= (10 - i)
        int min_digit = 10 - i;
        for (int d = min_digit; d <= 9; d++) {
            if (freq[d] > 0) {
                ans += (char)(d + '0');
                freq[d]--;
                break;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
