#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<string> melodies;             // it is a set will only store the unique values
        for(int i = 0; i < n - 1; ++i) {
            string sub = s.substr(i, 2);    // correct way to concatenate the string
            melodies.insert(sub);
        }
        cout << melodies.size() << endl;
    }
    return 0;
}
