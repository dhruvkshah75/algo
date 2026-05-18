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

// question link: https://codeforces.com/problemset/problem/2219/A

void solve(int p, int q) {
    
    /* Horizontal edges are m * (n + 1) and n * (m + 1) 
       Vertical edges are n * (m + 1) 
       Compare the perimeter => p + 2 * q = 2 * n * m + n + m
       Rearranging them gives (2n + 1)(2m + 1) = 2p + 4q + 1   
    */
 
    ll S = 2LL * p + 4LL * q + 1;

    for(ll i = 1; i * i <= S; i++) {
        if(S % i == 0) {
            ll a = i, b = S / i;

            // a = 2 * n + 1 anf b = 2 * m + 1
            if(a & 1 && b & 1) {
                // first orientation
                ll n = (a - 1) / 2;
                ll m = (b - 1) / 2;

                if(n > 0 && m > 0) {
                    cout << n << " " << m << "\n";
                    return;
                }

                // second orientation
                n = (b - 1) / 2;
                m = (a - 1) / 2;

                if(n > 0 && m > 0) {
                    cout << n << " " << m << "\n";
                    return;
                }
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while(t--) {
        int p, q;
        cin >> p >> q;

        solve(p, q);
    }
}