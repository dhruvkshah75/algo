#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    set<long long> prefix_set;
    prefix_set.insert(0); // insert initial prefix sum (p0 = 0)

    long long prefix_sum = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        prefix_sum += arr[i];

        // if prefix sum already exists, zero-sum segment found
        if (prefix_set.count(prefix_sum)) {
            ans++;  // we need to break here (simulate removal)
            prefix_set.clear();  // clear all old prefix sums
            prefix_set.insert(0); // restart with 0
            prefix_sum = arr[i];  // start new prefix from current element
        }

        prefix_set.insert(prefix_sum); // track current prefix
    }

    cout << ans << endl;
    return 0;
}
