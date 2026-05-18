#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int mod = 1e9+7;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/problemset/problem/1294/C  

void solve(int n) {
    // a * b * c = n
    int a = -1, b = -1, c = -1;

    // get the smallest factor of n 
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            a = i;
            break;
        }
    }
    // O(N ^ 0.5)

    // no factor found
    if(a == -1) {
        no; return;
    }

    int x = n / a;

    // find b * c = x
    for(int i = a + 1; i * i <= x; i++) {
        if(x % i == 0) {
            // a, b, c should be distinct 
            if(x / i != a && i != a && i * i != x) {
                b = i;
                c = x / i;
                break;
            }
        }
    }
    // O(x ^ 0.5)

    if(b != -1 && c != -1) {
        yes;
        cout << a << " " << b << " " << c << endl;
        return;
    }
    else {
        no; return;
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        solve(n);
    }
}