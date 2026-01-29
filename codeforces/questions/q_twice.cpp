

#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        map<int, int> freq;           // store it in a map with its freq
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int score = 0;
        for (auto [val, f] : freq) {
            score += f / 2;  
        }

        cout << score << '\n';
    }
    return 0;
}
