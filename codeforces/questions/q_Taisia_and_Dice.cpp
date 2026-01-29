#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r, s;
    cin >> n >> r >> s;

    int mx = s - r; 
    vector<int> res;
    int sum = r; 
    for (int i = 0; i < n - 1; ++i) {
        int val = min(mx, sum - (n - 2 - i)); 
        res.push_back(val);
        sum -= val;
    }
    res.push_back(mx);

    for (int val : res) cout << val << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
