#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool met_positive = false;
        int cnt_zero = 0;
        
        for (auto i = n - 1; i >= 0; --i) {
            if (s[i] != '0') {
                met_positive = true;
            } else if (met_positive) {
                cnt_zero++;
            }
        }
        
        cout << n - (cnt_zero + 1) << '\n';
    }
    return 0;
}