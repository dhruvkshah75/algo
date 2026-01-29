
/*
******************************************************** B. Keyboard *************************************************************
                                                    time limit per test: 1 second
                                                    memory limit per test: 256 megabytes
Vasya learns to type. He has an unusual keyboard at his disposal: it is rectangular and it has n rows of keys containing m keys in each row. 
Besides, the keys are of two types. Some of the keys have lowercase Latin letters on them and some of the keys work like the "Shift" key on standard keyboards, 
that is, they make lowercase letters uppercase.
Vasya can press one or two keys with one hand. 
However, he can only press two keys if the Euclidean distance between the centers of the keys does not exceed x. 
The keys are considered as squares with a side equal to 1. There are no empty spaces between neighbouring keys.

Vasya is a very lazy boy, that's why he tries to type with one hand as he eats chips with his other one. 
However, it is possible that some symbol can't be typed with one hand only, 
because the distance between it and the closest "Shift" key is strictly larger than x. 
In this case he will have to use his other hand. Having typed the symbol, Vasya returns other hand back to the chips.

You are given Vasya's keyboard and the text. Count the minimum number of times Vasya will have to use the other hand.

Input
The first line contains three integers n, m, x (1 ≤ n, m ≤ 30, 1 ≤ x ≤ 50).
Next n lines contain descriptions of all the keyboard keys. Each line contains the descriptions of exactly m keys, without spaces. 
The letter keys are marked with the corresponding lowercase letters. The "Shift" keys are marked with the "S" symbol.
Then follow the length of the text q (1 ≤ q ≤ 5·1e5). The last line contains the text T, which consists of q symbols, 
which are uppercase and lowercase Latin letters.

Output
If Vasya can type the text, then print the minimum number of times he will have to use his other hand. 
Otherwise, print "-1" (without the quotes).
******************************************************************************************************************************************
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 140;
int hsh[N];

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<string> keys(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    vector<pair<int, int>> shift_loc;     // store the shidt key location in terms i and j
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (keys[i][j] == 'S') {
                shift_loc.emplace_back(i, j);
            } else {
                hsh[(int)keys[i][j]] = 1;
            }
        }
    }

    map<char, bool> reachable;    // map to check if the character is reachable 
    if (!shift_loc.empty()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = keys[i][j];
                if (c == 'S') continue;
                for (auto& sh : shift_loc) {
                    double dist = sqrt(pow(sh.first - i, 2) + pow(sh.second - j, 2));
                    if (dist <= x) {
                        reachable[c] = true;
                        break;
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    string str;
    cin >> str;

    int ans = 0;
    for (char c : str) {
        if (islower(c)) {
            if (!hsh[(int)c]) {
                cout << -1 << endl;
                return 0;
            }
        } else if (isupper(c)) {
            char lower = tolower(c);
            if (!hsh[(int)lower]) {
                cout << -1 << endl;
                return 0;
            }
            if (shift_loc.empty()) {
                cout << -1 << endl;
                return 0;
            }
            if (!reachable[lower]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
