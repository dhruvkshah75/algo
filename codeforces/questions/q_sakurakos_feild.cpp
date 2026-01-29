#include <bits/stdc++.h>
using namespace std;

int calc_disturbance(const vector<int>& arr) {
    int cnt = 0;
    for(int i = 0; i < (int)arr.size() - 1; i++) {
        if(arr[i] == arr[i+1]) cnt++;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    // Initial disturbance
    int best = calc_disturbance(a);

    // Try all possible swap combinations with a[i] <-> a[n-1-i]
    for(int i = 0; i < n/2; i++) {
        swap(a[i], a[n-1-i]);
        best = min(best, calc_disturbance(a));
        swap(a[i], a[n-1-i]); // revert
    }

    cout << best << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}
