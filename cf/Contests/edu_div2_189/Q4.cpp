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

const int mod2 = 998244353;

// question link: https://codeforces.com/contest/2225/problem/D

void solve(ll n, ll x) {
    /* xor can be considered as sum of bits modulo 2 
       if the k-th bit is 1 in an even number of elements, 
       the resulting k-th bit of the XOR sum will be 0.
    */

    // to include x in the sequence we must know what bit is set or not at the kth position 

    vector<int> bits()


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
        ll n, x;
        cin >> n >> x;

        solve(n, x);
    }
}