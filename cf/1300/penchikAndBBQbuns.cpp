#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;

const int mod = 1e9+7;
const ll inf = 1e18;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// question link: https://codeforces.com/problemset/problem/2031/C

void solve(int n) {
    // if n is even simply place two buns at a distance of 1 
    if(n & 1) {
        // if n < 27 we cannot place the fillings in any way 
        if(n < 27) {
            cout << -1 << endl;
            return;
        }

        // magic 27 sequence 
        vector<int> res(n+1, 0);

        // filling 1 at 1, 10, 26 and filling 2 at 23, 27
        // after this magic all possible pairs can be placed
        res[1] = res[10] = res[26] = 1;
        res[23] = res[27] = 2;

        int filling = 3;

        for(int i = 1; i <= n; i++) {
            if(res[i] == 0) {
                res[i] = res[i+1] = filling;
                filling++;
            }
        }

        // print result 
        for(int i = 1; i <= n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    else {
        // n is even 
        for(int i = 1; i <= n; i += 2) {
            cout << i << " " << i << " ";
        }
        cout << endl;
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