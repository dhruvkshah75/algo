#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, L;
        cin >> n >> m >> L;

        vector<pair<int, int>> hurdles(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            hurdles[i] = {a, b};
        }

        sort(hurdles.begin(), hurdles.end());

        map<int, multiset<int>> power;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            power[a].insert(b);
        }

        multiset<int> available_powers;
        int count = 0;
        bool fail = false;

        for (auto &h : hurdles) {
            int h_start = h.first;
            int h_end = h.second;
            int h_size = h_end - h_start + 1;

            // Add powerups that are at or before the hurdle start
            auto it = power.begin();
            while (it != power.end() && it->first < h_start) {
                for (int val : it->second)
                    available_powers.insert(val);
                it = power.erase(it); // Remove added entries
            }

            int total_power = 0;
            while (total_power < h_size && !available_powers.empty()) {
                // Take the largest available powerup
                auto it = prev(available_powers.end());
                total_power += *it;
                available_powers.erase(it);
                count++;
            }

            if (total_power < h_size) {
                cout << -1 << endl;
                fail = true;
                break;
            }
        }

        if (!fail)
            cout << count << endl;
    }

    return 0;
}
